#include <stdio.h>
#include <mpi.h> 

int main(int argc, char *argv[])
{
  int rank, size, mysend, myrecv;
  int dims[2], periods[2]={1,1};
  MPI_Comm Comm_cart;
  MPI_Status status;
  
  MPI_Init(&argc, &argv);
  
  /* Find out how many processes are involved. */
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  /* Find out what id this process has. */
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
 /* Dimensional split of size into 2d. */
  MPI_Dims_create(size, 2, dims);
  
  /* Print out the split. */
  if(rank == 0){
    printf("Using a %d x %d array.\n", dims[0], dims[1]);
  }
  
 /* Create a cartesian communicator. */
  MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 1, &Comm_cart);
  
  MPI_Finalize();

}

