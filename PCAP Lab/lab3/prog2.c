#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
    int rank,size,M;

    int arr[1000],ele[100];
    float res[1000];

    float avg=0;

    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(rank==0)
    {
        printf("Enter value of M:\n");
        scanf("%d",&M);

        printf("Enter the %d numbers:\n",size*M);
        for (int i = 0; i < size*M; i++)
        {
            scanf("%d",&arr[i]);
        }
    }
    MPI_Bcast(&M,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(arr,M,MPI_INT,ele,M,MPI_INT,0,MPI_COMM_WORLD);
    
    for (int i = 0; i <M; i++)
    {
        avg=avg+ele[i];
    }
    avg=avg/M;
    

    MPI_Gather(&avg,1,MPI_FLOAT,res,1,MPI_FLOAT,0,MPI_COMM_WORLD);
    
    if(rank==0)
    {
        float final_avg=0;
        for (int i = 0; i < size; i++)
        {
            printf("Rank %d, avg is: %f\n",i,res[i]);
            final_avg=final_avg+res[i];
        }

        final_avg=final_avg/M;

        printf("Average is :%f",final_avg);
        
    }
    MPI_Finalize();

    return 0;

}

//  mpicc prog2.c -lm -o prog2 && mpirun -np 4 ./prog2