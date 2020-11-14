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
//    const int N = 8;
//    int arr[N];
//    int* newArr = new int[N];
//    int count = N / num;
//    int indforRecv = count;
//    int ind = count;
//
//    if (rank == 0) {
//        printf("OLD ARRAY:");
//        for (int i = 0; i < N; i++)
//        {
//            arr[i] = rand() % 100;
//            printf("%d ", arr[i]);
//        }
//        printf("\n");
//        for (int i = 0; i < num; i++)
//        {
//            int* subarr = new int[count];
//            if (i == 0)
//            {
//                printf("rank: %d", rank);
//                for (int i = 0; i < count; i++)
//                {
//                    subarr[i] = arr[i];
//                    printf(" %d ", subarr[i]);
//                    newArr[i] = subarr[i];
//                }
//                printf("\n");
//            }
//
//            else {
//                MPI_Send(&arr[ind], count, MPI_INT, i, 0, comm);
//                ind += count;
//            }
//            MPI_Recv(&newArr[indforRecv], count, MPI_INT, MPI_ANY_SOURCE, 1, comm, MPI_STATUS_IGNORE);
//            indforRecv += count;
//        }
//
//        for (int i = 1; i < num; i++)
//        {
//            MPI_Recv(&newArr[indforRecv], count, MPI_INT, MPI_ANY_SOURCE, 1, comm, MPI_STATUS_IGNORE);
//            indforRecv += count;
//        }
//        printf("NEW ARRAY:");
//        for (int i = 0; i < N; i++)
//        {
//            printf("%d ", newArr[i]);
//        }
//    }
//
//    else {
//        int* subarr = new int[count];
//        MPI_Recv(subarr, count, MPI_INT, 0, 0, comm, MPI_STATUS_IGNORE);
//        printf("rank: %d. Subarray:", rank);
//        for (int i = 0; i < count; i++)
//        {
//            printf(" %d ", subarr[i]);
//        }
//        MPI_Send(&subarr[0], count, MPI_INT, 0, 1, comm);
//        printf("\n");
//    }
//    MPI_Finalize();
//}
