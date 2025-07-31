# Makefile to compile source code


CC = mpicc

all: hello hello2 pingpong

hello: src/mpi_hello.c
	${CC} -o mpi_hello $<

hello2: src/mpi_hello2.c
	${CC} -o mpi_hello $<

pingpong: src/pingpong.c
	${CC} -o pingpong $<

clean:
	rm -f ./mpi_hello ./mpi_hello2 ./pingpong 

