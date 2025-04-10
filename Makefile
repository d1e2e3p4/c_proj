#! /bin/bash

CC = gcc
CFLAG = -c -g
LFLAG = -o
DBFLAG = -DDEBUG

mdcproj : main.o init.o exitprogram.o mainmenu.o compression.o openfile.o isunique.o createma.o maxbits.o getpos.o compression2.o compression3.o compression4.o compression5.o compression6.o compression7.o compression8.o
	  $(CC) $(LFLAG) mdcproj main.o init.o exitprogram.o mainmenu.o compression.o openfile.o isunique.o createma.o maxbits.o getpos.o compression2.o compression3.o compression4.o compression5.o compression6.o compression7.o compression8.o

main.o : main.c headers.h decs.h
	 $(CC) $(CFLAG) $(DBFLAG) main.c
mainmenu.o : mainmenu.c headers.h decs.h
	     $(CC) $(CFLAG) $(DBFLAG) mainmenu.c
exitprogram.o : exitprogram.c headers.h decs.h
	        $(CC) $(CFLAG) $(DBFLAG) exitprogram.c
openfile.o : openfile.c headers.h decs.h
	     $(CC) $(CFLAG) $(DBFLAG) openfile.c
isunique.o : isunique.c headers.h decs.h
	    $(CC) $(CFLAG) $(DBFLAG) isunique.c
createma.o : createma.c headers.h decs.h
	     $(CC) $(CFLAG) $(DBFLAG) createma.c
maxbits.o : createma.c headers.h decs.h
	    $(CC) $(CFLAG) $(DBFLAG) maxbits.c
getpos.o : getpos.c headers.h decs.h
	    $(CC) $(CFLAG) $(DBFLAG) getpos.c
compression.o : compression.c headers.h decs.h
	        $(CC) $(CFLAG) $(DBFLAG) compression.c
compression2.o : compression2.c headers.h decs.h
	         $(CC) $(CFLAG) $(DBFLAG) compression2.c
compression3.o : compression3.c headers.h decs.h
	         $(CC) $(CFLAG) $(DBFLAG) compression3.c
compression4.o : compression4.c headers.h decs.h
	         $(CC) $(CFLAG) $(DBFLAG) compression4.c
compression5.o : compression5.c headers.h decs.h
	         $(CC) $(CFLAG) $(DBFLAG) compression5.c
compression6.o : compression6.c headers.h decs.h
	         $(CC) $(CFLAG) $(DBFLAG) compression6.c
compression7.o : compression7.c headers.h decs.h
	         $(CC) $(CFLAG) $(DBFLAG) compression7.c
compression8.o : compression8.c headers.h decs.h
	         $(CC) $(CFLAG) $(DBFLAG) compression8.c

run : 
	./mdcproj
clean:	
	-rm *.o
	-rm mdcproj
