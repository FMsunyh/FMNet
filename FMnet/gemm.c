#include <stdlib.h>
#include <stdio.h>
#include "gemm.h"

void gemm_bin(int M, int N, int K, float ALPHA, char *A, int lda, float *B, int ldb, float *C, int ldc)
{

}

void gemm(int TA, int TB, int M, int N, int K, float ALPHA, float *A, int lda, float *B, int ldb, float BETA, float *C, int ldc)
{
	gemm_cpu(TA, TB, M, N, K, ALPHA, A, lda, B, ldb, BETA, C, ldc);
}

/*
 *	C = ALPHA * A * B + C æÿ’Ûº∆À„
 */
void gemm_nn(int M, int N, int K, float ALPHA,
	float *A, int lda,
	float *B, int ldb,
	float *C, int ldc)
{
	int i, j, k;
	//loop A
	for (i = 0; i < M; ++i)
	{
		for (k = 0; k < K; ++k)
		{
			register float	A_PART = ALPHA * A[i*lda + k];
			for (j = 0; j < N; ++j)
			{
				C[i*ldc + j] += A_PART*B[k*ldb + j];
			}
		}
	}
}

void gemm_nt(int M, int N, int K, float ALPHA,
	float *A, int lda,
	float *B, int ldb,
	float *C, int ldc)
{
	int i, j, k;
	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			register float sum = 0;
			for (k = 0; k < K; ++k)
			{
				sum += ALPHA*A[i*lda + k] * B[j*ldb + k];
			}

			C[i*ldc + j] += sum;
		}
	}
}

void gemm_tn(int M, int N, int K, float ALPHA,
	float *A, int lda,
	float *B, int ldb,
	float *C, int ldc)
{
	int i, j, k;
	for (i=0; i<M; ++i)
	{
		for (k=0; k<K; ++k)
		{
			register float A_PART = ALPHA*A[k*lda + i];
			for (j=0; j<N; ++j)
			{
				C[i*ldc + j] += A_PART*B[k*ldb + j];
			}
		}
	}
}

void gemm_tt(int M, int N, int K, float ALPHA,
	float *A, int lda,
	float *B, int ldb,
	float *C, int ldc)
{
	int i, j, k;
	for (i = 0; i < M; ++i) {
		for (j = 0; j < N; ++j) {
			register float sum = 0;
			for (k = 0; k < K; ++k) {
				sum += ALPHA*A[i + k*lda] * B[k + j*ldb];
			}
			C[i*ldc + j] += sum;
		}
	}
}

void gemm_cpu(int TA, int TB, int M, int N, int K, float ALPHA, float *A, int lda, float *B, int ldb, float BETA, float *C, int ldc)
{
	int i, j;
	for (i = 0; i < M; ++i) {
		for (j = 0; j < N; ++j) {
			C[i*ldc + j] *= BETA;
		}
	}
	if (!TA && !TB)
		gemm_nn(M, N, K, ALPHA, A, lda, B, ldb, C, ldc);
	else if (TA && !TB)
		gemm_tn(M, N, K, ALPHA, A, lda, B, ldb, C, ldc);
	else if (!TA && TB)
		gemm_nt(M, N, K, ALPHA, A, lda, B, ldb, C, ldc);
	else
		gemm_tt(M, N, K, ALPHA, A, lda, B, ldb, C, ldc);
}


float * random_matrix(int rows, int cols)
{
	int i;
	float *m = (float*)calloc(rows*cols, sizeof(float));
	for (i = 0; i < rows*cols; ++i) {
		m[i] = (float)rand() / RAND_MAX;
	}
	return m;
}


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
	float A[4] = { 2,3,1,5 };
	float B[6] = { 1,3,1,2,4,2 };
	float C[6] = { 1,1,1,1,1,1 };
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