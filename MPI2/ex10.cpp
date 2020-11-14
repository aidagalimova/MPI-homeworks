//#include <stdio.h>
//#include <stdlib.h>
//#include <mpi.h>
//#define comm MPI_COMM_WORLD
//void main(int argc, char** argv)
//{
//    MPI_Init(&argc, &argv);
//    int rank, num;
//    MPI_Comm_rank(comm, &rank);
//    MPI_Comm_size(comm, &num);
//    const int N = 80000;
//    int arr[N];
//    int newArr[N];
//    int newArr2[N];
//    int bsize = N * sizeof(int) + MPI_BSEND_OVERHEAD;
//    int* buf = new int[bsize];
//    double start;
//    double end;
//    MPI_Buffer_attach(buf, bsize);
//    if (rank == 0)
//    {
//        for (int i = 0; i < N; i++)
//        {
//            arr[i] = rand() % 100;
//        }
//        start = MPI_Wtime();
//        MPI_Rsend(arr, N, MPI_INT, 1, 3, comm);
//        MPI_Recv(&newArr2, N, MPI_INT, 1, 3, comm, MPI_STATUS_IGNORE);
//        end = MPI_Wtime();
//        printf("Rsend time %f\n", end - start);
//
//        start = MPI_Wtime();
//        MPI_Send(arr, N, MPI_INT, 1, 0, comm);
//        MPI_Recv(&newArr2, N, MPI_INT, 1, 0, comm, MPI_STATUS_IGNORE);
//        end = MPI_Wtime();
//        printf("Send time %f\n", end - start);
//
//        start = MPI_Wtime();
//        MPI_Ssend(arr, N, MPI_INT, 1, 1, comm);
//        MPI_Recv(&newArr2, N, MPI_INT, 1, 1, comm, MPI_STATUS_IGNORE);
//        end = MPI_Wtime();
//        printf("Ssend time %f\n", end - start);
//
//        start = MPI_Wtime();
//        MPI_Bsend(arr, N, MPI_INT, 1, 2, comm);
//        MPI_Recv(&newArr2, N, MPI_INT, 1, 2, comm, MPI_STATUS_IGNORE);
//        end = MPI_Wtime();
//        printf("Bsend time %f\n", end - start);
//    }
//    else if (rank == 1)
//    {
//        MPI_Recv(&newArr, N, MPI_INT, 0, 3, comm, MPI_STATUS_IGNORE);
//        MPI_Rsend(newArr, N, MPI_INT, 0, 3, comm);
//
//        MPI_Recv(&newArr, N, MPI_INT, 0, 0, comm, MPI_STATUS_IGNORE);
//        MPI_Send(newArr, N, MPI_INT, 0, 0, comm);
//
//        MPI_Recv(&newArr, N, MPI_INT, 0, 1, comm, MPI_STATUS_IGNORE);
//        MPI_Ssend(newArr, N, MPI_INT, 0, 1, comm);
//
//        MPI_Recv(&newArr, N, MPI_INT, 0, 2, comm, MPI_STATUS_IGNORE);
//        MPI_Bsend(newArr, N, MPI_INT, 0, 2, comm);
//    }
//    MPI_Finalize();
//}