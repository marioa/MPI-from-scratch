# Makefile to compile source code


CC = mpicc

hello: src/mpi_hello.c
	${CC} -o mpi_hello $<

hello2: src/mpi_hello2.c
	${CC} -o mpi_hello $<

pingpong: src/pingpong.c
	${CC} -o pingpong $<

