#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, M;

    int arr[1000], ele[1000],res[1000];

    int total_e, total_o;
    
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

    int e_count = 0;
    int o_count = 0;
    for (int i = 0; i < M; i++)
    {
        if (ele[i] % 2 == 0)
            ele[i] = 1, e_count++;
        else
            ele[i] = 0, o_count++;
    }

    MPI_Gather(ele, M, MPI_INT, res, M, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Reduce(&e_count,&total_e,1 ,MPI_INT, MPI_SUM,0,MPI_COMM_WORLD);
    MPI_Reduce(&o_count,&total_o,1 ,MPI_INT, MPI_SUM,0,MPI_COMM_WORLD);


    if (rank == 0)
    {
        for (int i = 0; i < size * M; i++)
        {
            printf("Rank %d, operation on %d gives: %d\n", i, arr[i], res[i]);
        }

        printf("Taotal even numbers in array are:%d \n",total_e);
        printf("Taotal odd numbers in array are:%d \n",total_o);

    }
    MPI_Finalize();

    return 0;
}

// https://cvw.cac.cornell.edu/mpicc/scan

//  mpicc additional2.c -lm -o additional2 && mpirun -np 4 ./additional2