#include<mpi.h>
#include<iostream>
#include <ctime>

using namespace std;
#define comm MPI_COMM_WORLD
int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);

    const int N = 5;
    int a[N], b[N], local_sum = 0, sum = 0;
    int rank, size;

    MPI_Comm_size(comm, &size);
    MPI_Comm_rank(comm, &rank);
   
    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            a[i] = rand();
            b[i] = rand();
            //printf("%d %d\n", a[i], b[i]);
        }
    }

    int* sendcount = new int[size];
    int* displs = new int[size];

    int rest = N;
    int k = rest / size;
    sendcount[0] = k;
    displs[0] = 0;

    for (int i = 1; i < size; i++) {
        rest -= k;
        k = rest / (size - i);
        sendcount[i] = k;
        displs[i] = displs[i - 1] + sendcount[i - 1];
    }

    int proc_num = sendcount[rank];
    int* local_a = new int[proc_num];
    int* local_b = new int[proc_num];

    MPI_Scatterv(a, sendcount, displs, MPI_INT, local_a, proc_num,
        MPI_INT, 0, comm);
    MPI_Scatterv(b, sendcount, displs, MPI_INT, local_b, proc_num,
        MPI_INT, 0, comm);

    local_sum = 0;
    for (int i = 0; i < proc_num; i++) {
        local_sum += local_a[i] * local_b[i];
    }

    MPI_Reduce(&local_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Answer: %d", sum);
    }

    MPI_Finalize();
    return 0;
}