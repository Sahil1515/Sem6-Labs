

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
        int ele;
        printf("Enter a value:\n");
        scanf("%d", &ele);

        MPI_Send(&ele, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);

        MPI_Recv(&ele, 1, MPI_INT, size-1, 1, MPI_COMM_WORLD, &status);
        printf("Rank 0. Recived value %d \n", ele);

    }
    else
    {
        int ele;
        MPI_Recv(&ele, 1, MPI_INT, rank - 1, 1, MPI_COMM_WORLD, &status);
        printf("Rank %d. Recived value %d \n", rank, ele);
        ele += 1;
        if (rank < size - 1)
        {
            MPI_Send(&ele, 1, MPI_INT, rank + 1, 1, MPI_COMM_WORLD);
        }
        else
            MPI_Send(&ele, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}

//   mpicc prog4.c -lm -o prog4 && mpirun -np 4 ./prog4