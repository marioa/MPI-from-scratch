#include <stdio.h>
#include <mpi.h> 

int main(int argc, char *argv[])
{
  int rank, size, mysend, myrecv;
  MPI_Status status;
  
  MPI_Init(&argc, &argv);
  
  /* Find out how many processes are involved. */
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  /* Find out what id this process has. */
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  /* Check we are only using two processes. */
  if(size != 2){
    if(rank == 0){ /* Only want one process to print error. */
      printf("This code will only work on two processes!\n\n");
    }
    /* Exit. */
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
  /* Initialise the values. */
  mysend = rank;
  myrecv = rank;
  
  /* Exchange messages. */
  if(rank == 0){
    MPI_Send(&mysend, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
    MPI_Recv(&myrecv, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
  }else{
    MPI_Recv(&myrecv, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
    MPI_Send(&mysend, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
  }
   
  /* Print out the result. */
  printf("Rank %d has mysend=%d and myrecv=%d.\n", rank, mysend, myrecv);
  
  MPI_Finalize();
}
