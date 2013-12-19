
CFLAGS= -g --std=gnu11 -O0 -fno-inline -Wall
COMPILE_OPTIONS=-DDEBUG

all: prepwork euler014_mpi euler014_pthr

prepwork:
	@if test -d ../bin; then echo BinOk >& /dev/null ; else mkdir -p ../bin; fi

euler014_mpi: euler014_mpi.c
	mpicc $(CFLAGS) $(COMPILE_OPTIONS) -o euler014_mpi euler014_mpi.c 
	mv euler014_mpi ../bin

euler014_pthr: euler014_pthr.c
	gcc $(CFLAGS) $(COMPILE_OPTIONS) -o euler014_pthr euler014_pthr.c 
	mv euler014_pthr ../bin

clean:
	rm -rf *.dSYM
	rm -f *.o
	rm -f ../bin/euler014_mpi
	rm -f ../bin/euler014_pthr

remake:
	make clean
	make all
