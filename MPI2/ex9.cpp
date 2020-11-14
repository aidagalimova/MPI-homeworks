//#include <stdio.h>
//#include <stdlib.h>
//#include <mpi.h>
//#define comm MPI_COMM_WORLD
//void main(int argc, char** argv)
//{
//    MPI_Init(&argc, &argv);
//    int N = 10;
//    int* arr = new int[N];
//    int rank, num;
//    MPI_Comm_rank(comm, &rank);
//    MPI_Comm_size(comm, &num);
//    if (rank == 0) {
//        for (int i = 0; i < N; i++) {
//            arr[i] = rand() % 100;
//            printf(" %d ", arr[i]);
//        }
//        printf("\n");
//    }
//    int* sendcount = new int[num];
//    int* displs = new int[num];
//    int* revdis = new int[num];
//    int rest = N;
//    int k = rest / num;
//    sendcount[0] = k;
//    displs[0] = 0;
//    revdis[0] = N - k;
//    for (int i = 1; i < num; i++) {
//        rest -= k;
//        k = rest / (num - i);
//        sendcount[i] = k;
//        displs[i] = displs[i - 1] + sendcount[i - 1];
//        revdis[i] = revdis[i - 1] - sendcount[i];
//    }
//    int proc_num = sendcount[rank];
//    int* local_arr = new int[proc_num];
//    MPI_Scatterv(arr, sendcount, displs, MPI_INT, local_arr, proc_num,
//        MPI_INT, 0, comm);
//
//    int temp;
//    for (int i = 0; i < proc_num / 2; i++) {
//        temp = local_arr[proc_num - i - 1];
//        local_arr[proc_num - i - 1] = local_arr[i];
//        local_arr[i] = temp;
//    }
//
//    MPI_Gatherv(local_arr, proc_num, MPI_INT, arr, sendcount, revdis, MPI_INT, 0, MPI_COMM_WORLD);
//
//    if (rank == 0) {
//        printf("New array:\n");
//        for (int i = 0; i < N; i++) 
//            printf(" %d ", arr[i]);
//    }
//    MPI_Finalize();
//}
