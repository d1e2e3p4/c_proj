#include"decs.h"
#include"headers.h"
#include"datastructs.h"

int main()
{
	#ifdef DEBUG
		printf("BEGIN:%s\n",__func__);
	#endif

	init();
	
	while(1)
	{
		(*fptr[1])((void*)NULL);
	}	

	#ifdef DEBUG
                printf("END:%s\n",__func__);
        #endif

}	
