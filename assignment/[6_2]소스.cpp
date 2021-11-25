/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.10.17
1 이상의 정수를 입력 받아 피라미드를 생성하는 프로그램
------------------------*/
#include <stdio.h>

int main(void) 
{ 
	int a;
	int b;
	int c;
	int num;

	printf("출력하고 싶은 피라미드의 층수 입력 : ");
	scanf("%d", &num);

	if (1 <= num && num <= 20)
		for (a = 0; a < num; a++)
		{
			for (b = a; b <= num - 1; b++)
			{
				printf("   ");
			}
			for (c = 0; c <= (a * 2); c++)
			{
				printf("%3d", c + 1); //정수에 대해 3칸의 너비로 출력. 즉, 1자리 수의 경우 앞에 1칸의 공백이, 2자리 수의 경우 앞에 1칸의 공백이 발생.
			}
			printf("\n");
		}
	else
		printf("허용된 입력을 벗어났습니다.");

	return 0; 
}