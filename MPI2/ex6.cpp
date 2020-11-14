//#include<mpi.h>
//#include<iostream>
//#include <ctime>
//
//#define comm MPI_COMM_WORLD
//int main(int argc, char** argv)
//{
//    MPI_Init(&argc, &argv);
//    const int N = 8;
//    int matrix[N][N];
//    int matrix_arr[N * N];
//    int rank, size;
//
//    MPI_Comm_size(comm, &size);
//    MPI_Comm_rank(comm, &rank);
//
//    if (rank == 0) {
//        for (int i = 0; i < N; i++) {
//            int min = INT_MAX;
//            for (int j = 0; j < N; j++) {
//                matrix[i][j] = rand() % 100;
//                matrix_arr[i * N + j] = matrix[i][j];
//                if (min > matrix[i][j])
//                {
//                    min = matrix[i][j];
//                }
//                printf("%d ", matrix[i][j]);
//            }
//            printf("\nlocal min: %d \n", min);
//        }
//    }
//    int* sendcount = new int[size];
//    int* displs = new int[size];
//    int rest = N*N;
//    int k = rest / size;
//    sendcount[0] = k;
//    displs[0] = 0;
//    for (int i = 1; i < size; i++) {
//        rest -= k;
//        k = rest / (size - i);
//        sendcount[i] = k;
//        displs[i] = displs[i - 1] + sendcount[i - 1];
//    }
//
//    int proc_num = sendcount[rank];
//    int rows = proc_num / N;
//    int* local_matrix = new int[proc_num];
//    int* local_mins = new int[rows];
//    int local_maxmin = INT_MIN;
//
//    MPI_Scatterv(matrix_arr, sendcount, displs, MPI_INT, local_matrix, proc_num, MPI_INT, 0, comm);
//    
//    for (int i = 0; i < rows; i++)
//    {
//        int min = INT_MAX;
//        for (int j = 0; j < N; j++)
//        {
//            if (min > local_matrix[j + N * i])
//            {
//                min = local_matrix[j + N * i];
//            }
//            local_mins[i] = min;
//        }
//        if (local_maxmin < local_mins[i])
//        {
//            local_maxmin = local_mins[i];
//        }
//    }
//
//    int* maxmin;
//    MPI_Reduce(&local_maxmin, &maxmin, 1, MPI_INT, MPI_MAX, 0, comm);
//    if (rank == 0) {
//        printf("MaxMin: %d \n", maxmin);
//    }
//    MPI_Finalize();
//    return 0;
//}