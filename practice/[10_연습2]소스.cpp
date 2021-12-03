/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.16
두 행렬(3*3)을 입력받고, 그 합과 곱을 산출하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#define ROWS 3
#define COLS 3

int main(void)
{
	int A[ROWS][COLS];
	int r_a, c_a;
	printf("첫 번째 3*3 행렬을 입력하시오 : ");
	for (r_a = 0; r_a < ROWS; r_a++)
		for (c_a = 0; c_a < COLS; c_a++)
			scanf("%d", &A[r_a][c_a]);

	int B[ROWS][COLS];
	int r_b, c_b;
	printf("두 번째 3*3 행렬을 입력하시오 : ");
	for (r_b = 0; r_b < ROWS; r_b++)
		for (c_b = 0; c_b < COLS; c_b++)
			scanf("%d", &B[r_b][c_b]);

	int C[ROWS][COLS];
	int D[ROWS][COLS];

	//행렬의 합 계산
	int r_c, c_c;

	for (r_c = 0; r_c < ROWS; r_c++)
		for (c_c = 0; c_c < COLS; c_c++)
			C[r_c][c_c] = A[r_c][c_c] + B[r_c][c_c];

	//행렬의 곱 계산
	int r_d, c_d, x;

	for (r_d = 0; r_d < ROWS; r_d++)
		for (c_d = 0; c_d < COLS; c_d++)
		{
			D[r_d][c_d] = 0;//초기화 필수
			for (x = 0; x < 3; x++)
				D[r_d][c_d] += A[r_d][x] * B[x][c_d];
		}

	//행렬의 합 산출
	printf("\n");
	printf("A+B=\n");
	for (r_c = 0; r_c < ROWS; r_c++)
	{
		for (c_c = 0; c_c < COLS; c_c++)
			printf("%d ", C[r_c][c_c]);
		printf("\n");
	}
	printf("\n");

	//행렬의 곱 산출
	printf("A*B=\n");
	for (r_d = 0; r_d < ROWS; r_d++)
	{
		for (c_d = 0; c_d < COLS; c_d++)
			printf("%d ", D[r_d][c_d]);
		printf("\n");
	}

	return 0;
}