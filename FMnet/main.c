#include "gemm.h"
#include <stdio.h>


void test_random_matrix()
{
	float *m = random_matrix(2, 2);
	for (int i = 0; i < 4; ++i)
	{
		printf("%f ", m[i]);
	}

	printf("\n");
}


void test_gemm_nn()
{
	float A[4] = { 2,3,1,5 };
	float B[6] = { 1,3,1,2,4,2 };
	float C[6] = { 1,1,1,1,1,1 };
	gemm_cpu(0, 0, 2, 3, 2, 1, A, 2, B, 3, 1, C, 3);

	int i = 0;
	for (i = 0; i < 6; ++i)
	{
		printf("%f ", C[i]);
	}

	printf("\n");
}


void test_gemm_tn()
{
	float A[4] = { 2,3,1,5};
	float B[6] = { 1,3,1,2,4,2};
	float C[6] = { 1,1,1,1,1,1};
	gemm_cpu(1, 0, 2, 3, 2, 1, A, 2, B, 3, 1, C, 3);

	int i = 0;
	for (i = 0; i < 6; ++i)
	{
		printf("%f ", C[i]);
	}

	printf("\n");
}


void test_gemm_nt()
{
	float A[4] = { 2,3,1,5 };
	float B[6] = { 1,3,1,2,4,2 };
	float C[6] = { 1,1,1,1,1,1 };
	gemm_cpu(0, 0, 2, 3, 2, 1, A, 2, B, 3, 1, C, 3);

	int i = 0;
	for (i = 0; i < 6; ++i)
	{
		printf("%f ", C[i]);
	}

	printf("\n");
}


int main()
{
	//test_gemm_nn();
	test_gemm_tn();
	return 0;
}