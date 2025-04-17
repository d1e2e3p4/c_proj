#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *decompression4(void *arg)
{
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif
	////retrieve ma from some file
	Dcomp *dc = (Dcomp*)arg;
	int writefd,readfilesize,ret;
	
	unsigned char cc,ch;
	int index=0;
	//open file in write mode to store decompressed data
	printf("enter the file name to store decompressed data\n");
        writefd= *(int*)(*fptr[2])((void*)"writing");
        if(!writefd)
        {
                perror("write error");
                (*fptr[0])((void*)"FAILURE");
        }
	readfilesize = lseek(dc->ifd,0,SEEK_END);
	lseek(dc->ifd,0,SEEK_SET);
	printf("read file size %d\n",readfilesize);
	while(readfilesize>0)
	{
		ch ^= ch;
		cc ^= cc;
		ret = read(dc->ifd,&ch,1);
		if(!ret)
		{
			perror("read error");
	                (*fptr[0])((void*)"FAILURE");
		}
		readfilesize--;
		cc = ch;
		ch=ch>>4;
		index=(int)ch;
		if((index>=0)&&(index<=15))
		{
			char rdch;
			rdch = *(dc->ma+index);
			ret = write(writefd,&rdch,1);
			if(!ret)
			{
				perror("write error");
                        	(*fptr[0])((void*)"FAILURE");
			}
		}
		//1st LSB 4 bits
		
		cc = cc & 0x0F;
		
		index =(int)cc;
		if((index>=0)&&(index<=15))
                {
                        char rdch;
                        rdch = *(dc->ma+index);
			ret = write(writefd,&rdch,1);
                        if(!ret)
                        {
                                perror("write error");
                                (*fptr[0])((void*)"FAILURE");
                        }
                }		
	}	
	close(writefd);
	close(dc->ifd);	
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif
}	
