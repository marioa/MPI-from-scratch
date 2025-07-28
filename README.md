# MPI from Scratch

* [Learning objectives](#learning-objectives)
* [Prerequisites](#prerequisites)

## Learning objectives

## Prequisites

You will need:

* An **editor**. An editor allows you to write code.
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

Here we are using the `gcc` compiler. The `-o` flag tells the compiler what to call the output executable (the default is to call it `a.out` if you do not specify anything).