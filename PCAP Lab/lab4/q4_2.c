#include<stdio.h>
#include<mpi.h>
int main(int argc, char* argv[]){
    int rank,size,fin;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int a[4][4];
    int c[4];
    if(rank==0){
        fprintf(stdout,"Enter  4X4 matrix: \n");
        fflush(stdout);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&a[i][j]);
            }
        }
    }
    MPI_Scatter(a,4,MPI_INT,c,4,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scan(c,&fin,4,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    // printf("Final is %d\n",fin);
    MPI_Gather(&fin,4,MPI_INT,a,4,MPI_INT,0,MPI_COMM_WORLD);

    if(rank==0){
        fprintf(stdout,"Modified array is:\n");
        fflush(stdout);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    MPI_Finalize();
    return 0;
}

