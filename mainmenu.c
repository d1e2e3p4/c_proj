#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *mainmenu(void *arg)
{
        #ifdef DEBUG
                printf("BEGIN:%s\n",__func__);
        #endif
	
	int i;
	char *str[3]={"EXIT\n",
		      "1.COMPRESSION\n",
		      "2.DECOMPRESSION\n"
		     };
	
	for(i=0;i<3;i++)
	{
		printf("%s",str[i]);
	}	
	printf("Enter your choice\n");
	scanf("%d",&i);

	if(i==0)
	{
		(*fptr[0])((void*)"SUCCESS");
	}	
	else
	{
		arg=(void*)(*fptr[6+i])((void*)arg);
	}	
	
	#ifdef DEBUG
                printf("END:%s\n",__func__);
        #endif
}	
