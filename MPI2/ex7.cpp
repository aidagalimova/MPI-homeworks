//
//#include<mpi.h>
//#include<iostream>
//#include <ctime>
//
//using namespace std;
//#define comm MPI_COMM_WORLD
//int main(int argc, char** argv)
//{
//    MPI_Init(&argc, &argv);
//    const int N = 8;
//    int matrix[N][N];
//    int matrix_arr[N * N];
//    int vector[N];
//    int rank, size;
//
//    MPI_Comm_size(comm, &size);
//    MPI_Comm_rank(comm, &rank);
//   
//    int* result = new int[N];
//
//    if (rank == 0) {
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                matrix[i][j] =  rand() % 100;
//            }
//            vector[i] = rand() % 100;
//        }
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                matrix_arr[i * N + j] = matrix[j][i];
//            }
//        }
//    }
//   
//    int sendcount = N * N/size;
//    int* local_columns = new int[sendcount];
//
//    int vec_sendcount = sendcount / N;
//    int* local_vec = new int[vec_sendcount];
//
//    MPI_Scatter(matrix_arr, sendcount, MPI_INT, local_columns, sendcount, MPI_INT, 0, comm);
//    MPI_Scatter(vector, vec_sendcount, MPI_INT, local_vec, vec_sendcount, MPI_INT, 0, comm);
//    int* local_sum = new int[N];
//    for (int i = 0; i < N; i++)
//    {
//        local_sum[i] = 0;
//    }
//    for (int i = 0; i < vec_sendcount; i++)
//    {
//        for (int j = 0; j < N; j++)
//        {
//            local_sum[j] += local_columns[j + N * i] * local_vec[i];
//        }
//    }
//    MPI_Reduce(local_sum, result, N, MPI_INT, MPI_SUM, 0, comm);
//
//    if (rank == 0)
//        for (int i = 0; i < N; i++) {
//         printf(" %d ", result[i]);
//        }
//
//    MPI_Finalize();
//    return 0;
//}