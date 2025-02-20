// #include "mpi.h"
// #include <stdio.h>
// #include <string.h>
// void ErrorHandler(int error_code)
// {
//     if (error_code != MPI_SUCCESS)
//     {
//         char error_string[BUFSIZ];
//         int length_of_error_string, error_class;
//         MPI_Error_class(error_code, &error_class);
//         MPI_Error_string(error_code, error_string, &length_of_error_string);
//         printf("%d %s\n", error_class, error_string);
//     }
// }
// int main(int argc, char *argv[])
// {
//     int rank, size, error_code;
//     int i = 0, j;
//     int k = 0, fac = 1, ans[1000], sum = 0;
//     int n, a[100][100], b[100];
//     MPI_Init(&argc, &argv);
//     error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
//     if (rank == 0)
//     {
//         printf("Enter the elements of matrix \n");
//         for (i = 0; i < 4; i++)
//         {
//             for (j = 0; j < 4; j++)
//             {
//                 scanf("%d", &a[i][j]);
//             }
//         }
//         printf("\n");
//     }
//     error_code = MPI_Scatter(a, 100, MPI_INT, b, 100, MPI_INT, 0,
//                              MPI_COMM_WORLD);
//     error_code = MPI_Scan(b, ans, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
//     ErrorHandler(error_code);
//     printf("\n");
//     for (i = 0; i < 4; i++)
//     {
//         printf("%d ", ans[i]);
//     }
//     printf("\n");
//     MPI_Finalize();
//     return 0;
// }

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
void ErrorHandler(int error_code)
{
    if (error_code != MPI_SUCCESS)
    {
        char error_string[BUFSIZ];
        int length_of_error_string, error_class;
        MPI_Error_class(error_code, &error_class);
        MPI_Error_string(error_code, error_string, &length_of_uerror_string);
        printf("Errors:= %d \t %s\n", error_class, error_string);
    }
}
int main(int argc, char **argv)
{
    int rank, size, error_code;
    int arr[4][4], arr2[4], partsum[20], i, j, ele, pos;
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    ErrorHandler(error_code);
    error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
    ErrorHandler(error_code);
    if (rank == 0)
    {
        printf("Enter  4X4 matrix\n");
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        printf("Ouput Matrix is: \n");
    }
    MPI_Scatter(arr, 4, MPI_INT, arr2, 4, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scan(arr2, partsum, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    for (i = 0; i < 4; i++)
    {
        printf("%d ", partsum[i]);
    }
    printf(“\n”);

    MPI_Finalize();
    return 0;
}
// mpicc q4_2.c -lm -o q4_2 && mpirun -np 4 ./q4_2
