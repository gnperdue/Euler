ARCH = $(shell uname)

all:
	make -f Makefile.$(ARCH)

clean:
	make clean -f Makefile.$(ARCH)

remake:
	make clean
	make all

