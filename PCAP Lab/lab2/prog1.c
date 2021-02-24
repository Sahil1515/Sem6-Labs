
#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Status status;

    if (rank == 0)
    {
        char ele[100];
        printf("Enter the word in main process:\n");
        scanf("%s", ele);
        MPI_Ssend(&ele, 100, MPI_CHAR, 1, 1, MPI_COMM_WORLD);

        MPI_Recv(&ele, 100, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);

        printf("Got back after toggling: %s\n", ele);
    }
    else if (rank == 1)
    {
        char ele2[100];
        MPI_Recv(&ele2, 100, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &status);

        for (int i = 0; i < strlen(ele2); i++)
        {
            if (ele2[i] >= 65 && ele2[i] <= 90)
            {
                ele2[i] += 32;
            }
            else
            {
                ele2[i] -= 32;
            }
        }

        MPI_Ssend(&ele2, 100, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
