# MPI from Scratch

* [Learning objectives](#learning-objectives)
* [Prerequisites](#prerequisites)
* [C code](#c-code)
* [Finding rank and size](#finding-rank-and-size)
* [Ping pong](#ping-pong)

## Learning objectives

This tutorial was constructed to allow a set of students to get an idea about MPI (Message Passing Interface) with little programming experience. It is not intended to teach C or MPI but walk you throught the processes. By the end of this tutorial you should:

* Have an idea of what an MPI program is.

## Prequisites

You will need:

* An **editor**. An editor allows you to write plain text without any embedded text formatting.
* A **compiler**. This converts your source code, something you understand, into machine executable code, something your computer is able to run.
* An **MPI distribution**. This is the library that will allow you to get your code to be able to communicate.

## C code 

Your first minimalist traditional C program is to get it to print out `Hello World!`. Write this program to a file called `hello.c`:

```C
/* This is a comment and will be ignored */
#include <stdio.h> /* This contains definitions to libraries */

/* All C programs must have a main program */
/* int means the value of the variable is an integer (a whole number) */
/* char means string and the * means it will be a pointer, point to an address */
/* argc contains the number of arguments passed to the program */
/* argv is an array containing the values of the arguments */
int main(int argc,char *argv[])
{
  printf("Hellow World!\n"); /* This will print hello world to the screen */
}
```

See [hello.c](src/hello.c).

Note:

* All C statements must be terminated by a semicolon.
* The `\n` tells what is printed to take a new line.

In order to execute this program we need to compile the code. This will have to be compiled using the shell:

```bash
gcc -o hello hello.c
```

Here we are using the `gcc` compiler. The `-o` flag tells the compiler what to call the output executable (the default is to call it `a.out` if you do not specify anything). To run the code just type the executable name:

```bash
./hello
```

## MPI hello world

In a similar fashion we can write an MPI `Hello World!` program. Things are a little more complicated as we now have to use a wrapper to our C compiler to hide complicated compiler invocations.

To start our code now looks like:

```c
#include <stdio.h>
#include <mpi.h> /* We now need to define MPI routines */

int main(int argc, char *argv[])
{
  /* All MPI Programs must call MPI_Init at the start */
  MPI_Init(&argc, &argv);
  
  printf("Hello World!\n");
   
  /* Once all the MPI bits are finished you call MPI_Finalize */
  MPI_Finalize();
}
```

See [mpi_hello.c](src/mpi_hello.c).

The `&` in front of a variable name means we are passing the address to that variable.

If you call this `mpi_hello.c` then this time we compile the code using:

```bash
mpicc -o mpi_hello mpi_hello.c
```

To run the code this time we use:

```bash
mpirun -n 1 ./mpi_hello
```

The `-n` is telling MPI how many process to run on. So now we can do:

```bash
mpirun -n 4 ./mpi_hello
```

## Finding rank and size

Every process that participates in an MPI program is given a unique number, referred to as the `rank`, within a given communications context, the default is `MPI_COMM_WORLD`, which starts from 0 to the total number of processes involved. 

![Example MPI domain](imgs/MPIworld.png)

We can query this information and use it in our MPI program:

```C
#include <stdio.h>
#include <mpi.h> 

int main(int argc, char *argv[])
{
  /* Define variables that we are going to use in the program */
  int rank, size;
  
  MPI_Init(&argc, &argv);
  
  /* Find out how many processes are involved, pass it the address (use &) of size. */
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  /* Find out what id this process has, again pass the adreess of the variable. */
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  /* Print the rank and the size, %d means print an integer. */
  printf("Hello World! from rank %d out of %d processes\n", rank, size);
   
  /* Once all the MPI bits are finished you call MPI_Finalize */
  MPI_Finalize();
}
```

See [mpi_hello2.c](src/mpi_hello2.c).

Now compile as before:

```bash
mpicc -o mpi_hello2 mpi_hello2.c
```

and you can run it using:

```bash
mpirun -n 4 ./mpi_hello2
```

## Ping pong

We can now write programs that will exchange information. We will only use two processes for this exercise.

```c
#include <stdio.h>
#include <mpi.h> 

int main(int argc, char *argv[])
{
  int rank, size, myval;
  
  MPI_Init(&argc, &argv);
  
  /* Find out how many processes are involved. */
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  /* Find out what id this process has. */
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  /* Check we are only using two processes. */
  if(size > 2){
    if(rank == 0){ /* Only want one process to print error. */
      printf("This code will only work on two processes!");
    }
    /* Exit. */
    MPI_Finalize();
  }
  
if(rank == 0){
  /* const void *buf, int count, MPI_Datatype datatype, int dest, int tag,
             MPI_Comm comm*/
  MPI_Send(&myval, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
  MPI_Recv();  
}else{
  MPI_Recv();
  MPI_Send();
}
   

  MPI_Finalize();
}
```



---

<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br/>This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.