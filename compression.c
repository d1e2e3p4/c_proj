#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *compression(void *arg)
{
#ifdef DEBUG
	printf("BEGIN:%s\n",__func__);
#endif
	
	Comp *cp=(Comp*)malloc(sizeof(Comp));
	if(!cp)
	{
                perror("malloc error");
                (*fptr[0])((void*)"FAILURE");
	}	
	cp->ma = NULL;
	cp->fd = (int*)malloc(sizeof(int));
	if(!cp->fd)
	{
		perror("malloc error");
		(*fptr[0])((void*)"FAILURE");
	}
	printf("ENTER uncompressed file name\n");	
	getchar();
	//first open file for read uncompressed file
	cp->fd =(int*)(*fptr[2])((void*)"reading");
	//create master array with unique characters
	cp->ma = (char*)(*fptr[4])((void*)cp->fd);
	
	if(!cp->ma)
	{
		perror("Error in creating ma");
		(*fptr[0])((void*)"FAILURE");
	}	
	//maxbits
	int maxbits = *(int*)(*fptr[5])((void*)cp->ma);

	printf("received maxbits are%d\n",maxbits);
	if((maxbits>=2)&&(maxbits<=8))
		(*fptr[5+maxbits])((void*)cp);

#ifdef DEBUG
        printf("END:%s\n",__func__);
#endif
}		
