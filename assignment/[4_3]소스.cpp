/*----------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.09.30
int�� ���� ������ �Է¹޾� 64-bit 16���� �������� ǥ���ϴ� ���α׷�
------------------------*/

#include <stdio.h>

int main()
{
	unsigned int A, B;
	unsigned int A_upper, A_lower, B_upper, B_lower;
	unsigned int C_upper, C_lower;
	unsigned int D_upper, D_lower;
	unsigned int E;

	//int�� ���� ���� 2���� �Է¹޴´�.
	printf("int�� �� ������ �Է��Ͻÿ�:");
	scanf("%d %d", &A, &B);

	//���� ���� �� 32bit�� ���� �ʵ��� ����ȯ���ش�.
	A_upper = A >> 16;
	A_lower = A & 0xFFFF;

	B_upper = B >> 16;
	B_lower = B & 0xFFFF;  

	C_upper = (A_upper * B_lower + A_lower * B_upper) >> 16;
	C_lower = (A_upper * B_lower + A_lower * B_upper) & 0xffff;

	//D_lower���� �ڸ��� �Ѵ� �� ���(E)�� ���� D_upper�� �Ѱ��ش�.
	E = (C_lower >> 15) & (A_lower * B_lower >> 31);
	D_upper = (A_upper * B_upper) + C_upper + E;
	D_lower = (C_lower << 16) + (A_lower * B_lower);


	printf("(int)A * (int)B = OX%08X%08X\n", D_upper, D_lower);
	printf("(long long)A * (long long)B = OX%016llX\n", (long long)A * B);
	printf("(long long)A * (long long)B = %lld\n", (long long)A * B);

	return 0;
}




