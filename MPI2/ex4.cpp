
#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#define comm MPI_COMM_WORLD
int ex4()
{
    MPI_Init(NULL,NULL);

    const int N = 5;
    int rank, size;
    int a[N];
    int local_res[2];
    int result[2];

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            a[i] = rand();
            printf("%d ", a[i]);
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
    int* proc_part = new int[proc_num];

    MPI_Scatterv(a, sendcount, displs, MPI_INT, proc_part, proc_num, MPI_INT, 0, MPI_COMM_WORLD);

    local_res[0] = 0;
    local_res[1] = 0;

    for (int i = 0; i < proc_num; i++) {
        if (proc_part[i] > 0) {
            local_res[0] += proc_part[i];
            local_res[1]++;
        }
    }

    MPI_Reduce(&local_res, &result, 2, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Answer: %f", (double)result[0] / result[1]);
    }

    MPI_Finalize();
    return 0;
	}