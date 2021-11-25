/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.10
������ ������ ������ �� ��İ� �� ���� ����ϰ�,
�� ������� �� ��� ���� ����� ����ϴ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 3
int arr_plus[ROWS][COLS];
void Plus_Matrix(int arr1[][3], int arr2[][3]);

int main(void)
{
	int arr1[ROWS][COLS];
	int arr2[ROWS][COLS];

	int a, b;

	srand((unsigned)time(NULL));//����ɶ����� ���� ����

	//�������� ������ ������ ���� ���arr1�� arr2�� �����Ѵ�.
	for (a = 0; a < ROWS; a++)
		for (b = 0; b < COLS; b++)
			arr1[a][b] = (rand() % 45) + 1;

	for (a = 0; a < ROWS; a++)
		for (b = 0; b < COLS; b++)
			arr2[a][b] = (rand() % 45) + 1;

	//������ �� ����� ����Ѵ�.
	printf("A =\n");
	for (a = 0; a < ROWS; a++)
	{
		for (b = 0; b < COLS; b++)
			printf("%3d", arr1[a][b]);
		printf("\n");
	}
	printf("\n");
	printf("B =\n");
	for (a = 0; a < ROWS; a++)
	{
		for (b = 0; b < COLS; b++)
			printf("%3d", arr2[a][b]);
		printf("\n");
	}
	printf("\n");

	Plus_Matrix(arr1, arr2);
	printf("\n");

	int i, j;
	float average_c, average_r;

	//�� ����� �ε��� ���� ���� ����� ���
	printf("A+B �� ����� ���\n");
	for (i = 0; i <= 2; i++)
	{
		average_c = 0;
		for (j = 0; j <= 2; j++)
			average_c += (float)arr_plus[i][j] / 3;
		printf("%d���� ���: %.2f\n", i + 1, average_c);
	}

	//�� ������ �ε��� ���� ���� ����� ���
	printf("A+B �� ������ ���\n");
	for (j = 0; j <= 2; j++)
	{
		average_r = 0;
		for (i = 0; i <= 2; i++)
			average_r += (float)arr_plus[i][j] / 3;
		printf("%d���� ���: %.2f\n", j + 1, average_r);
	}

	return 0;

}
void Plus_Matrix(int arr1[3][3], int arr2[3][3])//�� ����� ���� ���ϴ� �Լ�
{
	int x, y;
	//����� ���� ���Ѵ�.
	for (x = 0; x < ROWS; x++)
		for (y = 0; y < COLS; y++)
			arr_plus[x][y] = arr1[x][y] + arr2[x][y];
	printf("A + B =\n");
	//������ ���� ����Ѵ�.
	for (x = 0; x < ROWS; x++)
	{
		for (y = 0; y < COLS; y++)
			printf("%3d", arr_plus[x][y]);
		printf("\n");
	}
}