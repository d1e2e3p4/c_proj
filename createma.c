#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *createma(void *arg)//it will receive file fd as an argument
{
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif
	int fd,fz,ret;
	Duniq *unq=(Duniq*)malloc(sizeof(Duniq));
	if(!unq)
	{
		perror("malloc error");
		(*fptr[0])((void*)"FAILURE");
	}	
	fd = *(int*)arg;
	fz = lseek(fd,0,SEEK_END);
        lseek(fd,0,SEEK_SET);
	unq->ma = (char*)malloc(fz*sizeof(char));
	if(!unq->ma)
        {
                perror("unique malloc error");
                (*fptr[0])((void*)"FAILURE");
        }
	memset(unq->ma,'\0',fz);
	unq->size = 0;
        unq->ch = '\0';
	while(fz)
	{
		ret = read(fd,&unq->ch,1);
		if(ret<0)
        	{
                	perror("read error");
                	(*fptr[0])((void*)"FAILURE");
        	}
		ret = *(int*)(*fptr[3])((void*)unq);
		
		if(ret == 1)
		{
			//charater not preset in ma
			
			*(unq->ma + unq->size) = unq->ch;
			unq->size++;

		}	
		fz--;
		
	}	

#ifdef DEBUG
        printf("END:%s\n",__func__);
#endif
	return (void*)unq->ma;
}	
	
