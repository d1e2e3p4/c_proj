#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *maxbits(void *arg)
{
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif

	char *ma = (char*)arg;
	int len = strlen(ma);
	
	flag =0;

	
	
	if(len<4)
		flag = 2;
	else if(len<8)
                flag = 3;
	else if(len<16)
                flag = 4;
	else if(len<32)
                flag = 5;
	else if(len<64)
                flag = 6;
	else if(len<128)
                flag = 7;
	else if(len<256)
                flag = 8;

#ifdef DEBUG
        printf("END:%s\n",__func__);
#endif
	return (void*)&flag;
}	

