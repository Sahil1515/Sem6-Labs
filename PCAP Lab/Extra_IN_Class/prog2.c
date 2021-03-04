#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Status status;

    float arr[100];

    if (rank == 0)
    {

        int n;
        fprintf(stdout, "Enter value of n: ");
        fflush(stdout);
        scanf("%d", &n);
        MPI_Ssend(&n, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);

        fprintf(stdout, "Enter n numbers: ");
        fflush(stdout);

        for (int i = 0; i < n; i++)
            scanf(" %f", &arr[i]);

        MPI_Send(arr+(n/2), n / 2, MPI_FLOAT, 1, 2, MPI_COMM_WORLD);
    } 
    else if (rank == 1)
    {
        int n;
        MPI_Recv(&n, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);

        float ele[n / 2];
        MPI_Recv(ele, n / 2, MPI_FLOAT, 0, 2, MPI_COMM_WORLD, &status);
        for (int i = 0; i < (n / 2); i++)
            printf("%f \n", ele[i]);
    }
    MPI_Finalize();
    return 0;
}

//  mpicc prog1.c -lm -o prog1 && mpirun -np 4 ./prog1
