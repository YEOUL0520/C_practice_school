/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.10.06
삼각형의 세 변을 입력받아 각의 크기에 따른 삼각형의 종류를 판별하는 프로그램
------------------------*/
#include <stdio.h>

int main(void)
{
	int a, b, c;
	int x, y, z;

	printf("삼각형의 세 변을 입력하시오:");
	scanf("%d %d %d", &a, &b, &c);

	//배열을 사용할 수 없으므로 가정법을 사용해 입력받은 각각의 변 a,b,c를 크기 순으로 재배열(x,y,z)한다.
	if (a >= b)
	{
		if (a >= c)
		{
			if (b >= c)
				x = a, y = b, z = c;

			else
				x = a, y = c, z = b;

		}

		else
			x = c, y = a, z = b;

	}
	else
	{
		if (b >= c)
		{
			if (a >= c)
				x = b, y = a, z = c;

			else
				x = b, y = c, z = a;
		}

		else
			x = c, y = b, z = a;
	}

	//가장 긴 변의 길이가 나머지 두 변의 길이의 합보다 크면 삼각형이 될 수 없다.
	if (x > y + z)
		printf("올바르지 않은 삼각형입니다.");

	//삼각형이 만들어지는 경우, 예각/직각/둔각 삼각형 중 하나가 된다.
	else
	{
		if (x * x > y * y + z * z)
			printf("둔각삼각형입니다.");

		else if (x * x == y * y + z * z)
			printf("직각삼각형입니다.");

		else
			printf("예각삼각형입니다.");

	}



	return 0;
}