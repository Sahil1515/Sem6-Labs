

#include <stdio.h>
#include <mpi.h>


int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Status status;

    if (rank == 0)
    {
        MPI_Send(&a, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        MPI_Recv(&b, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
        c = a + b / 2;
    }
    else if (rank == 1)
    {
        MPI_Send(&b, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
        MPI_Recv(&a, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
        c = a + b / 2;
        printf("%d",c);
    }

    MPI_Finalize();

    return 0;
}

//  mpicc Additional1.c -lm -o Additional1 && mpirun -np 4 ./Additional1