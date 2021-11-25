/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.23
������ ������ �Է� �޾� ������ 10���� ���� ���� �迭�� ������ ��,
�������� �� ������������ �̸� �����ϴ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void Assending(int array[]);
void Descending(int array[]);

int main(void)
{
	srand(time(NULL));
	int list[SIZE] = { 0 };
	int a, b, max, min, choice = 0;

	while (1)
	{
		printf("������ ������ ������ ���Ͻÿ� : ");
		scanf("%d %d", &a, &b);
		//�Է��� ������ ������ ��� �ٽ� �Է¹���
		if (a < 0 || b < 0)
			printf("���� ���� �Է��� �ּ���.\n\n");
		else
			break;
	}
	//�Է��� �� �� �� ��� ���� ū ���̰� ��� ���� ���� ������ �Ǻ�
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	//�Է��� ������ ������ �°� ������ �� 10���� ����ϰ�, list�� ���
	for (int i = 0; i < 10; i++)
		list[i] = rand() % ((max - min) + 1) + min;

	printf("������ �迭 : ");
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);
	printf("\n1. �������� 2. �������� ");
	scanf("%d", &choice);

	if (choice == 1)
	{
		Assending(list);
		printf("������������ ������ �迭 :\n");
		for (int i = 0; i < 10; i++)
			printf("%d ", list[i]);
	}
	else if (choice == 2)
	{
		Descending(list);
		printf("������������ ������ �迭 :\n");
		for (int i = 0; i < 10; i++)
			printf("%d ", list[i]);
	}

}
//������������ �����ϴ� �Լ�
void Assending(int array[])
{
	int min, temp;

	for (int x = 0; x < 9; x++)
	{
		min = x;
		for (int y = x + 1; y < 10; y++)
			if (array[y] < array[min])
				min = y;
		temp = array[x];
		array[x] = array[min];
		array[min] = temp;

	}
}
//������������ �����ϴ� �Լ�
void Descending(int array[])
{
	int max, temp;

	for (int x = 0; x < 9; x++)
	{
		max = x;
		for (int y = x + 1; y < 10; y++)
			if (array[y] > array[max])
				max = y;
		temp = array[x];
		array[x] = array[max];
		array[max] = temp;

	}
}