#include <stdio.h>

char change_char(int d);

void print_RSP(int d, int x)
{
	printf("��� ���.\n");
	printf("����� %c�� �°�, ��ǻ�ʹ� %c�� �½��ϴ�.\n", change_char(d), change_char(x));
}

char change_char(int d)
{
	if (d == 1)
		return 'R';
	else if (d == 2)
		return 'S';
	else if (d == 3)
		return 'P';
}