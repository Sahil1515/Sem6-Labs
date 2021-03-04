#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Status status;

    int arr[100];

    if (rank == 0)
    {

        int n;

        fprintf(stdout, "Enter a number: ");
        fflush(stdout);
        scanf(" %d", &n);
        
        for (int i = 1; i < size; i++)
        {
            MPI_Send(&n, 1, MPI_INT, i, i, MPI_COMM_WORLD);
        }
        
        for (int i = 1; i < size; i++)
        {
            MPI_Recv(&arr[i], 1, MPI_INT, i, 2, MPI_COMM_WORLD, &status);
        }

        for (int i = 1; i < size; i++)
        {
            printf("Rank %d, Number after increment %d\n",i, arr[i]);
        }
    }
    else 
    {
            int ele;
            MPI_Recv(&ele, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
            ele=ele+rank;

            MPI_Send(&ele, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}

//  mpicc send_num_andrank.c -lm -o send_num_andrank && mpirun -np 4 ./send_num_andrank
