/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.09.30
int형 양의 정수를 입력받아 64-bit 16진수 형식으로 표시하는 프로그램
------------------------*/

#include <stdio.h>

int main()
{
	unsigned int A, B;
	unsigned int A_upper, A_lower, B_upper, B_lower;
	unsigned int C_upper, C_lower;
	unsigned int D_upper, D_lower;
	unsigned int E;

	//int형 양의 정수 2개를 입력받는다.
	printf("int형 두 정수를 입력하시오:");
	scanf("%d %d", &A, &B);

	//곱셈 연산 시 32bit를 넘지 않도록 형변환해준다.
	A_upper = A >> 16;
	A_lower = A & 0xFFFF;

	B_upper = B >> 16;
	B_lower = B & 0xFFFF;  

	C_upper = (A_upper * B_lower + A_lower * B_upper) >> 16;
	C_lower = (A_upper * B_lower + A_lower * B_upper) & 0xffff;

	//D_lower에서 자릿수 넘는 값 계산(E)한 이후 D_upper로 넘겨준다.
	E = (C_lower >> 15) & (A_lower * B_lower >> 31);
	D_upper = (A_upper * B_upper) + C_upper + E;
	D_lower = (C_lower << 16) + (A_lower * B_lower);


	printf("(int)A * (int)B = OX%08X%08X\n", D_upper, D_lower);
	printf("(long long)A * (long long)B = OX%016llX\n", (long long)A * B);
	printf("(long long)A * (long long)B = %lld\n", (long long)A * B);

	return 0;
}




