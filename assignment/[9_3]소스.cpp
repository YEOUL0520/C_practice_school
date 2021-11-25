/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.08
0 이상인 실수를 double형으로 입력받아 2진수로 변환하는 프로그램
----------------------------------------------------------------*/

#include <stdio.h>

void binary_change1(int x);//정수부분을 변환해주는 함수
void binary_change2(double x);//소수부분을 변환해주는 함수

int main(void)
{
	double number, y;
	int x;

	printf("음이 아닌 실수를 입력하시오:\n");
	scanf("%lf", &number);

	x = (int)number;//입력받은 실수 중 정수 부분
	y = number - x;//입력받은 실수 중 소수 부분

	printf("2진수 표현: ");
	binary_change1(x);
	printf(".");
	binary_change2(y);

	return 0;
}

void binary_change1(int x)//정수 부분(int로 지정)을 변환해주는 함수
{
	if (x > 0)
	{
		binary_change1(x / 2);
		printf("%d", x % 2);
	}
	return;
}

void binary_change2(double x)//소수 부분(double로 지정)을 변환해주는 함수
{
	double k;
	k = x * 2;

	if (k < 1)
	{
		printf("0");
		binary_change2(k);
	}
	else if (k > 1)
	{
		printf("1");
		binary_change2(k - 1);
	}
	else
	{
		printf("1");
		return;
	}

}

