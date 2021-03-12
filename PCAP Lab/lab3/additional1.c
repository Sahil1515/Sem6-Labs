#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, M;

    int arr[1000], ele[1000];
    int res[1000];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter value of M:\n");
        scanf("%d", &M);

        printf("Enter the %d numbers:\n", size * M);
        for (int i = 0; i < size * M; i++)
        {
            scanf("%d", &arr[i]);
        }
    }
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(arr, M, MPI_INT, ele, M, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank % 2 == 0)
    {
        for (int i = 0; i < M; i++)
        {
            ele[i] = ele[i] * ele[i];
        }
    }
    else
    {
        for (int i = 0; i < M; i++)
        {
            ele[i] = ele[i] * ele[i] * ele[i];
        }
    }

    MPI_Gather(ele, M, MPI_INT, res, M, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        for (int i = 0; i < size*M; i++)
        {
            printf("Rank %d, operation on %d gives: %d\n", i,arr[i], res[i]);
        }
    }
    MPI_Finalize();

    return 0;
}

//  mpicc additional1.c -lm -o additional1 && mpirun -np 4 ./additional1