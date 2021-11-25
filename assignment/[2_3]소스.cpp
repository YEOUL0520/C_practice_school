/*--------------
작성자 : 류효정
날짜 : 21.09.16
[1,6] 범위의 정수를 선택해 수열을 산출하는 프로그램
--------------*/
#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, f;

	printf("[1, 6] 범위의 정수를 하나 선택하시오: ");
	scanf("%d", &a);

	b = (a * 5) % 7;
	c = (b * 5) % 7;
	d = (c * 5) % 7;
	e = (d * 5) % 7;
	f = (e * 5) % 7;

	printf("%d %d %d %d %d %d", a, b, c, d, e, f);

	return 0;
}