#ifndef _MINILZO_H_
#define _MINILZO_H_

#define LZO_VERSION          0x1040
#define LZO_VERSION_STRING   "1.04"
#define LZO_VERSION_DATE     "Mar 15 1998"

extern u32          lzo_version(void);
extern const char  *lzo_version_string(void);
extern const char  *lzo_version_date(void);
extern const char  *_lzo_version_string(void);
extern const char  *_lzo_version_date(void);

extern s32          __lzo_init2(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32          lzo1x_1_compress(u8 *, u32, u8 *, u32 *, void *);
extern s32          lzo1x_decompress(u8 *, u32, u8 *, u32 *, void *);

#endif /* !_MINILZO_H_ */
