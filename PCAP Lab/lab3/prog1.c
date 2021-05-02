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

    int fact=1;

    for (int i = 1; i <=ele; i++)
    {
        fact=fact*i;
    }
    

    MPI_Gather(&fact,1,MPI_INT,res,1,MPI_INT,0,MPI_COMM_WORLD);

    if(rank==0)
    {
        long long int result=0;
        for (int i = 0; i < size; i++)
        {
            printf("Rank %d, factorial of %d id : %d\n",i,arr[i],res[i]);
            result=result+res[i];
        }

        printf("Sum of all factorials is :%lld",result);
        
    }
    MPI_Finalize();

    return 0;

}

//  mpicc prog1.c -lm -o prog1 && mpirun -np 4 ./prog1