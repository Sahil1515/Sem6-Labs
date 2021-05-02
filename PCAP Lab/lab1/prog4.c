#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char arr[6] = {'H', 'e', 'L', 'L', 'O', '\0'};
    int rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (arr[rank] >= 65 && arr[rank] <= 90)
    {
        arr[rank] += 32;
    }
    else
    {
        arr[rank] -= 32;
    }
    printf("rank %d After %s\n", rank, arr);
    MPI_Finalize();

    return 0;
}