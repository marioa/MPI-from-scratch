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
