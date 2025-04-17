#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *exitprogram(void *arg)
{
        #ifdef DEBUG
                printf("BEGIN:%s\n",__func__);
        #endif
	char *str = (char*)arg;
	if(strncmp(str,"SUCCESS",7)==0)
	{
		printf("Exited Successfully......................\n");
		exit(EXIT_SUCCESS);
	}	
	else
	{
		printf("Failed...........");
		exit(EXIT_FAILURE);
	}	
	
	#ifdef DEBUG
                printf("BEGIN:%s\n",__func__);
        #endif
}
