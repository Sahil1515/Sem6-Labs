#include <stdio.h>
#include<mpi.h>


int main(int argc, char *argv[])
{
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	MPI_Status status;

	if(rank==0)
	{
		int n;
		long long int sum=0;
		printf("Here n is: %d\n",size);

		printf("Rank 0 finds: 1\n");
		sum=sum+1;

		for (int i = 1; i < size; i++)
		{
			int ele;
			MPI_Recv(&ele,1,MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,&status);
			sum+=ele;
		}
		printf("Total = %lld\n",sum );

		// fprintf(stdout, "Total %d ",sum );
		// fflush(stdout);

	}
	else
	{
		long long int sumTemp=1;
		printf("Rank %d finds :1",rank);
		if(rank%2==1)
		{

			for (int i = 2; i <=rank+1; i++)
			{
				sumTemp+=i;
				printf("+%d",i);
			}
		}
		else{

			for (int i = 2; i <=rank+1; i++)
			{
				sumTemp*=i;
				printf("*%d",i);
				
			}
		}

		printf(" = %lld\n",sumTemp );
		MPI_Send(&sumTemp,1,MPI_INT,0,1,MPI_COMM_WORLD);

	}

	MPI_Finalize();
	return 0;

	// mpicc Additional2.c -lm -o Additional2 && mpirun -np 4 ./Additional2
}