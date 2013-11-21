
CFLAGS= -g --std=gnu11 -O0 -fno-inline -Wall
COMPILE_OPTIONS=-DDEBUG

all: prepwork euler010 euler010_pthr

prepwork:
	@if test -d ../bin; then echo BinOk >& /dev/null ; else mkdir -p ../bin; fi

euler010: euler010.c
	mpicc $(CFLAGS) $(COMPILE_OPTIONS) -o euler010 euler010.c 
	mv euler010 ../bin

euler010_pthr: euler010_pthr.c
	mpicc $(CFLAGS) $(COMPILE_OPTIONS) -o euler010_pthr euler010_pthr.c 
	mv euler010_pthr ../bin

clean:
	rm -rf *.dSYM
	rm -f *.o
	rm -f ../bin/euler010
	rm -f ../bin/euler010_pthr

remake:
	make clean
	make all
