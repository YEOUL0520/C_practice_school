/*--------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.03
���θ��� ���� ���� ���̸� �Է¹޾�
�ִܰŸ��� ���̿� �� ����� ���� ����ϴ� ���α׷�
----------------------------------------------------*/
#include <stdio.h>

//���� �޴� ������ ���� �ֹ� �ݾ��� ���� ������ ���
int count_all, price_all;
int count_1, count_2, count_3;

void choose(int n);
void password_check(void);
int main(void)
{
	int number;

	//������ �Ϸ��Ҷ����� ��� �ݺ�
	while (1)
	{
		printf("-------------------------------------------------------\n");
		printf("              �ֹ��� �޴��� �������ּ���\n");
		printf("-------------------------------------------------------\n");
		printf("              1. �Ƹ޸�ī��\n");
		printf("              2. ���̽�Ƽ\n");
		printf("              3. ����\n");
		printf("              4. �� �� �� ��\n");
		printf("-------------------------------------------------------\n");
		printf("�޴��� �����ϼ��� : ");
		scanf("%d", &number);

		if (number == 4)
			break;
		else
		{
			choose(number);
		}
	}
	
	printf("-------------------------------------------------------\n");
	printf("                    �ֹ���� ��ȸ\n");
	printf("-------------------------------------------------------\n");
	printf("�Ƹ޸�ī�� %d��\n���̽�Ƽ %d��\n���� %d��\n", count_1, count_2, count_3);
	printf("�� �޴� ���� : %d��\n", count_all);
	printf("���� �ݾ� : %d��\n\n", price_all);
	
	password_check();
	
	return 0;
}
//�޴��� ���ݰ� ���� �ֹ� �ݾ�, ���� �޴� ������ ����ϴ� �Լ�
void choose(int n)
{
	
	
	int price;

	//��ȣ�� �����Ҷ����� ������ Ƚ���� ����, ���ÿ� �ش�Ǵ� �޴��� �ݾװ� �� ������ ���
	if (n == 1)
	{
		price = 3000;
		printf("�Ƹ޸�ī��� 3000�� �Դϴ�.\n");
		count_1++;
		count_all++;
		price_all = price_all + 3000;
	}
	if (n == 2)
	{
		printf("���̽�Ƽ�� 3000�� �Դϴ�.\n");
		count_2++;
		count_all++;
		price_all = price_all + 3000;
	}
	if (n == 3)
	{
		printf("������ 6000�� �Դϴ�.\n");
		count_3++;
		count_all++;
		price_all = price_all + 6000;
	}
	
	//���� �� ���� Ƚ���� �ݾ��� ����
	printf("���ݱ��� �����Ͻ� �޴��� ������ %d�� �Դϴ�.\n", count_all);
	printf("���ݱ��� �����Ͻ� �޴��� ���� �ݾ��� %d�� �Դϴ�.\n", price_all);

}
//�н����带 �˻��ϴ� �Լ�
void password_check(void)
{
	int password,password_count;
	password_count = 0;

	while (1)
	{
		//��й�ȣ �õ� Ƚ�� 4ȸ �ʰ���(5ȸ����) ����
		if (password_count == 5)
		{
			printf("�α��� �õ� Ƚ���� �ʰ��Ͽ����ϴ�. ������ �ֹ��� �ֽñ� �ٶ��ϴ�.");
			break;
		}
		else
		{
			printf("���� ��ȣ �Է� : ");
			scanf("%d", &password);
			password_count++;
			//��й�ȣ�� 1234�� ��ġ�� ����
			if (password == 1234)
			{
				printf("�ֹ��� �Ϸ�Ǿ����ϴ�. �̿����ּż� �����մϴ�.");
				break;
			}
			//��й�ȣ�� 1234�� ��ġ���� ���� ��� ���
			else
				continue;

		}
	}
}