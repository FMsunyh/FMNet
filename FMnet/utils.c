#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void del_arg(int argc, char **argv, int index)
{
	int i;
	for (i = index; i < argc - 1; ++i)
	{
		argv[i] = argv[i + 1];
	}
	argv[i] = 0;
}

int find_int_arg(int argc, char ** argv, char * arg, int def)
{
	int i;
	for (i = 0; i < argc - 1; ++i) {
		if (!argv[i]) continue;
		if (0 == strcmp(argv[i], arg)) {
			def = atoi(argv[i + 1]);
			del_arg(argc, argv, i);
			del_arg(argc, argv, i);
			break;
		}
	}

	return def;
}

float find_float_arg(int argc, char ** argv, char * arg, float def)
{
	int i;
	for (i = 0; i < argc - 1; ++i)
	{
		if (!argv[i]) continue;
		if (0 == strcmp(argv[i], arg))
		{
			def = atof(argv[i + 1]);
			del_arg(argc, argv, i);
			del_arg(argc, argv, i);
			break;
		}
	}
	return def;
}

int find_arg(int argc, char * argv[], char * arg)
{
	int i;
	for (i = 0; i < argc; ++i)
	{
		if (!argv[i]) continue;
		if (0 == strcmp(argv[i], arg))
		{
			del_arg(argc, argv, i);
			return 1;
		}
	}

	return 0;
}

char * find_char_arg(int argc, char ** argv, char * arg, char * def)
{
	int i;
	for (i = 0; i < argc; ++i)
	{
		if (!argv[i]) continue;
		if (0 == strcmp(argv[i], arg))
		{
			def = argv[i + 1];
			del_arg(argc, argv, i);
			del_arg(argc, argv, i);
			break;
		}
	}
	return def;
}

void print_arg(int argc, char **argv)
{
	int i;
	for (i = 0; i < argc - 1; ++i)
	{
		fprintf(stdout, "%s ", argv[i]);
	}
}

void test_atoi()
{
	int val;
	char str[20];
	strcpy(str, "1999");
	val = atoi(str);
	printf("str = %s int = %d\n", str, val);


	strcpy(str, "eddy");
	val = atoi(str);
	printf("str = %s int = %d\n", str, val);
}

void test()
{
	test_atoi();
}