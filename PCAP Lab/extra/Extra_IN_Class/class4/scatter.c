
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int size, rank;
    int n;
    int arr[100];
    int ele;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("Enter %d Values\n", size);
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
    }

    MPI_Scatter(arr, 1, MPI_INT,  &ele,1,MPI_INT ,0, MPI_COMM_WORLD);
    printf("Rank :%d and value got: %d\n",rank,ele);

    MPI_Finalize();
}

//  mpicc scatter.c -lm -o scatter && mpirun -np 4 ./scatter
