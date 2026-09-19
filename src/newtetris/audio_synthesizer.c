#include "common.h"
#include "synthInternals.h"

static s32 __nextSampleTime(ALSynth *, ALPlayer **);

void alSynNew(ALSynth *drvr, ALSynConfig *c) {
  s32 i;
  PVoice *pv;
  PVoice *pvoices;
  ALHeap *hp = c->heap;
  ALSave *save;
  ALFilter *sources;
  ALParam *params;
  ALParam *paramPtr;

  drvr->head = NULL;
  drvr->numPVoices = c->maxPVoices;
  drvr->curSamples = 0;
  drvr->paramSamples = 0;
  drvr->outputRate = c->outputRate;
  drvr->maxOutSamples = AL_MAX_RSP_SAMPLES;
  drvr->dma = c->dmaproc;

  save = alHeapAlloc(hp, 1, sizeof(ALSave));
  alSaveNew(save);
  drvr->outputFilter = (ALFilter *)save;

  //drvr->auxBus = alHeapAlloc(hp, 1, sizeof(ALAuxBus));
  drvr->auxBus = alHeapAlloc(hp, 1, 0x48);  // sizeof(ALAuxBus) = 0x4C
  drvr->maxAuxBusses = 1;
  sources = alHeapAlloc(hp, c->maxPVoices, sizeof(ALFilter *));
  alAuxBusNew(drvr->auxBus, sources, c->maxPVoices);

  drvr->mainBus = alHeapAlloc(hp, 1, sizeof(ALMainBus));
  sources = alHeapAlloc(hp, c->maxPVoices, sizeof(ALFilter *));
  alMainBusNew(drvr->mainBus, sources, c->maxPVoices);

  if (c->fxType != AL_FX_NONE) {
    alSynAllocFX(drvr, 0, c, hp);
  } else {
    alMainBusParam(drvr->mainBus, AL_FILTER_ADD_SOURCE, &drvr->auxBus[0]);
  }

  drvr->pFreeList.next = NULL;
  drvr->pFreeList.prev = NULL;
  drvr->pLameList.next = NULL;
  drvr->pLameList.prev = NULL;
  drvr->pAllocList.next = NULL;
  drvr->pAllocList.prev = NULL;

  pvoices = alHeapAlloc(hp, c->maxPVoices, sizeof(PVoice));
  for (i = 0; i < c->maxPVoices; i++) {
    pv = &pvoices[i];
    alLink((ALLink *)pv, &drvr->pFreeList);
    pv->vvoice = NULL;

    alLoadNew(&pv->decoder, drvr->dma, hp);
    h2oLoadParam(&pv->decoder, AL_FILTER_SET_SOURCE, NULL);

    alResampleNew(&pv->resampler, hp);
    alResampleParam(&pv->resampler, AL_FILTER_SET_SOURCE, &pv->decoder);

    alEnvmixerNew(&pv->envmixer, hp);
    alEnvmixerParam(&pv->envmixer, AL_FILTER_SET_SOURCE, &pv->resampler);

    alAuxBusParam(drvr->auxBus, AL_FILTER_ADD_SOURCE, &pv->envmixer);

    pv->channelKnob = (ALFilter *)&pv->envmixer;
  }

  alSaveParam(save, AL_FILTER_SET_SOURCE, drvr->mainBus);

  params = alHeapAlloc(hp, c->maxUpdates, sizeof(ALParam));
  drvr->paramList = NULL;
  for (i = 0; i < c->maxUpdates; i++) {
    paramPtr = &params[i];
    paramPtr->next = drvr->paramList;
    drvr->paramList = paramPtr;
  }

  drvr->heap = hp;
}

Acmd *alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen) {
  ALPlayer *client;
  ALFilter *output;
  ALSynth *drvr = &alGlobals->drvr;
  s16 tmp = 0;
  Acmd *cmdlEnd = cmdList;
  Acmd *cmdPtr;
  s32 nOut;
  s16 *lOutBuf = outBuf;

  if (drvr->head == NULL) {
    *cmdLen = 0;
    return cmdList;
  }

  for (drvr->paramSamples = __nextSampleTime(drvr, &client); (drvr->paramSamples - drvr->curSamples) < outLen; drvr->paramSamples = __nextSampleTime(drvr, &client)) {
    client->samplesLeft = _timeToSamples(drvr, client->handler(client)) + drvr->paramSamples;
  }

  while (outLen > 0) {
    nOut = (drvr->maxOutSamples < outLen) ? drvr->maxOutSamples : outLen;

    cmdPtr = cmdlEnd;
    aSegment(cmdPtr++, 0, 0);
    output = drvr->outputFilter;
    output->setParam(output, AL_FILTER_SET_DRAM, lOutBuf);
    cmdlEnd = output->handler(output, &tmp, nOut, drvr->curSamples, cmdPtr);

    outLen -= nOut;
    lOutBuf += nOut << 1;
    drvr->curSamples += nOut;
  }
  *cmdLen = cmdlEnd - cmdList;

  _collectPVoices(drvr);

  return cmdlEnd;
}

ALParam *__allocParam(void) {
  ALParam *update = NULL;
  ALSynth *drvr = &alGlobals->drvr;

  if (drvr->paramList != NULL) {
    update = drvr->paramList;
    drvr->paramList = drvr->paramList->next;
    update->next = NULL;
  }

  return update;
}

void __freeParam(ALParam *param) {
  ALSynth *drvr = &alGlobals->drvr;

  param->next = drvr->paramList;
  drvr->paramList = param;
}

void _collectPVoices(ALSynth *drvr) {
  ALLink *dl;

  while ((dl = drvr->pLameList.next) != NULL) {
    alUnlink(dl);
    alLink(dl, &drvr->pFreeList);
  }
}

void _freePVoice(ALSynth *drvr, PVoice *pvoice) {
  alUnlink((ALLink *)pvoice);
  alLink((ALLink *)pvoice, &drvr->pLameList);
}

s32 _timeToSamples(ALSynth *ALSynth, s32 micros) {
  s32 ret;
  f32 tmp;

  tmp = ((f32)micros) * ALSynth->outputRate / 1000000.0;
  ret = tmp;
  ret &= ~0xF;

  return ret;
}

ALMicroTime _samplesToTime(ALSynth *synth, s32 samples) {
  f32 ret;

  ret = ((f32)samples) * 1000000.0 / synth->outputRate;

  return ret;
}

static s32 __nextSampleTime(ALSynth *drvr, ALPlayer **client) {
  ALMicroTime delta = 0x7FFFFFFF;
  ALPlayer *cl;

  *client = NULL;

  for (cl = drvr->head; cl != NULL; cl = cl->next) {
    if ((cl->samplesLeft - drvr->curSamples) < delta) {
      *client = cl;
      delta = cl->samplesLeft - drvr->curSamples;
    }
  }

  return (*client)->samplesLeft;
}
