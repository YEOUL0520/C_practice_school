/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.08
0 �̻��� �Ǽ��� double������ �Է¹޾� 2������ ��ȯ�ϴ� ���α׷�
----------------------------------------------------------------*/

#include <stdio.h>

void binary_change1(int x);//�����κ��� ��ȯ���ִ� �Լ�
void binary_change2(double x);//�Ҽ��κ��� ��ȯ���ִ� �Լ�

int main(void)
{
	double number, y;
	int x;

	printf("���� �ƴ� �Ǽ��� �Է��Ͻÿ�:\n");
	scanf("%lf", &number);

	x = (int)number;//�Է¹��� �Ǽ� �� ���� �κ�
	y = number - x;//�Է¹��� �Ǽ� �� �Ҽ� �κ�

	printf("2���� ǥ��: ");
	binary_change1(x);
	printf(".");
	binary_change2(y);

	return 0;
}

void binary_change1(int x)//���� �κ�(int�� ����)�� ��ȯ���ִ� �Լ�
{
	if (x > 0)
	{
		binary_change1(x / 2);
		printf("%d", x % 2);
	}
	return;
}

void binary_change2(double x)//�Ҽ� �κ�(double�� ����)�� ��ȯ���ִ� �Լ�
{
	double k;
	k = x * 2;

	if (k < 1)
	{
		printf("0");
		binary_change2(k);
	}
	else if (k > 1)
	{
		printf("1");
		binary_change2(k - 1);
	}
	else
	{
		printf("1");
		return;
	}

}

