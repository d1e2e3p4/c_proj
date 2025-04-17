#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *openfile(void *arg)
{
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif
	
	int index=0,ret=0;
	char ch[300];
	char *fd = (char*)malloc(sizeof(char));
	if(!fd)
	{
		perror("fd malloc error");
		(*fptr[0])((void*)"FAILURE");
	}	
	//to input the filename
	//mode=arg
	char *mode = (char*)arg;
	char *ipfile = (char*)malloc(20*sizeof(char));
	if(!ipfile)
	{
		perror("ipfile malloc error");
		(*fptr[0])((void*)"FAILURE");
	}	
	memset(ipfile,'\0',20);
	do
	{
		*(ipfile+index)=getchar();
		if(*(ipfile+index) == '\n') break;
		index++;
	}while(1);
	*(ipfile+index) = '\0';
	
#ifdef DEBUG
	printf("Entered file name is  %s\n",ipfile);
#endif

	if(strncmp(mode,"reading",7) == 0)
	{

	read:
		*fd = open(ipfile,O_RDONLY); 
				
		if(*fd<0)
		{
			printf("file does not exit\n");
			
			*fd = open(ipfile,O_WRONLY|O_CREAT);
			if(*fd < 0)
			{
				perror("write error");
				(*fptr[0])((void*)"FAILURE");
			}
			printf("Enter the characters to write in file\n");
			int idx=0;
			while(1)
			{
				*(ch+idx)=getchar();
				if(*(ch+idx) == '\n')
					break;

				ret = write(*fd,(ch+idx),1);
				if(ret<0)
                        	{
                                	perror("write error");
                                	(*fptr[0])((void*)"FAILURE");
                        	}
				idx++;
			}
				
			close(*fd);
			
			goto read;
			
		}
	}	
	if(strncmp(mode,"writing",7)==0)
	{
		*fd = open(ipfile,O_WRONLY|O_CREAT);
                if(ret < 0)
                {
                	perror("write error");
                        (*fptr[0])((void*)"FAILURE");
                }     

	}	
	#ifdef DEBUG
                printf("END:%s\n",__func__);
        #endif
	return (void*)fd;	
}	

