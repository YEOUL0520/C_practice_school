/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.16
�� ���(3*3)�� �Է¹ް�, �� �հ� ���� �����ϴ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
#define ROWS 3
#define COLS 3

int main(void)
{
	int A[ROWS][COLS];
	int r_a, c_a;
	printf("ù ��° 3*3 ����� �Է��Ͻÿ� : ");
	for (r_a = 0; r_a < ROWS; r_a++)
		for (c_a = 0; c_a < COLS; c_a++)
			scanf("%d", &A[r_a][c_a]);

	int B[ROWS][COLS];
	int r_b, c_b;
	printf("�� ��° 3*3 ����� �Է��Ͻÿ� : ");
	for (r_b = 0; r_b < ROWS; r_b++)
		for (c_b = 0; c_b < COLS; c_b++)
			scanf("%d", &B[r_b][c_b]);

	int C[ROWS][COLS];
	int D[ROWS][COLS];

	//����� �� ���
	int r_c, c_c;

	for (r_c = 0; r_c < ROWS; r_c++)
		for (c_c = 0; c_c < COLS; c_c++)
			C[r_c][c_c] = A[r_c][c_c] + B[r_c][c_c];

	//����� �� ���
	int r_d, c_d, x;

	for (r_d = 0; r_d < ROWS; r_d++)
		for (c_d = 0; c_d < COLS; c_d++)
		{
			D[r_d][c_d] = 0;//�ʱ�ȭ �ʼ�
			for (x = 0; x < 3; x++)
				D[r_d][c_d] += A[r_d][x] * B[x][c_d];
		}

	//����� �� ����
	printf("\n");
	printf("A+B=\n");
	for (r_c = 0; r_c < ROWS; r_c++)
	{
		for (c_c = 0; c_c < COLS; c_c++)
			printf("%d ", C[r_c][c_c]);
		printf("\n");
	}
	printf("\n");

	//����� �� ����
	printf("A*B=\n");
	for (r_d = 0; r_d < ROWS; r_d++)
	{
		for (c_d = 0; c_d < COLS; c_d++)
			printf("%d ", D[r_d][c_d]);
		printf("\n");
	}

	return 0;
}