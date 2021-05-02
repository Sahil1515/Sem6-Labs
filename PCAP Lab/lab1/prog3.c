#include<mpi.h>
#include<stdio.h>
#include<math.h>

int main(int argc,char *argv[])
{
    const int num1=3,num2=4;
    int res=0;
    int rank;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    
    if(rank==0)
    {
        printf("Addition of (%d , %d): %d\n",num1,num2,num1+num2);
    }
    else if (rank==1)
    {
        printf("Multiplication of (%d , %d): %d\n",num1,num2,num1*num2);
    }
    else if(rank==2)
    {
        printf("Division of (%d , %d): %f\n",num1,num2,(float)num1/(float)num2);   
    }
    else if(rank==3)
    {
        printf("Subtraction of (%d , %d): %d\n",num1,num2,num1-num2);
    }

    MPI_Finalize();

    return 0;

}
