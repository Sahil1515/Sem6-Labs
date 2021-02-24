#include<mpi.h>
#include<stdio.h>
#include<math.h>

int main(int argc,char *argv[])
{
    const int x=3;
    int rank;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    printf("Rank %d\n",rank);

    int p=pow(x,rank);
    printf("power(%d,%d): %d\n",x,rank,p);

    MPI_Finalize();

    return 0;

}

//  mpicc prog1.c -lm -o prog1 && mpirun -np 4 ./prog1