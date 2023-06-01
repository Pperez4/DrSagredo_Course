#include "mpi.h"
#include "string.h"
#include "stdio.h"

//--------------------------
// Compilation 
// mpicc -o hello hello.c
// mpirun -np 2 hello
//--------------------------



int main(int argc, char *argv[])
{
    int sizechar = 20;
    char message[sizechar];
    int myrank, numprocs;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    if (myrank == 0)
    {
        strcpy(message, "Hi, there");
        for (int i = 1; i < numprocs; i++)
            MPI_Send(message, strlen(message)+1, MPI_CHAR, i, 99, MPI_COMM_WORLD);
    }
    else if (myrank != 0){
        MPI_Recv(message, sizechar, MPI_CHAR, 0, 99, MPI_COMM_WORLD, &status);
        printf("received: %s:\n", message);
    }
    MPI_Finalize();
    return 0;

    
}