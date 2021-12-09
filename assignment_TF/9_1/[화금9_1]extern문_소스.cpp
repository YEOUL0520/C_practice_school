#include <stdio.h>

char change_char(int d);

void print_RSP(int d, int x)
{
	printf("경기 결과.\n");
	printf("당신은 %c를 냈고, 컴퓨터는 %c를 냈습니다.\n", change_char(d), change_char(x));
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