//
//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <cmath>
//#include <time.h>
//#define comm MPI_COMM_WORLD
//
//int main(int argc, char* argv[]) {
//	
//	int totalCount = 1000000;
//	int circleCount = 0;
//	double x, y;
//	int rank, num;
//	
//	MPI_Init(&argc, &argv);
//	MPI_Comm_rank(comm, &rank);
//	MPI_Comm_size(comm, &num);
//	
//	int localCircleCount = 0;
//	int k = totalCount / num;
//	int i1 = k * rank;
//	int i2 = k * (rank+1);
//	if (rank == num-1) i2 = totalCount;
//	
//	for (int i = i1; i < i2; i++)
//	{
//		x = (double)rand() / (double)RAND_MAX * 2 - 1;
//		y = (double)rand() / (double)RAND_MAX * 2 - 1;
//		if (pow(x, 2) + pow(y, 2) <= 1)
//			localCircleCount++;
//	}
//
//	MPI_Reduce(&localCircleCount, &circleCount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
//
//	if (rank == 0)
//	{
//		double answer = (4 * (double)circleCount) / (double)totalCount;
//		printf("Pi = %f", answer);
//	}
//
//	MPI_Finalize();
//
//}