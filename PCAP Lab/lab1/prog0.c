#include <mpi.h>
#include<stdio.h>

int main(int argc, char *agrv[])
{
    int rank,size;

    MPI_Init(&argc,&agrv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    printf("Rank :%d \t Size :%d\n",rank,size);

    MPI_Finalize();

    return 0;
}

// mpicc prog0.c -o prog && mpirun -np 4 ./prog