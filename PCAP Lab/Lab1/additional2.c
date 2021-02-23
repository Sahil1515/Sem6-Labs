
#include <mpi.h>
#include <stdio.h>
#include <math.h>

int isPrime(int num)
{
    for (int i = 2; i*i <= num; i++)
    {
        if(num%i==0)
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank==0)
    {
        for (int i = 2; i <=50; i++)
        {
            if(isPrime(i))
            {
                printf("%d ",i);
            }
        }
        
    }
    else{
        for (int i = 50; i <=100; i++)
        {
            if(isPrime(i))
            {
                printf("%d ",i);
            }
        }

    }
   
    MPI_Finalize();

    return 0;
}
