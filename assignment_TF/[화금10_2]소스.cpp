/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.12.11
입력 받은 문자열의 길이를 출력하고,
이를 대문자와 소문자로 구분지어 출력하며,
각각의 문자열을 전부 대문자와 소문자로 바꾸어 출력한 후
처음 입력받은 문자열을 소문자로 바꾸어 오름차순으로 정렬하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

int main(void)
{
	char list[SIZE] = { 0 };
	int sum = 0;

	srand((unsigned)time(NULL));

	printf("생성된 길이가 30인 문자열 : ");

	for (int i = 0; i < SIZE; i++)
	{
		list[i] = rand() % 122 + 1;
		while (list[i]<48 || 57<list[i]<97 || list[i]>122)
		{
			list[i] = rand() % 122 + 1;
		}
		printf("%c", list[i]);
	}

	printf("\n문자열 안에 포함된 숫자들의 총합 : ");
	for (int i = 0; i < SIZE; i++)
	{
		if (48 <= list[i] <= 57)
		{
			sum += list[i];
		}
	}
	printf("%d", sum);

	return 0;
}