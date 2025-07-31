#include <stdio.h>
#include <mpi.h> 

int main(int argc, char *argv[])
{
  int rank, size, mysend, myrecv;
  int sendto, getfrom;
  MPI_Status status;
  
  MPI_Init(&argc, &argv);
  
  /* Find out how many processes are involved. */
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  /* Find out what id this process has. */
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  /* work out who we are going to send to and receive from */
  sendto = rank + 1;
  getfrom = rank - 1;
  
  /* Deal with processors at the start and end of the ring */
  if(rank == 0){getfrom = size - 1;}
  if(rank == size - 1) {sendto = 0;}
  
  /* Set the values to send and receive - add 1 at each send */
  mysend = 0;
  myrecv = 0;
  
  /* Exchange messages. */
  if(rank == 0){
    mysend += 1;
    MPI_Send(&mysend, 1, MPI_INT, sendto, 1, MPI_COMM_WORLD);
    MPI_Recv(&myrecv, 1, MPI_INT, getfrom, 1, MPI_COMM_WORLD, &status);
  }else{
    MPI_Recv(&myrecv, 1, MPI_INT, getfrom, 1, MPI_COMM_WORLD, &status);
    mysend = myrecv + 1;
    MPI_Send(&mysend, 1, MPI_INT, sendto, 1, MPI_COMM_WORLD);
  }
   
  /* Procss 0 prints out the result. */
  if(rank == 0){
    printf("Rank %d has myrecv=%d.\n", rank, myrecv);
  } 
  
  MPI_Finalize();
}
