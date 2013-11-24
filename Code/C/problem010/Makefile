
CFLAGS= -g  -O0 -fno-inline -Wall
COMPILE_OPTIONS=-DDEBUG

all: prepwork euler010 euler010_pthr euler010_openmp1 euler010_openmp_reduct1

prepwork:
	@if test -d ../bin; then echo BinOk >& /dev/null ; else mkdir -p ../bin; fi

euler010: euler010.c
	clang $(CFLAGS) --std=gnu11 $(COMPILE_OPTIONS) -o euler010 euler010.c 
	mv euler010 ../bin

euler010_pthr: euler010_pthr.c
	clang $(CFLAGS) --std=gnu11 $(COMPILE_OPTIONS) -o euler010_pthr euler010_pthr.c 
	mv euler010_pthr ../bin

euler010_openmp1: euler010_openmp1.c
	gcc-4.2 $(CFLAGS) -fopenmp $(COMPILE_OPTIONS) -o euler010_openmp1 euler010_openmp1.c 
	mv euler010_openmp1 ../bin

euler010_openmp_reduct1: euler010_openmp_reduct1.c
	gcc-4.2 $(CFLAGS) -fopenmp $(COMPILE_OPTIONS) -o euler010_openmp_reduct1 euler010_openmp_reduct1.c 
	mv euler010_openmp_reduct1 ../bin

clean:
	rm -rf *.dSYM
	rm -f *.o
	rm -f ../bin/euler010
	rm -f ../bin/euler010_pthr
	rm -f ../bin/euler010_openmp1
	rm -f ../bin/euler010_openmp_reduct1

remake:
	make clean
	make all
