#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]){
    int rank,size,fact=1,factsum,errclass,resultlen;
    char err_buffer[1000];
    MPI_Init(&argc,&argv);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    for(int i=1;i<=rank+1;i++){
        fact*=i;
    }
    int ierr=MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    if(ierr!=MPI_SUCCESS){
        MPI_Error_class(ierr,&errclass);
        if(errclass==MPI_ERR_COUNT){
            printf("Invalid rank used in MPI Scan call\n");
            MPI_Error_string(ierr,err_buffer,&resultlen);
            printf("%s",err_buffer);
            MPI_Finalize();
        }
    }
    if(rank==size-1){
        fprintf(stdout,"\n\n\t\tProcess %d \n\n\t\tFactorial sum %d\n\n",rank,factsum);
        fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}

// mpicc q1.c -lm -o q1 && mpirun -np 4 ./q1