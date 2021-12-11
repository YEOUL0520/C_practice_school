/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.12.11
�ߺ����� ������ 1~30������ ���� ����ڰ� �Է��� �� 6���� �� ��
�� ���� ���ڰ� �´��� Ȯ���� �� �ִ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;
int list[6] = { 0 };
int lotto[6] = { 0 };

void random_number();
void lotto_number();
void check_lotto();

int main(void)
{
	srand((unsigned)time(NULL));
	random_number();
	printf("�ζ� ��ȣ:");
	lotto_number();
	check_lotto();
	if (count == 6)
		printf("�����մϴ�! 1���Դϴ�.");
	else if (count == 5)
		printf("�����մϴ�! 2���Դϴ�.");
	else if (count == 4)
		printf("�����մϴ�! 3���Դϴ�.");
	else if (count == 3)
		printf("�����մϴ�! 4���Դϴ�.");
	else
		printf("��� �ȿ� ���� ���߽��ϴ�.");

	return 0;
}
void random_number()
{
	int i;
	for (i = 0; i < 6; i++)
	{
		printf("%d��° �ζ� ��ȣ�� �Է����ּ���: ", i+1);
		scanf("%d", &list[i]);

		for (int j = 0; j < i; j++)
		{
			if (list[j] == list[i])
			{
				printf("�ߺ����� �Է����ּ���.\n");
				i--;
				break;
			}
		}
		if (list[i] > 30)
		{
			printf("1~30������ ���ڸ� �Է����ּ���.\n");
			i--;
			continue;
		}

	}
}
void lotto_number()
{
	for (int i = 0; i < 6; i++)
	{
		lotto[i] = rand() % 30 + 1;

		for (int j = 0; j < i; j++)
		{
			if (lotto[j] == lotto[i])
			{
				i--;
				continue;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", lotto[i]);
	}
}
void check_lotto()
{
	printf("\n���� ��ȣ�� ");
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (lotto[j] == list[i])
			{
				printf("%d ", lotto[j]);
				count++;
			}
		}
	}
	if(count==0)
		printf("�����ϴ�.");
	else
		printf("�Դϴ�.");
	printf("\n\n���� ������ %d �Դϴ�.\n\n", count);
}