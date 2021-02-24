
#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_rank(MPI_COMM_WORLD, &size);

    MPI_Status status;

    if (rank == 0)
    {
        int ele;
        printf("Enter the integer in main process:\n");
        scanf("%d", &ele);
        for (int i = 1; i < size; i++)
        {
            MPI_Send(&ele, 1, MPI_INT, i, i, MPI_COMM_WORLD);
        }
    }
    else
    {
        int ele2;
        MPI_Recv(&ele2, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
        printf("Rank %d\t Number:%d \n", rank, ele2);
    }

    MPI_Finalize();

    return 0;
}
