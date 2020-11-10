//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include "mpi.h"
//
//#define comm MPI_COMM_WORLD
//int main(int argc, char** argv)
//{
//    int ProcRank, ProcNum;
//    const int size = 15;
//    int x[size];
//    int max;
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(comm, &ProcNum);
//    MPI_Comm_rank(comm, &ProcRank);
//    
//    if (ProcRank == 0)
//        for (int i = 0; i < size; i++)
//        {
//            x[i] = rand();
//            printf(" %d, ", x[i]);
//        }
//
//    MPI_Bcast(x, size, MPI_INT, 0, comm);
//    
//    int k = size / ProcNum;
//    int i1 = k * ProcRank;
//    int i2 = k * (ProcRank+1);
//    if (ProcRank == ProcNum-1)
//    {
//        i2 = size;
//    }
//    //printf("%d-%d\n", i1, i2);
//    int localmax = 0;
//    for (int i = i1; i < i2; i++)
//    {
//        if (localmax < x[i])
//        {
//            localmax = x[i];
//        }
//    }
//
//    MPI_Reduce(&localmax, &max, 1, MPI_INT, MPI_MAX, 0, comm);
//
//    if (ProcRank == 0)
//        printf("\n max = %d \n", max);
//
//    MPI_Finalize();
//    return 0;
//}