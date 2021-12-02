/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.12.02
��Ʈ�� ������ Ȱ���� ����ڰ� �Է��� ���� 
�ؽ�Ʈ ���Ϸ� �����Ͽ� �����ϴ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>

int main(void)
{
	FILE* fp;
	int year, month, day, money; //��¥ �� ���� ���� �ڻ��� �Է¹��� ����
	int choice;//�޴� ���ð��� �Է¹��� ����

	printf("����� �ۼ��� �����մϴ�.\n\n");
	printf("��¥�� �Է��ϼ���. (��: 2020 04 13) : ");
	scanf("%d %d %d", &year, &month, &day);
	printf("\n");
	getchar();
	printf("���� ���� �ڻ��� �Է��ϼ���. : ");
	scanf("%d", &money);
	printf("\n");
	fp = fopen("cashbook.txt", "a");//cashbook�̸��� �޸��� ����
	//�Է¹��� ��¥�� ���Ŀ� ���߾� �޸��忡 �����
	fprintf(fp, "========= %d�� %d�� %d�� ��� ���� =========\n", year, month, day);
	fprintf(fp, "\n");

	//���� ���� �� �ʱ�ȭ
	int balance = 0;
	char income_list[100];
	int t_income_money = 0;
	int income_count = 0;
	int income_money = 0;
	char expenditure_list[100];
	int expenditure_count = 0;
	int expenditure_money = 0;
	int t_expenditure_money = 0;

	//���α׷� ���Ḧ �����ϱ� ������ ��� �ݺ���
	while (1)
	{
		printf("�Է� ���� (1. ���Ծ� 2. ����� 3. ���α׷� ����) : ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			//���� ������ �ݾ��� �Է¹ް� ���� ������ ���
			printf("���� ������ �Է��ϼ��� : ");
			scanf("%s", income_list);
			getchar();
			printf("���� �ݾ��� �Է��ϼ��� : ");
			scanf("%d", &income_money);
			getchar();
			income_count++;
			t_income_money += income_money;
			printf("�Է��Ͻ� ���� ������ %d�� �Դϴ�.\n\n", t_income_money);
			//�޸��忡 ���� ����� �����
			fprintf(fp, "���� ��� %d %s %d��\n", income_count, income_list, income_money);
		}
		else if (choice == 2)
		{
			//���� ������ �ݾ��� �Է¹ް� ���� ������ ���
			printf("���� ������ �Է��ϼ��� : ");
			scanf("%s", expenditure_list);
			getchar();
			printf("���� �ݾ��� �Է��ϼ��� : ");
			scanf("%d", &expenditure_money);
			getchar();
			expenditure_count++;
			t_expenditure_money += expenditure_money;
			printf("�Է��Ͻ� ���� ������ %d�� �Դϴ�.\n\n", t_expenditure_money);
			//�޸��忡 ���� ����� �����
			fprintf(fp, "���� ��� %d %s %d��\n", expenditure_count, expenditure_list, expenditure_money);
		}
		else if (choice == 3)
		{
			//�� ���԰� �� ������ �޸��忡 �����
			fprintf(fp, "[�հ�] ���� : %d�� ���� : %d��\n", t_income_money, t_expenditure_money);
			//�ܾ��� ����� �޸��忡 ����ϰ�, ���� ����� �ܿ� �ݾ��� �����
			balance = money + t_income_money - t_expenditure_money;
			fprintf(fp, "�ܾ� : %d��\n", balance);
			printf("=> ���� ������ %d��, �ܿ� �ݾ��� %d�� �Դϴ�.", t_expenditure_money, balance);
			break;//3�� ���ý� ���α׷��� ������
		}
		else
		{
			printf("�˸��� ��ȣ�� ���Է��ϼ���.\n");
		}
	}

	fclose(fp);
	return 0;
}
