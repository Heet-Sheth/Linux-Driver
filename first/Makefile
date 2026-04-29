obj-m += ldd.o	#string variable (system provided), to be appended

all: ldd.c	#target and depedency, command bellow
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) module

clean:	#target, only a single tab before actual commmand
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


#use Makefile, or filename.mk, case sensitive
#use as make or make filename.mk
#use target (default 1st 1)