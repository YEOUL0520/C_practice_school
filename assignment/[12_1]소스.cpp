/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.24
�Է� ���� ���ڿ��� ���̸� ����ϰ�,
�̸� �빮�ڿ� �ҹ��ڷ� �������� ����ϸ�,
������ ���ڿ��� ���� �빮�ڿ� �ҹ��ڷ� �ٲپ� ����� ��
ó�� �Է¹��� ���ڿ��� �ҹ��ڷ� �ٲپ� ������������ �����ϴ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lower_char(char a[]);
void upper_char(char a[]);
void print_lower(char a[]);
void print_upper(char a[]);
int selection_sort_char(char* a);

int length;//���ڿ��� ���̸� ���� ������ ����

int main(void)
{
	char list[100];
	printf("----------���� ��ȯ ���α׷�----------\n");
	printf("���ڿ��� �Է��ϼ��� : ");
	gets_s(list, 100);//gets_s�Լ��� ���� ���ڿ��� �Է¹���
	printf("���ڿ� ���� : ");
	printf("%d\n", strlen(list));//strlen�Լ��� ����� ���ڿ��� ���̸� �����
	length = strlen(list);

	printf("�ҹ��� ���� : ");
	lower_char(list);
	printf("\n�빮�� ���� : ");
	upper_char(list);
	printf("\n�빮�ڷ� ��� : ");
	print_upper(list);
	printf("\n�ҹ��ڷ� ��� : ");
	print_lower(list);
	printf("\n������������ ���ĵ� ���ڿ�: ");
	selection_sort_char(list);
	print_lower(list);
	printf("\n--------------------------------------\n");

	return 0;
}
void lower_char(char a[])//islower�� �̿��� ���ڿ� �� �ҹ��ڸ� ����ϴ� �Լ�
{
	for (int i = 0; a[i] != NULL; i++)
	{
		if (islower(a[i]))//�ش� �迭�� ���� �빮���̸�
		{
			printf("%c ", a[i]);//�̸� �����
		}
	}
}
void upper_char(char a[])//isupper�� �̿��� ���ڿ� �� �빮�ڸ� ����ϴ� �Լ�
{
	for (int i = 0; a[i] != NULL; i++)
	{
		if (isupper(a[i]))//�ش� �迭�� ���� �빮���̸�
		{
			printf("%c ", a[i]);//�̸� �����
		}
	}
}
void print_lower(char a[])//isupper�� tolower�� �̿��� �빮�ڸ� �ҹ��ڷ� �ٲٴ� �Լ�
{
	for (int i = 0; a[i] != NULL; i++)
	{
		if (isupper(a[i]))//�ش� �迭�� ���� �빮���̸�
			a[i] = tolower(a[i]);//�빮�ڸ� �ҹ��ڷ� �����ϰ�

		printf("%c", a[i]);//�̸� �����
	}
}
void print_upper(char a[])//islower�� toupper�� �̿��� �ҹ��ڸ� �빮�ڷ� �ٲٴ� �Լ�
{
	for (int i = 0; a[i] != NULL; i++)
	{
		if (islower(a[i]))//�ش� �迭�� ���� �ҹ����̸�
			a[i] = toupper(a[i]);//�ҹ��ڸ� �빮�ڷ� �����ϰ�

		printf("%c", a[i]);//�̸� �����
	}
}
int selection_sort_char(char* a)//���ڸ� ������������ �����ϴ� �Լ�
{
	int low;
	char temp;

	for (int x = 0; x < (length - 1); x++)
	{
		low = x;
		for (int y = x + 1; y < length; y++)
		{
			if (a[y] < a[low])
				low = y;
		}

		if (x != low)
		{
			temp = a[x];
			a[x] = a[low];
			a[low] = temp;
		}

	}

	return 0;
}