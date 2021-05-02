#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]){
    int arr[3][3],size,rank,occurance=0,element,finsum,b[3],errclass;
    MPI_Init(&argc,&argv);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
     MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(rank==0){
        printf("Enter the 9 elements of 3x3 matrix: \n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&arr[i][j]);
            }
        }

        printf("Enter the element to search: \n");
        scanf("%d",&element);
    }
    MPI_Bcast(&element,1,MPI_INT,0,MPI_COMM_WORLD);
    int ierr=MPI_Scatter(arr,3,MPI_INT,b,3,MPI_INT,0,MPI_COMM_WORLD);

    if(ierr!=MPI_SUCCESS){
        MPI_Error_class(ierr,&errclass);
        if(errclass==MPI_ERR_COUNT){
            printf("Invalid rank used in MPI Scan call\n");
            
            MPI_Finalize();
        }
    }
    for(int i=0;i<3;i++){
        if(b[i]==element){
            occurance++;
        }
    }
    MPI_Scan(&occurance,&finsum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    if(rank==size-1){
        printf("Number of occurances of %d is %d\n",element,finsum);
    }
    MPI_Finalize();
    return 0;
    
    
}

// mpicc q3.c -lm -o q3 && mpirun -np 4 ./q3