#include <stdlib.h>

void gemm_bin(int M, int N, int K, float ALPHA, char *A, int lda, float *B, int ldb, float *C, int ldc)
{

}

void gemm(int TA, int TB, int M, int N, int K, float ALPHA, float *A, int lda, float *B, int ldb, float BETA, float *C, int ldc)
{

}

void gemm_cpu(int TA, int TB, int M, int N, int K, float ALPHA, float *A, int lda, float *B, int ldb, float BETA, float *C, int ldc)
{

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

