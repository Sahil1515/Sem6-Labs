#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int size, rank;
    int ele;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("Enter value:\n");
        scanf("%d", &ele);
    }

    MPI_Bcast(&ele, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Rank :%d and value got : %d \n", rank, ele);

    MPI_Finalize();
}

//  mpicc broadcast.c -lm -o broadcast && mpirun -np 4 ./broadcast




