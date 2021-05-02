
// #include <mpi.h>
// #include <stdio.h>
// #include <math.h>
// #include <string.h>

// int main(int argc, char *argv[])
// {
//     int rank;

//     MPI_Init(&argc, &argv);
//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);

//     MPI_Status status;

//     if (rank == 0)
//     {
//         char ele[100];
//         printf("Enter the word in main process:\n");
//         scanf("%s", ele);
//         MPI_Ssend(&ele, 100, MPI_CHAR, 1, 1, MPI_COMM_WORLD);

//         MPI_Recv(&ele, 100, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);

//         printf("Got back after toggling: %s\n", ele);
//     }
//     else if (rank == 1)
//     {
//         char ele2[100];
//         MPI_Recv(&ele2, 100, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &status);

//         for (int i = 0; i < strlen(ele2); i++)
//         {
//             if (ele2[i] >= 65 && ele2[i] <= 90)
//             {
//                 ele2[i] += 32;
//             }
//             else
//             {
//                 ele2[i] -= 32;
//             }
//         }

//         MPI_Ssend(&ele2, 100, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
//     }

//     MPI_Finalize();

//     return 0;
// }

//  mpicc prog1.c -lm -o prog1 && mpirun -np 4 ./prog1

#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, n;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        char a[25];

        fprintf(stdout, "Enter the Word : \n");
        fflush(stdout);
        scanf("%s", a);

        n = strlen(a);

        MPI_Ssend(&n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Sent\n");
        MPI_Ssend(a, n+1, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
        fprintf(stdout, "Process %d sent:  %s\n", rank, a);
        fflush(stdout);
        MPI_Recv(a, n+1, MPI_CHAR, 1, 2, MPI_COMM_WORLD, &status);
        fprintf(stdout, "Process %d recieved: %s\n", rank, a);
        fflush(stdout);
    }
    else if (rank == 1)
    {
        char b[25];

        MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Got\n");
        MPI_Recv(b, n+1, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &status);
        fprintf(stdout, "Process %d recieved:  %s\n", rank, b);
        fflush(stdout);

        for (int i = 0; i < n; i++)
        {
            if (b[i] >= 'a' && b[i] <= 'z')
            {
                b[i] = b[i] - 32;
            }
            else
            {
                b[i] = b[i] + 32;
            }
        }
        MPI_Ssend(b, n+1, MPI_CHAR, 0, 2, MPI_COMM_WORLD);
        fprintf(stdout, "Process %d sent: %s\n", rank, b);
        fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}