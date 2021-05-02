#include <stdio.h>
#include <mpi.h>
#include <string.h>

int isConsonant(char ch)
{
    return !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int main(int argc, char *argv[])
{
    int rank, size;

    int slen;

    int send_size_per_process = 0;

    char str[1000], ele[1000];

    int res[100];

    int len = 0;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter the string\n");
        scanf("%s", str);

        len = strlen(str);

        send_size_per_process = (len - (len % size)) / size;
    }

    MPI_Bcast(&send_size_per_process, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Scatter(str, send_size_per_process, MPI_CHAR, ele, send_size_per_process, MPI_CHAR, 0, MPI_COMM_WORLD);

    int tot_per_process = 0;

    for (int i = 0; i < send_size_per_process; i++)
    {
        if (isConsonant(ele[i]))
            tot_per_process++;
    }

    MPI_Gather(&tot_per_process, 1, MPI_INT, res, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        int total = 0;
        for (int i = 0; i < size; i++)
        {
            printf("Rank %d, %d non-vowels\n", i, res[i]);
            total=total+res[i];
        }

        for (int i = size * send_size_per_process; i < len; i++)
        {
            if (isConsonant(str[i]))
            {
                total++;
            }
        }

        printf("Total non-vowels: %d ", total);
    }
    MPI_Finalize();

    return 0;
}

//  mpicc prog3.c -lm -o prog3 && mpirun -np 4 ./prog3