
#include <mpi.h>
#include <stdio.h>
#include <math.h>

int reverse(int num)
{
    int rev = 0;
    while (num)
    {
        int rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }
    return rev;
}

int main(int argc, char *argv[])
{
    int arr[9] = {18, 523, 301, 1234, 2, 14, 108, 150, 1928};
    int rank;
    int rev;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    arr[rank] = reverse(arr[rank]);

    printf("Rank %d\t%d\n", rank,arr[rank]);

    MPI_Finalize();

    return 0;
}
