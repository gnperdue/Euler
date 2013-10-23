
CFLAGS= -g --std=gnu11 -O0 -fno-inline -Wall
# COMPILE_OPTIONS=-DDEBUG
CC=mpicc

all: prepwork euler092_sr euler092_reduce

prepwork:
	@if test -d ../bin; then echo BinOk >& /dev/null ; else mkdir -p ../bin; fi

euler092_sr: euler092_sr.c
	$(CC) $(CFLAGS) $(COMPILE_OPTIONS) -o euler092_sr euler092_sr.c 
	mv euler092_sr ../bin

euler092_reduce: euler092_reduce.c
	$(CC) $(CFLAGS) $(COMPILE_OPTIONS) -o euler092_reduce euler092_reduce.c 
	mv euler092_reduce ../bin

clean:
	rm -rf *.dSYM
	rm -f *.o
	rm -f ../bin/euler092_sr
	rm -f ../bin/euler092_reduce

remake:
	make clean
	make all
