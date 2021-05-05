
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int size, rank;
    int n;
    int arr[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("Enter value of n:\n");
        scanf("%d", &n);
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Enter %d Values\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
    }

    MPI_Bcast(arr, n, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Rank :%d and value got: ",rank);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    MPI_Finalize();
}

//  mpicc broadcast_array.c -lm -o broadcast_array && mpirun -np 4 ./broadcast_array
