#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_prime(int n);
void print_graph(int n);

int main(void)
{
	int number;
	srand((unsigned)time(NULL));

	number = rand() % 100 + 1;
	printf("%d\n", number);
	print_graph(number);
	
}
int is_prime(int n)
{
	int k;
	for (k = 2; k < n; k++)
	{
		if (n % k == 0)
			break;
	}
	if (n == k)
		return 1;
	else
		return 0;
}
void print_graph(int n)
{
	int count = 0;
	if (is_prime(n) == 1)
	{
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				count++;
				if (count == n)
				{
					printf("%3d  ", n);//±×³É %dÇÑÃ¤·Î ÇÒ °æ¿ì Ã¹ÁÙ¿¡ ¸ÂÃçÁü
				}
				else
					printf("  *  ");//±×·²°æ¿ì *  (°ø¹é µÎÄ­) ÇØÁÖ¸é µÊ
			}
			printf("\n");
		}
		
	}
	else
	{
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
				printf("*  ");
			printf("\n");
		}
	}
}