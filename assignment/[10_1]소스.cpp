/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.10
랜덤한 정수로 구성된 두 행렬과 그 합을 출력하고,
그 결과값의 각 행과 열의 평균을 출력하는 프로그램
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

	srand((unsigned)time(NULL));//실행될때마다 난수 변경

	//랜덤으로 생성된 난수를 통해 행렬arr1과 arr2를 구성한다.
	for (a = 0; a < ROWS; a++)
		for (b = 0; b < COLS; b++)
			arr1[a][b] = (rand() % 45) + 1;

	for (a = 0; a < ROWS; a++)
		for (b = 0; b < COLS; b++)
			arr2[a][b] = (rand() % 45) + 1;

	//구성된 두 행렬을 출력한다.
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

	//각 행들의 인덱스 값을 더해 평균을 출력
	printf("A+B 각 행들의 평균\n");
	for (i = 0; i <= 2; i++)
	{
		average_c = 0;
		for (j = 0; j <= 2; j++)
			average_c += (float)arr_plus[i][j] / 3;
		printf("%d행의 평균: %.2f\n", i + 1, average_c);
	}

	//각 열들의 인덱스 값을 더해 평균을 출력
	printf("A+B 각 열들의 평균\n");
	for (j = 0; j <= 2; j++)
	{
		average_r = 0;
		for (i = 0; i <= 2; i++)
			average_r += (float)arr_plus[i][j] / 3;
		printf("%d열의 평균: %.2f\n", j + 1, average_r);
	}

	return 0;

}
void Plus_Matrix(int arr1[3][3], int arr2[3][3])//두 행렬의 합을 구하는 함수
{
	int x, y;
	//행렬의 합을 구한다.
	for (x = 0; x < ROWS; x++)
		for (y = 0; y < COLS; y++)
			arr_plus[x][y] = arr1[x][y] + arr2[x][y];
	printf("A + B =\n");
	//구해진 합을 출력한다.
	for (x = 0; x < ROWS; x++)
	{
		for (y = 0; y < COLS; y++)
			printf("%3d", arr_plus[x][y]);
		printf("\n");
	}
}