/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.11.02
수의 범위를 입력받아 랜덤으로 두 수를 뽑고,
뽑은 두 수의 최대공약수를 구하는 프로그램
------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void gcd(int n1, int n2);

int main(void)
{
	int a, b, x, y;

	while (1)
	{
		printf("랜덤으로 뽑을 두 자연수의 범위를 입력해주세요: ");
		scanf("%d %d", &a, &b);
		
		//입력 값이 2 이상의 자연수가 아닐 경우 값을 다시 입력받음
		if (a < 2)
		{
			printf("첫 번째 입력 값이 2 이상의 자연수가 아닙니다.\n");
			
			if (b < 2)
				printf("두 번째 입력 값이 2 이상의 자연수가 아닙니다.\n");
			
			printf("\n");

			continue;
		}
		else
			if (b < 2)
			{
				printf("두 번째 입력 값이 2 이상의 자연수가 아닙니다.\n");
				printf("\n");
				continue;
			}
		
		//입력된 두 수의 차이가 3 미만일 경우 값을 다시 입력받음
		if ((b - a) < 3)
		{
			printf("입력된 두 수의 차이가 3 미만입니다.\n");
			printf("\n");
		}
		else
			break;
	}

	//입력 범위 중 랜덤으로 두 수 출력
	srand(time(NULL));
	x = rand() % (b - a) + a;
	y = rand() % (b - a) + a;
	printf("선택된 두 수는 %d와 %d입니다.\n", x, y);

	printf("%d와 %d의 ", x, y);
	gcd(x, y);
	return 0;
}

//최대 공약수 계산 함수(GCD)
void gcd(int n1, int n2)
{
	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}
	printf("최대 공약수: %d\n", n1);
}