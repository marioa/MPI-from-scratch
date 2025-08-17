# Makefile to compile source code


CC = mpicc

all: mpi_hello mpi_hello2 pingpong ring

mpi_hello: src/mpi_hello.c
	${CC} -o $@ $<

mpi_hello2: src/mpi_hello2.c
	${CC} -o $@ $<

pingpong: src/pingpong.c
	${CC} -o $@ $<

ring: src/ring.c
	${CC} -o $@ $<

mpi_cart: src/mpi_cart.c
	${CC} -o $@ $<

clean:
	rm -fr ./hello ./mpi_hello ./mpi_hello2 ./pingpong ./ring *.dSYM ./mpi_cart

