

#include <stdio.h>
#include <mpi.h>

int isPrime(int num)
{
    if(num==1)
        return 0;

    for (int i = 2; i*i <= num; i++)
    {
        if(num%i==0)
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Status status;

    char buff[100];
    int n = 100l;
    if (rank == 0)
    {
        int arr[100];

        printf("Enter %d numbers:\n", size);
        scanf("%d", &arr[0]);

        if (isPrime(arr[0]))
        {
            printf("Rank %d. Number: %d Is Prime\n",rank,arr[0]);    
        }
        else
            printf("Rank %d. Number: %d Is Not Prime\n",rank,arr[0]);

        for (int i = 1; i < size; i++)
        {
            scanf("%d", &arr[i]);
            MPI_Send(&arr[i], 1, MPI_INT, i, i, MPI_COMM_WORLD);
        }
    }
    else
    {
        int ele;
        MPI_Recv(&ele, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
        if (isPrime(ele))
        {
            printf("Rank %d. Number: %d Is Prime\n",rank,ele);    
        }
        else
            printf("Rank %d. Number: %d Is Not Prime\n",rank,ele);
           
    }

    MPI_Finalize();

    return 0;
}

//  mpicc Additional1.c -lm -o Additional1 && mpirun -np 4 ./Additional1