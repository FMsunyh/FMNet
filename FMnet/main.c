#include "gemm.h"
#include <stdio.h>

int main()
{
	float *m = random_matrix(2, 2);
	for (int i = 0; i < 4; ++i)
	{
		printf("%f ", m[i]);
	}

	printf("\n");
	return 0;
}