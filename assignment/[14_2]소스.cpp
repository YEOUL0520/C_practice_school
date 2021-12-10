/*----------------------------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.12.02
�������� �̸�, ����, �ڰ��� ���� ����, ���������� �м��ϰ� ���ؿ� ���߾� ����ϴ� ���α׷�
------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#define SIZE 30

typedef struct applicants
{
	char name[10];
	double grade;
	char get;
	int point;
} APPLICANTS; //�������� �ڰ� ��ǿ� ���� ����ü�� �����ϰ� ���ο� �ڷ��� APPLICANTS�� ������

void quality_test(APPLICANTS list[30], int n);
int selection_cort_grade(APPLICANTS* a, int n);
void print_list(APPLICANTS* list, int n);

//���������� ����
int count = 0;
double sum = 0;

int main(void)
{
	int choice, number, j;
	APPLICANTS list[SIZE];
	
	while (1)
	{
		printf("===========================\n");
		printf("0. ������ �м�\n");
		printf("1. ����\n");
		printf("===========================\n");
		printf("�Է� : ");
		scanf("%d", &choice);


		if (choice == 0)
		{
			printf("������ ���� �Է��ϼ���. : ");
			scanf("%d", &number);
			printf("�������� �̸�, ����, �ڰ��� ���� ����, ���������� ������� �Է��ϼ���.\n");

			int i = 0;

			while (i < number)//�������� ����ŭ �迭 ����ü�� �Է¹���
			{
				printf("�Է� : ");
				scanf("%s %lf %c %d", list[i].name, &list[i].grade, &list[i].get, &list[i].point);
				i++;
			}

			quality_test(list, number);//�����ڵ��� �����ڰ��� �׽�Ʈ��

			printf("\n\n������ ��� : \n");
			printf("===========================\n");
			printf("������������ ���\n");
			printf("===========================\n");
			printf("         �̸�       ����        ����     ��������\n");

			if (selection_cort_grade(list, number) == 2)//������������ ������ �Ϸ�Ǿ��� ���
			{
				print_list(list, number);//list�� ���
			}

			printf("�����ڰ��� �����ϴ� �л��� ���� %d�Դϴ�.\n", count);//�����ڰ��� �����ϴ� �л��� ���
			printf("�����ڰ��� �����ϴ� �л����� ��������� %.2lf�̴�.\n", sum / count);//�����ڰ��� �����ϴ� �л����� ������� ���
		}
		else if (choice == 1)
			break;
	}
	return 0;
}
//�����ڰ��� �׽�Ʈ�ϴ� �Լ�
void quality_test(APPLICANTS list[30], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (list[i].point < 500)//���� ������ �������� ���� ��� ���� 0���� ����
			list[i].point = 0;
	}

	int t;
	for (t = 0; t < n; t++)
	{
		if (list[t].get != 'o')//�ڰ����� �������� ���� ��� ���� 0���� �ٲ�
			list[t].get = NULL;
	}
}
//���� ������ ����ؼ� ������������ �����ϴ� �Լ�
int selection_cort_grade(APPLICANTS* a, int n)
{
	int max;
	APPLICANTS temp;

	for (int l = 0; l < n-1; l++)
	{
		max = l;
		for (int i = l+1; i < n; i++)
			if (a[i].grade > a[max].grade)
				max = i;
		temp = a[l];
		a[l] = a[max];
		a[max] = temp;
	}

	return 2;
}
//APPLICANTS�迭�� ����ϴ� �Լ�
void print_list(APPLICANTS* list, int n)
{
	count = 0;
	sum = 0;

	for (int i = 0; i < n; i++)
	{
		//�ڰ��� �������� �ʴ� ����� ���� ���� 0���� �ٲ��־����Ƿ� 0�� ������ ���� ��쿡�� print��
		if (list[i].point == 0 || list[i].get == NULL)
		{
			continue;
		}
		else
		{
			sum += list[i].grade; //�����ڰ��� �����ϴ� ��� ������ ���տ� �ջ�
			count++;//�����ڰ��� �����ϴ� �л��� ���� ��
			printf("%d. %10s %10.2lf %10c %10d\n", i + 1, list[i].name, list[i].grade, list[i].get, list[i].point);//�����ڰ��� ������ ��� print����
		}
	} 
}

