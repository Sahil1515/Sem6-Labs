#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
    int rank,size,ele;

    int arr[100],res[100];
    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(rank==0)
    {
        printf("Enter the %d numbers:\n",size);
        for (int i = 0; i < size; i++)
        {
            scanf("%d",&arr[i]);
        }
    }

    MPI_Scatter(arr,1,MPI_INT,&ele,1,MPI_INT,0,MPI_COMM_WORLD);

    ele=ele*ele;

    MPI_Gather(&ele,1,MPI_INT,res,1,MPI_INT,0,MPI_COMM_WORLD);

    if(rank==0)
    {
        for (int i = 0; i < size; i++)
        {
            printf("Rank %d , square of %d is: %d\n",i,arr[i],res[i]);
        }
        
    }
    MPI_Finalize();

    return 0;

}

//  mpicc solved.c -lm -o solved && mpirun -np 4 ./solved