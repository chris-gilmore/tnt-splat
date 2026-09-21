#ifndef _MINILZO_H_
#define _MINILZO_H_

#define LZO_VERSION          0x1040
#define LZO_VERSION_STRING   "1.04"
#define LZO_VERSION_DATE     "Mar 15 1998"

extern int __lzo_init_done;

extern unsigned int   __lzo_ptr_linear(void *);
extern unsigned int   __lzo_align_gap(void *, unsigned int);
extern int            lzo_assert(int);
extern char          *lzo_copyright(void);
extern unsigned int   lzo_version(void);
extern char          *lzo_version_string(void);
extern char          *lzo_version_date(void);
extern char          *_lzo_version_string(void);
extern char          *_lzo_version_date(void);
extern unsigned int   lzo_adler32(unsigned int, unsigned char *, unsigned int);
extern int            lzo_memcmp(void *, void *, unsigned int);
extern void          *lzo_memcpy(void *, void *, unsigned int);
extern void          *lzo_memmove(void *, void *, unsigned int);
extern void          *lzo_memset(void *, int, unsigned int);
extern int            _lzo_config_check(void);
extern int            __lzo_init2(unsigned int, int, int, int, int, int, int, int, int, int);
extern int            lzo1x_1_compress(unsigned char *, unsigned int, unsigned char *, unsigned int *, void *);
extern int            lzo1x_decompress(unsigned char *, unsigned int, unsigned char *, unsigned int *, void *);
extern int            lzo1x_decompress_safe(unsigned char *, unsigned int, unsigned char *, unsigned int *, void *);

#endif /* !_MINILZO_H_ */
