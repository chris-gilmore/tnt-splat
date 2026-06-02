#include "common.h"
#include "synthInternals.h"

void alSynSetVol(ALSynth *s, ALVoice *v, s16 vol, s32 delta) {
  ALParam *param;
  ALFilter *filter;

  if (v->pvoice != NULL) {
    param = __allocParam();
    if (param == NULL) {
      return;
    }

    param->delta = s->paramSamples + v->pvoice->offset;
    param->type = AL_FILTER_SET_VOLUME;
    param->data.i = vol;
    param->moredata.i = _timeToSamples(s, delta);
    param->next = NULL;
    filter = v->pvoice->channelKnob;
    filter->setParam(filter, AL_FILTER_ADD_UPDATE, param);
  }
}
