
CFLAGS= -g --std=gnu11 -O0 -fno-inline -Wall
CC=mpicc

all: prepwork euler014

prepwork:
	@if test -d ../bin; then echo BinOk >& /dev/null ; else mkdir -p ../bin; fi

euler014: euler014.c
	$(CC) $(CFLAGS) -o euler014 euler014.c 
	mv euler014 ../bin


clean:
	rm -rf *.dSYM
	rm -f *.o
	rm -f ../bin/euler014

remake:
	make clean
	make all
