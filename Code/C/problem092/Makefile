
TARGET=euler092_sr
CFLAGS= -g --std=gnu11 -O0 -fno-inline -Wall
CC=mpicc

all: prepwork $(TARGET)

prepwork:
	@if test -d ../bin; then echo BinOk >& /dev/null ; else mkdir -p ../bin; fi

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c 
	mv $(TARGET) ../bin

clean:
	rm -rf *.dSYM
	rm -f *.o
	rm -f ../bin/$(TARGET)

remake:
	make clean
	make all
