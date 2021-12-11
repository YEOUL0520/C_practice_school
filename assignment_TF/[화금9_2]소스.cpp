#include <stdio.h>

int factorial(int number);
int multiply(int number);
int reverse(int number);

int main(void)
{
	int number, answer;
	printf("팩토리얼 구할 수를 입력 : ");
	scanf("%d", &number);
	if (number < 0)
	{
		while (1)
		{
			printf("0 이상의 정수로 다시 입력 : ");
			scanf("%d", &number);
			if (number > 0)
				break;
		}
	}
	answer = factorial(number);
	printf("%d! = %d\n", number, answer);
	printf("각 자리수의 곱 : %d\n", multiply(answer));
	printf("계산된 팩토리얼의 결과를 역순으로 출력 : ");
	reverse(answer);
	
}
//팩토리얼을 구하는 함수
int factorial(int number)
{
	if (number <= 1)
		return 1;
	else
		return (number * factorial(number - 1));
}
//각 자리 수의 곱을 구하는 함수
int multiply(int number)
{
	if (number <= 1)
		return 1;
	else
		return ((number % 10) * multiply(number / 10));
}
//각 자리 수의 위치를 바꾸는 함수
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