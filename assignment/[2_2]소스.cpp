#include <stdio.h>

int main(void)
{
	int x;
	int y;
	int k;
	int a;
	int b;

	printf("직육면체의 가로와 세로, 높이를 정수로 입력하시오 : ");
	scanf("%d %d %d", &x, &y, &k);

	a = (x * y) * 2 + (y * k) * 2 + (k * x) * 2;
	b = x * y * k;
	printf("직육면체의 겉넓이 : %d\n", a);
	printf("직육면체의 부피 : %d", b);

	return 0;

}