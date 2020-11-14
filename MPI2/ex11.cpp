#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define comm MPI_COMM_WORLD
void main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);
    int rank, num;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &num);
    const int N = 8;
    int arr[N];
    int arr2[N];
    int res[N];
    if (rank == 0)
    {
        printf("array before\n");
        for (int i = 0; i < N; i++)
        {
            arr[i] = rand() % 100;
            printf("%d ", arr[i]);
        }
    }
    if (rank != 0)
    {
        MPI_Recv(&arr, N, MPI_INT, rank - 1, 0, comm, MPI_STATUS_IGNORE);
    }
    for (int i = 0; i < N; i++)
    {
        arr[i] += 1;
    }
    if (rank != num - 1) MPI_Send(arr, N, MPI_INT, rank + 1, 0, comm);
    else {
        printf("array after:\n");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    MPI_Finalize();
}