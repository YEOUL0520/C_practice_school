/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.12.09
최종 수정일 : 2021.12.11
랜덤으로 생성된 수의 소수 여부를 판별하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_prime(int n);
void print_graph(int n);

int main(void)
{
	int number;
	srand((unsigned)time(NULL));

	number = rand() % 100 + 1;
	printf("%d\n", number);
	print_graph(number);
	
}
int is_prime(int n)
{
	int k;
	for (k = 2; k < n; k++)
	{
		if (n % k == 0)
			break;
	}
	if (n == k)
		return 1;
	else
		return 0;
}
void print_graph(int n)
{
	int count = 0;
	if (is_prime(n) == 1)
	{
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				count++;
				if (count == n)
				{
					printf("%3d  ", n);//그냥 %d한채로 할 경우 첫줄에 맞춰짐
				}
				else
					printf("  *  ");//그럴경우 *  (공백 두칸) 해주면 됨
			}
			printf("\n");
		}
		
	}
	else
	{
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
				printf("*  ");
			printf("\n");
		}
	}
}
