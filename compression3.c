#include"decs.h"
#include"headers.h"
#include"datastructs.h"

void *compression3(void *arg)
{
#ifdef DEBUG
        printf("BEGIN:%s\n",__func__);
#endif

        //it will receive the fd of file in read mode and read the position from ma 
        //and write it another file
        //the ma and file read fd is received in arg

        int fs=0,writefd=0,ret=0,pos=0;
        char ch;
        unsigned char byt,idx=0,cc=0;
        Comp *cp = (Comp*)arg;//received fd and ma
        Duniq *du = (Duniq*)malloc(sizeof(Duniq));//this structure is used to send ch and ma together in getpos func
        if(!du)
        {
                perror("malloc error");
                (*fptr[0])((void*)"FAILURE");

        }
        fs=lseek(*cp->fd,0,SEEK_END);
        lseek(*cp->fd,0,SEEK_SET);
        du->ch='\0';
        du->ma = cp->ma;
        du->size = strlen(cp->ma);
        //open the compressed file in write mod to write the master array positions
        printf("Enter file name to store compressed data\n");
        writefd=*(int*)(*fptr[2])((void*)"writing");
        if(writefd<0)
        {
                perror("write error");
                (*fptr[0])((void*)"FAILURE");
        }
	unsigned char byt1;
        while(fs>0)
        {
                byt ^= byt;
		//1st read
		ret = read(*(cp->fd),&ch,1);
                if(ret<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                fs--;
                du->ch = ch;
                pos = *(int*)(*fptr[6])((void*)du);
#ifdef DEBUG
		printf("the character read:%c and its position returned:%d\n",du->ch,pos);//m
#endif
	    	if(pos<0)
                {
                        perror(" pos error");
                        (*fptr[0])((void*)"FAILURE");

                }
		idx = (char)pos;
		idx = idx<<5;
		byt = byt|idx;
		if(fs == 0)
		{
			byt = byt | 0x1F;
			goto write;
		}	
		//2nd read
		ret = read(*(cp->fd),&ch,1);
                if(ret<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                fs--;
                du->ch = ch;
                pos = *(int*)(*fptr[6])((void*)du);
#ifdef DEBUG
                printf("the character read:%c and its position returned:%d\n",du->ch,pos);//m
#endif
                if(pos<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");

                }
                idx = (char)pos;
		idx = idx << 5;
		idx = idx >> 3;
		byt = byt|idx;
		if(fs == 0)
                {
                        byt = byt | 0x03;
                        goto write;
                }
		//3rd read
		ret = read(*(cp->fd),&ch,1);
                if(ret<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                fs--;
                du->ch = ch;
                pos = *(int*)(*fptr[6])((void*)du);
#ifdef DEBUG
                printf("the character read:%c and its position returned:%d\n",du->ch,pos);//m
#endif
               if(pos<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");

                }
                idx = (char)pos;
		cc = idx;
		idx = idx << 5;
		idx = idx >> 6;
		byt = byt|idx;
		//all bits of byts are filled ,write it in compressed file
		//write all bits
		ret=write(writefd,&byt,1);
                if(!ret)
                {
                        perror(" write error");
                        (*fptr[0])((void*)"FAILURE");
                }

		//start filling byt
		byt ^= byt;
		idx = cc;
		idx = idx<<7;
		byt = byt|idx;
		if(fs == 0)
                {
                        byt = byt | 0x70;
                        goto write;
                }
		//4th read
		ret = read(*(cp->fd),&ch,1);
                if(ret<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                fs--;
                du->ch = ch;
                pos = *(int*)(*fptr[6])((void*)du);
#ifdef DEBUG
                printf("the character read:%c and its position returned:%d\n",du->ch,pos);//m
#endif
                if(pos<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");

                }
                idx = (char)pos;
		idx = idx<<5;
		idx = idx>>1;
		byt = byt|idx;
		if(fs == 0)
                {
                        byt = byt | 0x0E;
                        goto write;
                }
		//5th read
		ret = read(*(cp->fd),&ch,1);
                if(ret<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                fs--;
                du->ch = ch;
                pos = *(int*)(*fptr[6])((void*)du);
#ifdef DEBUG
                printf("the character read:%c and its position returned:%d\n",du->ch,pos);//m
#endif
		if(pos<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");

                }
                idx = (char)pos;
		idx = idx<<5;
		idx = idx>>4;
		byt = byt | idx;//-------0
		if(fs == 0)
                {
                        byt = byt | 0x01;
                        goto write;
                }
		//6th read
		ret = read(*(cp->fd),&ch,1);
                if(ret<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                fs--;
                du->ch = ch;
                pos = *(int*)(*fptr[6])((void*)du);
#ifdef DEBUG
                printf("the character read:%c and its position returned:%d\n",du->ch,pos);//m
#endif
		if(pos<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");

                }
                idx = (char)pos;
		cc = idx;
		idx = idx << 5;
		idx = idx >> 7;
		byt = byt | idx;
		//all bits are filed, write in compressed file
		//write all bits
		ret=write(writefd,&byt,1);
                if(!ret)
                {
                        perror(" write error");
                        (*fptr[0])((void*)"FAILURE");
                }

		//next cycle for byt
		byt ^= byt;
		idx = cc;
		idx = idx<<6;
		byt = byt | idx;
		if(fs == 0)
                {
                        byt = byt | 0x30;
                        goto write;
                }
		//7th read
		ret = read(*(cp->fd),&ch,1);
                if(ret<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                fs--;
                du->ch = ch;
                pos = *(int*)(*fptr[6])((void*)du);
#ifdef DEBUG
                printf("the character read:%c and its position returned:%d\n",du->ch,pos);//m
#endif
                if(pos<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");

                }
                idx = (char)pos;
		idx = idx << 5;
		idx = idx >> 2;
		byt = byt | idx;
		//error situation
		if(fs == 0)
                {
                      byt = byt | 0x07;
		      goto write;
                }

		//8th read
		ret = read(*(cp->fd),&ch,1);
                if(ret<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");
                }
                fs--;
                du->ch = ch;
                pos = *(int*)(*fptr[6])((void*)du);
#ifdef DEBUG
                printf("the character read:%c and its position returned:%d\n",du->ch,pos);//m
#endif
                if(pos<0)
                {
                        perror(" read error");
                        (*fptr[0])((void*)"FAILURE");

                }
                idx = (char)pos;
		idx = idx << 5;
		idx = idx >> 5;
		byt = byt | idx;
write:
		 ret=write(writefd,&byt,1);
                if(!ret)
                {
                        perror(" write error");
                        (*fptr[0])((void*)"FAILURE");
                }
	}
	//store ma in some file also
        writefd=0;
        printf("Enter file name to store encrypted ky(master array)\n");
        writefd =*(int*)(*fptr[2])((void*)"writing");
        if(!ret)
        {

                perror("read error");
                (*fptr[0])((void*)"FAILURE");
        }
        int len=strlen(cp->ma);
        ret=write(writefd,cp->ma,len);
        if(!ret)
        {
                perror("read error");
                (*fptr[0])((void*)"FAILURE");
        }
        close(writefd);
        close(*cp->fd);

#ifdef DEBUG
        printf("END:%s\n",__func__);
#endif
}










