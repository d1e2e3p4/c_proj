#include"decs.h"
#include"headers.h"
#include"datastructs.h"

int flag;
void *(*fptr[NOF])(void*);
void *exitprogram(void*);
void *mainmenu(void*);
void *openfile(void *arg);
void *isunique(void *arg);
void *createma(void *arg);
void *maxbits(void *arg);
void *getpos(void *arg);
void *compression(void*);
void *decompression(void*);
void *compression3(void *arg);
void *compression4(void *arg);
void *compression5(void *arg);
void *decompression3(void *arg);
void *decompression4(void *arg);
void *decompression5(void *arg);

int init()
{
	#ifdef DEBUG
                printf("BEGIN:%s\n",__func__);
        #endif
	flag = 0;
	fptr[0] = exitprogram;
        fptr[1] = mainmenu;
  	fptr[2] = openfile;
	fptr[3] = isunique;
	fptr[4] = createma;
	fptr[5] = maxbits;
	fptr[6] = getpos;
	fptr[7] = compression;
	fptr[8] = decompression;
//	fptr[9] = compression3;
	fptr[9]= compression4;
//	fptr[11]= compression5;
//	fptr[12]= decompression3;
	fptr[10]= decompression4;
//	fptr[14]= decompression5;

	#ifdef DEBUG
                printf("END:%s\n",__func__);
        #endif

}	

