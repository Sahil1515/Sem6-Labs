#include<stdio.h>
#include<mpi.h>

int main(int argc , char *argv[])
{
    int rank, size;
    int rec,fact=1;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    for(int i=1;i<=rank+1;i++)
    fact=fact*i;

    MPI_Scan(&fact,&rec,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);

    if(rank==size-1)
    {
    printf("Rank %d, factorilas of %d is : %d\n",rank,rank+1,rec);

    }


    MPI_Finalize();

    return 0;


}


// mpicc prog1.c -lm -o prog1 && mpirun -np 4 ./prog1