/*----------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.02
���� ������ �Է¹޾� �������� �� ���� �̰�,
���� �� ���� �ִ������� ���ϴ� ���α׷�
------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void gcd(int n1, int n2);

int main(void)
{
	int a, b, x, y;

	while (1)
	{
		printf("�������� ���� �� �ڿ����� ������ �Է����ּ���: ");
		scanf("%d %d", &a, &b);
		
		//�Է� ���� 2 �̻��� �ڿ����� �ƴ� ��� ���� �ٽ� �Է¹���
		if (a < 2)
		{
			printf("ù ��° �Է� ���� 2 �̻��� �ڿ����� �ƴմϴ�.\n");
			
			if (b < 2)
				printf("�� ��° �Է� ���� 2 �̻��� �ڿ����� �ƴմϴ�.\n");
			
			printf("\n");

			continue;
		}
		else
			if (b < 2)
			{
				printf("�� ��° �Է� ���� 2 �̻��� �ڿ����� �ƴմϴ�.\n");
				printf("\n");
				continue;
			}
		
		//�Էµ� �� ���� ���̰� 3 �̸��� ��� ���� �ٽ� �Է¹���
		if ((b - a) < 3)
		{
			printf("�Էµ� �� ���� ���̰� 3 �̸��Դϴ�.\n");
			printf("\n");
		}
		else
			break;
	}

	//�Է� ���� �� �������� �� �� ���
	srand(time(NULL));
	x = rand() % (b - a) + a;
	y = rand() % (b - a) + a;
	printf("���õ� �� ���� %d�� %d�Դϴ�.\n", x, y);

	printf("%d�� %d�� ", x, y);
	gcd(x, y);
	return 0;
}

//�ִ� ����� ��� �Լ�(GCD)
void gcd(int n1, int n2)
{
	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}
	printf("�ִ� �����: %d\n", n1);
}