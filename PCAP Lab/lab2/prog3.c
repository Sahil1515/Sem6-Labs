

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Status status;

    char buff[100];
    int n = 100l;
    MPI_Buffer_attach(buff, n);
    if (rank == 0)
    {
        int arr[100];

        printf("Enter %d numbers:\n", size);
        scanf("%d", &arr[0]);
        printf("Rank 0: Square of %d is :%d\n", arr[0], arr[0] * arr[0]);

        for (int i = 1; i < size; i++)
        {
            scanf("%d", &arr[i]);
            MPI_Bsend(&arr[i], 1, MPI_INT, i, i, MPI_COMM_WORLD);
        }
    }
    else
    {
        int ele;
        MPI_Recv(&ele, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);

        if (rank % 2 == 0)
            printf("Rank %d: Square of %d is :%d\n", rank, ele, ele*ele);
        else
            printf("Rank %d: Cube of %d is :%d\n", rank, ele,ele* ele* ele);
    }

    MPI_Buffer_detach(buff, &n);
    MPI_Finalize();

    return 0;
}

//  mpicc prog3.c -lm -o prog3 && mpirun -np 4 ./prog3