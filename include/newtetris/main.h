#ifndef _MAIN_H_
#define _MAIN_H_

extern u8 D_800CFE34;
extern u64 bootStack[];
extern OSMesgQueue D_8010BB08;
extern OSSched scheduler;
extern SuperThread superThread;

extern void   boot(void *);
extern void   main_8004A34C_threeliner(void);

#endif /* !_MAIN_H_ */
