#include <stdio.h>

int main(void)
{
	int x;
	int y;
	int k;
	int a;
	int b;

	printf("������ü�� ���ο� ����, ���̸� ������ �Է��Ͻÿ� : ");
	scanf("%d %d %d", &x, &y, &k);

	a = (x * y) * 2 + (y * k) * 2 + (k * x) * 2;
	b = x * y * k;
	printf("������ü�� �ѳ��� : %d\n", a);
	printf("������ü�� ���� : %d", b);

	return 0;

}