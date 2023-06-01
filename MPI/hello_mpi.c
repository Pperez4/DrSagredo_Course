#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
//--------------------------
// Compilation 
// mpicc -o hello hello_mpi.c
// mpirun -np 2 hello
//--------------------------




int main(int argc, char** argv)
{
    //Initialize the MPI environment
    MPI_Init(NULL, NULL);

    //GET THE NUMBER OF PROCESSES
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    //GET THE RANK OF THE PROCESS
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    //GET THE NAME OF THE PROCESSOR
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    //Print of a hello world message 
    printf("Hello World from processor %s, rank %d out of %d processors\n",processor_name, world_rank, world_size);

    //FINALIZE THE MPI ENVIRONMENT 
    MPI_Finalize();
}