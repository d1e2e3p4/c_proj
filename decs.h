#define NOF 11

int init();

extern void *(*fptr[NOF])(void*);
extern void *exitprogram(void*);
extern void *mainmenu(void*);
extern void *openfile(void *arg);
extern void *isunique(void *arg);
extern void *createma(void *arg);
extern void *maxbits(void *arg);
extern void *getpos(void *arg);
extern void *compression(void*);
extern void *decompression(void*);
extern void *compression2(void *arg);
extern void *compression3(void *arg);
extern void *compression4(void *arg);
extern void *decompression3(void *arg);
extern void *decompression4(void *arg);
extern void *compression5(void *arg);
extern void *compression6(void *arg);
extern void *compression7(void *arg);
extern void *compression8(void *arg);

extern char *menu[];
extern int flag;
