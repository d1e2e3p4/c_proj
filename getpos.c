#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *getpos(void *arg)
{
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif

	//duniq structure is passed as an argument
	Duniq *du=(Duniq*)arg;
	int i=0;

	for(i=0;i<du->size;i++)
	{
		if(*(du->ma+i) == du->ch)
		{
			flag=i;
			break;
		}	
	}	

#ifdef DEBUG
        printf("END:%s\n",__func__);
#endif
	return (void*)&flag;
}	

