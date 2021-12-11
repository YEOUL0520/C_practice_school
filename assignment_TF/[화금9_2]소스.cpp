#include <stdio.h>

int factorial(int number);
int multiply(int number);
int reverse(int number);

int main(void)
{
	int number, answer;
	printf("���丮�� ���� ���� �Է� : ");
	scanf("%d", &number);
	if (number < 0)
	{
		while (1)
		{
			printf("0 �̻��� ������ �ٽ� �Է� : ");
			scanf("%d", &number);
			if (number > 0)
				break;
		}
	}
	answer = factorial(number);
	printf("%d! = %d\n", number, answer);
	printf("�� �ڸ����� �� : %d\n", multiply(answer));
	printf("���� ���丮���� ����� �������� ��� : ");
	reverse(answer);
	
}
//���丮���� ���ϴ� �Լ�
int factorial(int number)
{
	if (number <= 1)
		return 1;
	else
		return (number * factorial(number - 1));
}
//�� �ڸ� ���� ���� ���ϴ� �Լ�
int multiply(int number)
{
	if (number <= 1)
		return 1;
	else
		return ((number % 10) * multiply(number / 10));
}
//�� �ڸ� ���� ��ġ�� �ٲٴ� �Լ�
int reverse(int number)
{
	int rev = 0;

	if (number == 1)
	{
		printf("1");
		return 0;
	}
	else if (number == 0)
		return 1;
	else
	{
		rev = number % 10;
		printf("%d", rev);
		return reverse(number / 10);
	}
}