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
    char str1[1000], str2[1000], ele1[1000], ele2[1000];
    char res[10000];
    int len = 0;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter the string 1 : \n");
        scanf("%s", str1);

        len = strlen(str1);

        printf("Enter the string 2 of size %d: \n", len);
        scanf("%s", str2);

        send_size_per_process = (len - (len % size)) / size;
    }

    MPI_Bcast(&send_size_per_process, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(str1, send_size_per_process, MPI_CHAR, ele1, send_size_per_process, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(str2, send_size_per_process, MPI_CHAR, ele2, send_size_per_process, MPI_CHAR, 0, MPI_COMM_WORLD);

    char per_process_arr[1000];
    int count = 0;

    for (int i = 0; i < send_size_per_process; i++)
    {
        
            per_process_arr[count++] = ele1[i];
            per_process_arr[count++] = ele2[i];
    }

    MPI_Gather(per_process_arr, count, MPI_CHAR, res, count, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        count = strlen(res);

        for (int i = count / 2; i < len; i++)
        {
                res[count++] = str1[i];
                res[count++] = str2[i];
        }
        printf("Output string: \n");
        puts(res);
    }
    MPI_Finalize();

    return 0;
}

//  mpicc prog4.c -lm -o prog4 && mpirun -np 4 ./prog4