# Makefile to compile source code


CC = mpicc

all: hello hello2 pingpong

mpi_hello: src/mpi_hello.c
	${CC} -o $@ $<

mpi_hello2: src/mpi_hello2.c
	${CC} -o $@ $<

pingpong: src/pingpong.c
	${CC} -o $@ $<

clean:
	rm -f ./mpi_hello ./mpi_hello2 ./pingpong 

