#include "gemm.h"
#include <stdio.h>
#include <string.h>
#include "utils.h"

int gpu_index = 0;
int main(int argc, char **argv)
{
	//test_gemm_nn();
	//test_gemm_tn();
	print_arg(argc, argv);

	gpu_index = find_int_arg(argc, argv, "-i", 0);
	print_arg(argc, argv);

	float thresh = find_float_arg(argc, argv, "-thresh", .2);
	print_arg(argc, argv);
	//if (argc < 2) {
	//	fprintf(stderr, "usage: %s <function>\n", argv[0]);
	//	return 0;
	//}

	//return 0;

	test();
}