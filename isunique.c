#include"headers.h"
#include"datastructs.h"
#include"decs.h"

void *isunique(void *arg)//it will receive file fd as an argument
{
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif

	Duniq *dq = (Duniq*)arg;
	int i;
	flag = 1;
	//linear search
	if(dq->size == 0)//array empty
		return (void*)&flag;

	for(i=0;i < dq->size;i++)
	{
		if(*(dq->ma + i) == dq->ch)
		{
			flag = 0;
			return (void*)&flag;
		}	
	}	

	//whole array traversed and character not found
	
#ifdef DEBUG
        printf("END:%s\n",__func__);
#endif
	return (void*)&flag;
}
