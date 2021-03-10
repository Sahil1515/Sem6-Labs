
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int size, rank;
    int n;
    int arr[100];
    int ele[2];
    int sum[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("Enter %d Values\n", size * 2);
        for (int i = 0; i < size * 2; i++)
        {
            scanf("%d", &arr[i]);
        }
    }
    MPI_Scatter(arr, 2, MPI_INT, ele, 2, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Rank :%d and value got: %d %d \n", rank, ele[0], ele[1]);

    // int index = rank * 2;

    for (int i = 0; i < 2; i++)
    {
        int index = rank * 2;

        ele[index] = ele[index] * ele[index];
        ele[index + 1] = ele[index + 1] * ele[index + 1] * ele[index + 1];
    }

    // ele[0] = ele[0] * ele[0];
    // ele[1] = ele[1] * ele[1] * ele[1];

    MPI_Gather(ele, 2, MPI_INT, sum, 2, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)

        for (int i = 0; i < size * 2; i++)
        {
            printf("%d ", sum[i]);
        }
    printf("\n");

    MPI_Finalize();
}

//  mpicc prog0.c -lm -o prog0 && mpirun -np 4 ./prog0
