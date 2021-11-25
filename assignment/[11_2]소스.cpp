/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.23
정수로 범위를 입력 받아 랜덤한 10개의 수를 가진 배열을 생성한 후,
오름차순 및 내림차순으로 이를 정렬하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void Assending(int array[]);
void Descending(int array[]);

int main(void)
{
	srand(time(NULL));
	int list[SIZE] = { 0 };
	int a, b, max, min, choice = 0;

	while (1)
	{
		printf("난수를 생성할 범위를 정하시오 : ");
		scanf("%d %d", &a, &b);
		//입력한 정수가 음수일 경우 다시 입력받음
		if (a < 0 || b < 0)
			printf("정수 값을 입력해 주세요.\n\n");
		else
			break;
	}
	//입력한 두 값 중 어느 것이 큰 값이고 어느 값이 작은 값인지 판별
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	//입력한 정수의 범위에 맞게 랜덤한 수 10개를 출력하고, list에 담기
	for (int i = 0; i < 10; i++)
		list[i] = rand() % ((max - min) + 1) + min;

	printf("생성된 배열 : ");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);
	printf("\n1. 오름차순 2. 내림차순 ");
	scanf("%d", &choice);

	if (choice == 1)
	{
		Assending(list);
		printf("오름차순으로 정리한 배열 :\n");
		for (int i = 0; i < 10; i++)
			printf("%d ", list[i]);
	}
	else if (choice == 2)
	{
		Descending(list);
		printf("내림차순으로 정리한 배열 :\n");
		for (int i = 0; i < 10; i++)
			printf("%d ", list[i]);
	}

}
//오름차순으로 정렬하는 함수
void Assending(int array[])
{
	int min, temp;

	for (int x = 0; x < 9; x++)
	{
		min = x;
		for (int y = x + 1; y < 10; y++)
			if (array[y] < array[min])
				min = y;
		temp = array[x];
		array[x] = array[min];
		array[min] = temp;

	}
}
//내림차순으로 정렬하는 함수
void Descending(int array[])
{
	int max, temp;

	for (int x = 0; x < 9; x++)
	{
		max = x;
		for (int y = x + 1; y < 10; y++)
			if (array[y] > array[max])
				max = y;
		temp = array[x];
		array[x] = array[max];
		array[max] = temp;

	}
}