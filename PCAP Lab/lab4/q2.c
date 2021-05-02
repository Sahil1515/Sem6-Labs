#include<stdio.h>
#include<mpi.h>
float func(float x){
    return 4/(1+x*x);
}
int main(int argc, char* argv[]){
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    
    float interval,mid,height,sum,area;
    int errclass;

    interval=(1/(float)size);
    mid=(rank*interval)+interval/2;
    height=func(mid);
    area=height*interval;
    int ierr=MPI_Reduce(&area,&sum,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);

    if(ierr!=MPI_SUCCESS){
        MPI_Error_class(ierr,&errclass);
        if(errclass==MPI_ERR_COUNT){
            printf("Invalid rank used in MPI Scan call\n");
            
            MPI_Finalize();
        }
    }
    if(rank==0){
        printf("\n\n\t\tProcess %d pi value is %f\n\n\n",rank,sum);
    }


    MPI_Finalize();
    return 0;
}

// mpicc q2.c -lm -o q2 && mpirun -np 4 ./q2
