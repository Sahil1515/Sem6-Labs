

#include<mpi.h>
#include <stdio.h>

    int main(int argc, char *agrv[])
{
    int rank;

    MPI_Init(&argc, &agrv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank % 2 == 0)
    {
        printf("Hello\t Rank :%d \n", rank);
    }
    else
    {
        printf("World\t Rank :%d \n", rank);
    }

    MPI_Finalize();

    return 0;
}