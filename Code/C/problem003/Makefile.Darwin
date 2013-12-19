
CFLAGS= -g --std=gnu11 -O0 -fno-inline -Wall
COMPILE_OPTIONS=-DDEBUG

all: prepwork euler003

prepwork:
	@if test -d ../bin; then echo BinOk >& /dev/null ; else mkdir -p ../bin; fi

euler003: euler003.c
	mpicc $(CFLAGS) $(COMPILE_OPTIONS) -o euler003 euler003.c 
	mv euler003 ../bin


clean:
	rm -rf *.dSYM
	rm -f *.o
	rm -f ../bin/euler003

remake:
	make clean
	make all
