/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.12.02
����ü�� �̿��� ����ڰ� ���� ������ �޴��� �ۼ��ϰ�
����� �޴��� ������ �� �ִ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
#define SIZE 2

void krmenu_writing(struct korean* k);
void chmenu_writing(struct chinese* c);
void jpmenu_writing(struct japanese* j);
//�ѽ� �޴��� �޾ƿ��� ����ü
struct korean
{
	char name_k[100];
	int price_k;
};
//�߽� �޴��� �޾ƿ��� ����ü
struct chinese
{
	char name_c[100];
	int price_c;
};
//�Ͻ� �޴��� �޾ƿ��� ����ü
struct japanese
{
	char name_j[100];
	int price_j;
};

int main(void)
{
	struct korean k[SIZE];
	struct chinese c[SIZE];
	struct japanese j[SIZE];

	printf("========= �޴��� �ۼ� =========\n\n");
	krmenu_writing(k);
	chmenu_writing(c);
	jpmenu_writing(j);
	printf("\n");
	printf("========= ������ �޴��� =========\n\n");
	printf("-�ѽ�-\n");
	for (int y=0; y<SIZE; y++)
		printf("%d. %s | %d��\n", y+1, k[y].name_k, k[y].price_k);
	printf("\n");
	printf("-�߽�-\n");
	for (int y = 0; y < SIZE; y++)
		printf("%d. %s | %d��\n", y + 3, c[y].name_c, c[y].price_c);
	printf("\n");
	printf("-�Ͻ�-\n");
	for (int y = 0; y < SIZE; y++)
		printf("%d. %s | %d��\n", y + 5, j[y].name_j, j[y].price_j);
	printf("\n");

	int choice;
	while (1)
	{
		printf("�ֹ��Ͻ� �޴��� ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &choice);
		if (choice < 0 || choice > 6)//�Է¹��� �޴��� 1~6�� �������� ��� ��� �ٽ� �Է�
		{
			printf("�߸��� ��ȣ�Դϴ�. �ٽ� �Է��� �ּ���.\n");
			continue;
		}
		else
			break;
	}
	
	printf("�ֹ��� �Ϸ�Ǿ����ϴ�."); //������ �� ��ȣ�� �°� ���� �̸��� ������ �����
	if (choice == 1)
		printf("�ֹ��Ͻ� ������ %s�̰� ������ %d���Դϴ�.", k[0].name_k, k[0].price_k);
	else if (choice == 2)
		printf("�ֹ��Ͻ� ������ %s�̰� ������ %d���Դϴ�.", k[1].name_k, k[1].price_k);
	else if (choice == 3)
		printf("�ֹ��Ͻ� ������ %s�̰� ������ %d���Դϴ�.", c[0].name_c, c[0].price_c);
	else if (choice == 4)
		printf("�ֹ��Ͻ� ������ %s�̰� ������ %d���Դϴ�.", c[1].name_c, c[1].price_c);
	else if (choice == 5)
		printf("�ֹ��Ͻ� ������ %s�̰� ������ %d���Դϴ�.", j[0].name_j, j[0].price_j);
	else if (choice == 6)
		printf("�ֹ��Ͻ� ������ %s�̰� ������ %d���Դϴ�.", j[1].name_j, j[1].price_j);


	return 0;
}
//����ڷκ��� �ѽ� �޴��� �Է¹޴� �Լ�
void krmenu_writing(struct korean* k)
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		printf("�ѽ��� %d ��° ������ �Է��ϼ��� : ", i + 1);
		scanf("%s", k[i].name_k);
		printf("������ ������ �Է��ϼ��� : ");
		scanf("%d", &k[i].price_k);
		printf("\n");
	}
	printf("\n");
}
//����ڷκ��� �߽� �޴��� �Է¹޴� �Լ�
void chmenu_writing(struct chinese* c)
{
	int l;
	for (l = 0; l < SIZE; l++)
	{
		printf("�߽��� %d ��° ������ �Է��ϼ��� : ", l + 1);
		scanf("%s", c[l].name_c);
		printf("������ ������ �Է��ϼ��� : ");
		scanf("%d", &c[l].price_c);
		printf("\n");
	}
	printf("\n");
}
//����ڷκ��� �Ͻ� �޴��� �Է¹޴� �Լ�
void jpmenu_writing(struct japanese* j)
{
	int m;
	for (m = 0; m < SIZE; m++)
	{
		printf("�Ͻ��� %d ��° ������ �Է��ϼ��� : ", m + 1);
		scanf("%s", j[m].name_j);
		printf("������ ������ �Է��ϼ��� : ");
		scanf("%d", &j[m].price_j);
		printf("\n");
	}
	printf("\n");
}