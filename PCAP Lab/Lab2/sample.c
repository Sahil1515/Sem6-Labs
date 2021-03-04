
#include <mpi.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Status status;

    if(rank==0)
    {
        int ele;
        printf("Enter the integer value in main process:\n");
        scanf("%d",&ele);
        MPI_Send(&ele,1,MPI_INT,1,1,MPI_COMM_WORLD);
    }
    else{
        int ele2;
        MPI_Recv(&ele2,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        printf("Process rank 1 got %d\n",ele2);
    }

    MPI_Finalize();

    return 0;
}
