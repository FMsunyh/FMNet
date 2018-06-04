#ifndef GEMM_H
#define GEMM_H


void gemm_bin(int M, int N, int K, float ALPHA,
	char  *A, int lda,
	float *B, int ldb,
	float *C, int ldc);

void gemm(int TA, int TB, int M, int N, int K, float ALPHA,
	float *A, int lda,
	float *B, int ldb,
	float BETA,
	float *C, int ldc);

/*
**  ���ܣ�������㣬���C = ALPHA * A * B + BETA * C��
**       �����CҲ�ǰ��д洢�������в���һ�У�
**  ���룺 A,B,C   �������һά�����ʽ�����д洢�������в���һ�У�
**        ALPHA   ϵ��
**        BETA    ϵ��
**        TA,TB   �Ƿ���Ҫ��A,B��ת�ò�������Ϊ1,��Ϊ0
**        M       A,C������
**        N       B,C������
**        K       A��������B������
**        lda     A������������ת�ã�������������ת�ã�
**        ldb     B������������ת�ã�������������ת�ã�
**        ldc     C������
**  ˵�����˺�������Cʵ�־���˷����㣬�ⲿ�ִ���Ӧ����ģ�µ�Caffe�е�math_functions.cpp�Ĵ���
**       �ο����ͣ�http://www.voidcn.com/blog/thy_2014/article/p-6149690.html
*/
void gemm_cpu(int TA, int TB, int M, int N, int K, float ALPHA,
	float *A, int lda,
	float *B, int ldb,
	float BETA,
	float *C, int ldc);


float *random_matrix(int rows, int cols);

#endif