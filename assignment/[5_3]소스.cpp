/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.10.07
수식을 입력하면 결과를 산출하는 프로그램
------------------------*/
#include <stdio.h>

int main(void)
{
	int A, B;
	char a, b;

	printf("수식을 입력하시오 (예: 2 + 5):");
	scanf("%d %c%c %d", &A, &a, &b, &B);

	if (a == '+')
		printf("%d + %d = %d", A, B, (A + B));
	else if (a == '-')
		printf("%d - %d = %d", A, B, (A - B));
	else if (a == '*')
		printf("%d * %d = %d", A, B, (A * B));
	else if (a == '/')
		printf("%d / %d = %d", A, B, (A / B));
	else if (a == '%')
		printf("%d % %d = %d", A, B, (A % B));

	/*>> , << 연산자의 경우 
	하나의 char에 두 개의 값을 받을 수 없으므로 
	두 개의 char을 사용*/ 

	else if (a == '>' && b == '>')
		printf("%d >> %d = %d", A, B, (A >> B));
	else if (a == '<' && b == '<')
		printf("%d << %d = %d", A, B, (A << B));

	else if (a == '#')
		if (B < 2) //B의 값이 무엇인지에 따라 밀어야 하는 A의 bit자릿수가 달라짐
		{
			if (A == B || (A >> 1) == B || (A >> 2) == B || (A >> 3) == B || (A >> 4) == B || (A >> 5) == B || (A >> 6) == B || (A >> 7) == B || (A >> 8) == B)
				printf("%d # %d = matching pattern found", A, B);
			else
				printf("%d # %d = no matching pattern", A, B);
		}

		else if (B < 4)
		{
			if (((A & 3) == B) || (((A >> 1) & 3) == B) || (((A >> 2) & 3) == B) || (((A >> 3) & 3) == B) || (((A >> 4) & 3) == B) || (((A >> 5) & 3) == B) || (((A >> 6) & 3) == B) || (((A >> 7) & 3) == B))
				printf("%d # %d = matching pattern found", A, B);
			else
				printf("%d # %d = no matching pattern", A, B);
		}
		else if (B < 8)
		{
			if (((A & 7) == B) || (((A >> 1) & 7) == B) || (((A >> 2) & 7) == B) || (((A >> 3) & 7) == B) || (((A >> 4) & 7) == B) || (((A >> 5) & 7) == B) || (((A >> 6) & 7) == B))
				printf("%d # %d = matching pattern found", A, B);
			else
				printf("%d # %d = no matching pattern", A, B);
		}
		else if (B < 16)
		{
			if (((A & 15) == B) || (((A >> 1) & 15) == B) || (((A >> 2) & 15) == B) || (((A >> 3) & 15) == B) || (((A >> 4) & 15) == B) || (((A >> 5) & 15) == B))
				printf("%d # %d = matching pattern found", A, B);
			else
				printf("%d # %d = no matching pattern", A, B);
		}
		else if (B < 32)
		{
			if (((A & 31) == B) || (((A >> 1) & 31) == B) || (((A >> 2) & 31) == B) || (((A >> 3) & 31) == B))
				printf("%d # %d = matching pattern found", A, B);
			else
				printf("%d # %d = no matching pattern", A, B);
		}
		else if (B < 64)
		{
			if (((A & 63) == B) || (((A >> 1) & 63) == B) || (((A >> 2) & 63) == B))
				printf("%d # %d = matching pattern found", A, B);
			else
				printf("%d # %d = no matching pattern", A, B);
		}
		else if (B < 128)
		{
			if (((A & 127) == B) || (((A >> 1) & 127) == B))
				printf("%d # %d = matching pattern found", A, B);
			else
				printf("%d # %d = no matching pattern", A, B);
		}
		else if (B < 256)
		{
			if ((A & 255) == B)
				printf("%d # %d = matching pattern found", A, B);
			else
				printf("%d # %d = no matching pattern", A, B);
		}


	return 0;


}


