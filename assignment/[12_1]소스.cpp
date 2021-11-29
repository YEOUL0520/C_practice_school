/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.24
입력 받은 문자열의 길이를 출력하고,
이를 대문자와 소문자로 구분지어 출력하며,
각각의 문자열을 전부 대문자와 소문자로 바꾸어 출력한 후
처음 입력받은 문자열을 소문자로 바꾸어 오름차순으로 정렬하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lower_char(char a[]);
void upper_char(char a[]);
void print_lower(char a[]);
void print_upper(char a[]);
int selection_sort_char(char* a);

int length;//문자열의 길이를 전역 변수로 지정

int main(void)
{
	char list[100];
	printf("----------문자 변환 프로그램----------\n");
	printf("문자열을 입력하세요 : ");
	gets_s(list, 100);//gets_s함수를 통해 문자열을 입력받음
	printf("문자열 길이 : ");
	printf("%d\n", strlen(list));//strlen함수를 사용해 문자열의 길이를 출력함
	length = strlen(list);

	printf("소문자 모음 : ");
	lower_char(list);
	printf("\n대문자 모음 : ");
	upper_char(list);
	printf("\n대문자로 출력 : ");
	print_upper(list);
	printf("\n소문자로 출력 : ");
	print_lower(list);
	printf("\n오름차순으로 정렬된 문자열: ");
	selection_sort_char(list);
	print_lower(list);
	printf("\n--------------------------------------\n");

	return 0;
}
void lower_char(char a[])//islower을 이용해 문자열 중 소문자만 출력하는 함수
{
	for (int i = 0; a[i] != NULL; i++)
	{
		if (islower(a[i]))//해당 배열의 값이 대문자이면
		{
			printf("%c ", a[i]);//이를 출력함
		}
	}
}
void upper_char(char a[])//isupper을 이용해 문자열 중 대문자만 출력하는 함수
{
	for (int i = 0; a[i] != NULL; i++)
	{
		if (isupper(a[i]))//해당 배열의 값이 대문자이면
		{
			printf("%c ", a[i]);//이를 출력함
		}
	}
}
void print_lower(char a[])//isupper과 tolower을 이용해 대문자를 소문자로 바꾸는 함수
{
	for (int i = 0; a[i] != NULL; i++)
	{
		if (isupper(a[i]))//해당 배열의 값이 대문자이면
			a[i] = tolower(a[i]);//대문자를 소문자로 변경하고

		printf("%c", a[i]);//이를 출력함
	}
}
void print_upper(char a[])//islower과 toupper을 이용해 소문자를 대문자로 바꾸는 함수
{
	for (int i = 0; a[i] != NULL; i++)
	{
		if (islower(a[i]))//해당 배열의 값이 소문자이면
			a[i] = toupper(a[i]);//소문자를 대문자로 변경하고

		printf("%c", a[i]);//이를 출력함
	}
}
int selection_sort_char(char* a)//문자를 오름차순으로 정렬하는 함수
{
	int low;
	char temp;

	for (int x = 0; x < (length - 1); x++)
	{
		low = x;
		for (int y = x + 1; y < length; y++)
		{
			if (a[y] < a[low])
				low = y;
		}

		if (x != low)
		{
			temp = a[x];
			a[x] = a[low];
			a[low] = temp;
		}

	}

	return 0;
}