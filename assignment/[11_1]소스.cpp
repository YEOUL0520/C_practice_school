/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.17
���� ���� : 2021.11.23
�Է¹��� ���ڿ��� ���ĺ� ���� �󵵼��� ���� ���� �� ����ϴ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>

void swap_num(int* n1, int* n2);
void swap_char(char* n1, char* n2);

int main(void)
{
	int number;

	printf("<<���ڿ� �м� ���α׷�>>\n");

	//0�� ���������� ���ѹݺ�
	while (1)
	{
		
		printf("========================\n");
		printf("1. ���ڿ� �м�\n");
		printf("0. ���α׷� ����\n");
		printf("========================\n");
		printf("��ȣ �Է� : ");
		scanf("%d", &number);

		if (number == 1)
		{
			char list[100];
			printf("�м��� ���ڿ� �Է�: ");
			scanf("%s", list);

			int size = 0;
			//�Էµ� ���ڿ��� ���̸� size�� ����
			for (int k = 0; k < 100; k++)
				if (list[k] == NULL)
					break;
				else
					size++;

			int i, k;
			int alpa_count[26] = { 0 };
			char beta_count[26] = { 0 };
			//�� ���ĺ��� ���� �󵵼��� �� �迭 alpa_count
			for (i = 0; i < size; i++)
			{
				alpa_count[list[i] - 'a']++;
			}
			//�� ���ĺ��� ���� �󵵼���� ������ �迭 beta_count
			for (int a = 0; a < 26; a++)
			{
				beta_count[a] = 'a' + a;
			}

			int max, temp;

			//swap�Լ��� �̿��� ���� �󵵼��� ���� ����� alpa_count�� beta_count�� ����
			for (int j = 0; j < 25; j++)
			{
				max = j;
				for (int i = j + 1; i < 26; i++)
					if (alpa_count[i] > alpa_count[max])
						max = i;
				swap_num(&alpa_count[j], &alpa_count[max]);
				swap_char(&beta_count[j], &beta_count[max]);

			}

			//������ ���� ���
			printf("\n�⿬ �󵵼��� ���� 5���� ���ĺ�\n");
			for (int print = 0; print < 5; print++)
				printf("%d         %c         %d��\n", print + 1, beta_count[print], alpa_count[print]);
			printf("\n\n");
		}
		else
			break;
	}

	return 0;
}
void swap_num(int* n1, int* n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
void swap_char(char* n1, char* n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}