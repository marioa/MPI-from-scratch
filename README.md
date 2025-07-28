# MPI from Scratch

* [Learning objectives](#learning-objectives)
* [Prerequisites](#prerequisites)
* [C code](#c-code)

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
  
  printf("Hello World!");
   
  /* Once all the MPI bits are finished you call MPI_Finalize */
  MPI_Finalize();
}
```

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



---

<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br/>This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.