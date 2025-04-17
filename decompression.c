#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *decompression(void *arg)
{
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif
	int readfd=0,size,ret,writefd;
	
	Dcomp *dc=(Dcomp*)malloc(sizeof(Dcomp));
	if(!dc)
        {
                perror("read error");
                (*fptr[0])((void*)"FAILURE");
        }
	char ch;
	//1st fill the master array from file
	printf("Enter the filename with encrypted data(master array)\n");
	getchar();
	readfd=*(int*)(*fptr[2])((void*)"reading");
	if(readfd<0)
	{
                perror("read error");
                (*fptr[0])((void*)"FAILURE");
	}
	size=lseek(readfd,0,SEEK_END);
	lseek(readfd,0,SEEK_SET);
	dc->ma = (char*)malloc(sizeof(char));
	if(!dc->ma)
	{
		perror("malloc error");
                (*fptr[0])((void*)"FAILURE");
	}	
	memset(dc->ma,'\0',size);
	dc->size = 0;
	while(1)
	{
		ret=read(readfd,&ch,1);
		if(ret<0)
		{
			perror("read error");
	                (*fptr[0])((void*)"FAILURE");
		}	
		if(ret == 0) break;// nothing to read
		*(dc->ma + dc->size) = ch;
		dc->size++;
	}
	
	dc->ifd = 0;
	printf("enter the file name with compressed data\n");
        dc->ifd= *(int*)(*fptr[2])((void*)"reading");
        if(!dc->ifd)
        {
                perror("write error");
                (*fptr[0])((void*)"FAILURE");
        }
	printf("received master array is:%s \n",dc->ma);
	int maxbits=*(int*)(*fptr[5])((void*)dc->ma);
	printf("received maxbits are:%d\n",maxbits);
	if((maxbits>=2)&&(maxbits<=8))
		(*fptr[6+maxbits])((void*)dc);
 
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif
}	
