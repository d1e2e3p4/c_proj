#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *decompression3(void *arg)
{
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif
        ////retrieve ma from some file
        Dcomp *dc = (Dcomp*)arg;
        int writefd,readfilesize,ret;

        unsigned char cc,ch,byt;
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
                byt ^= byt;
		ch ^= ch;
                cc ^= cc;
		//read first 8 bits
                ret = read(dc->ifd,&ch,1);
                if(!ret)
                {
                        perror("read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                readfilesize--;
		cc = ch;
		//first 3 bits of byt
		ch = ch>>5;
		index = (int)ch;
		if((index>=0)&&(index<=7))
                {
                        char rdch;
                        rdch = *(dc->ma+index);
#ifdef DEBUG
			printf("the obtained index:%d and corresponding char:%c\n",index,rdch);//m
#endif            
	    		ret = write(writefd,&rdch,1);
                        if(!ret)
                        {
                                perror("write error");
                                (*fptr[0])((void*)"FAILURE");
                        }
                }
		
		//second 3 bits of byt
		ch = cc;
		ch = ch <<3;
		ch = ch >>5;
		index = (int)ch;
		if((index>=0)&&(index<=7))
                {
                        char rdch;
                        rdch = *(dc->ma+index);
#ifdef DEBUG
                        printf("the obtained index:%d and corresponding char:%c\n",index,rdch);//m
#endif
                        ret = write(writefd,&rdch,1);
                        if(!ret)
                        {
                                perror("write error");
                                (*fptr[0])((void*)"FAILURE");
                        }
                }
		//last two bit of byt
		ch = cc;
		ch = ch<<6;
		ch = ch>>5;
		byt = byt | ch;
		//read another character	
		ret = read(dc->ifd,&ch,1);
                if(!ret)
                {
                        perror("read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                readfilesize--;
		cc = ch;
		//first 1 byt
		ch = ch>>7;
		ch = byt | ch;
		index = (int)ch; 
		if((index>=0)&&(index<=7))
                {
                        char rdch;
                        rdch = *(dc->ma+index);
#ifdef DEBUG
                        printf("the obtained index:%d and corresponding char:%c\n",index,rdch);//m
#endif
                        ret = write(writefd,&rdch,1);
                        if(!ret)
                        {
                                perror("write error");
                                (*fptr[0])((void*)"FAILURE");
                        }
                }
		//next 3 bits
		ch = cc;
		ch = ch << 1;
		ch = ch >> 5;
		index = (int)ch;
		if((index>=0)&&(index<=7))
                {
                        char rdch;
                        rdch = *(dc->ma+index);
#ifdef DEBUG
                        printf("the obtained index:%d and corresponding char:%c\n",index,rdch);//m
#endif
                        ret = write(writefd,&rdch,1);
                        if(!ret)
                        {
                                perror("write error");
                                (*fptr[0])((void*)"FAILURE");
                        }
                }
		//next 3 bits
		ch = cc;
		ch = ch << 4;
		ch = ch >> 5;
		index = (int)ch;
		if((index>=0)&&(index<=7))
                {
                        char rdch;
                        rdch = *(dc->ma+index);
#ifdef DEBUG
                        printf("the obtained index:%d and corresponding char:%c\n",index,rdch);//m
#endif
                        ret = write(writefd,&rdch,1);
                        if(!ret)
                        {
                                perror("write error");
                                (*fptr[0])((void*)"FAILURE");
                        }
                }
		ch = cc;
		ch = ch<<7;
		ch = ch >> 5;
		byt ^= byt;
		byt = byt | ch;
		//read another character        
                ret = read(dc->ifd,&ch,1);
                if(!ret)
                {
                        perror("read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                readfilesize--;
		//first two bits
		cc = ch;
		ch = ch >> 6;
		byt = byt | ch;
		index = (int)byt;
		if((index>=0)&&(index<=7))
                {
                        char rdch;
                        rdch = *(dc->ma+index);
#ifdef DEBUG
                        printf("the obtained index:%d and corresponding char:%c\n",index,rdch);//m
#endif
                        ret = write(writefd,&rdch,1);
                        if(!ret)
                        {
                                perror("write error");
                                (*fptr[0])((void*)"FAILURE");
                        }
                }
		// next 3 bits
		ch = 0x00;
		ch = cc;
		ch = ch << 2;
		ch = ch >>5;
		index = (int)ch;
		if((index>=0)&&(index<=7))
                {
                        char rdch;
                        rdch = *(dc->ma+index);
#ifdef DEBUG
                        printf("the obtained index:%d and corresponding char:%c\n",index,rdch);//m
#endif
                        ret = write(writefd,&rdch,1);
                        if(!ret)
                        {
                                perror("write error");
                                (*fptr[0])((void*)"FAILURE");
                        }
                }
		// next 3 bits
		ch = 0x00; 
		ch = cc;
                ch = ch << 5;
                ch = ch >>5;
                index = (int)ch;
                if((index>=0)&&(index<=7))
                {
                        char rdch;
                        rdch = *(dc->ma+index);
#ifdef DEBUG
                        printf("the obtained index:%d and corresponding char:%c\n",index,rdch);//m
#endif
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

