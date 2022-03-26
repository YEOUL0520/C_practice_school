/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.12.01
���� ������ : 2021.12.02
�ܺ� �ؽ�Ʈ ������ �̿��� ��ǰ �ֹ� �������� �ۼ��ϴ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	char fname[100];
	char name[100];
	int price, discount_rate, total, discount;
	float f_discount_rate;

	printf("���� �̸��� �Է����ּ���.: ");
	scanf("%s", fname);

	printf("----------------�޴���---------------\n");
	printf("1. ��� 1000�� ������ 10%%\n");
	printf("2. �� 2000�� ������ 5%%\n");
	printf("3. ���� 2600�� ������ 10%%\n");
	printf("4. �������ֽ� 1300�� ������ 5%%\n");
	printf("5. ��ī�ݶ� 1400�� ������ 10%%\n");
	printf("6. ���� 3000�� ������ 20%%\n");
	printf("7. ����ũ 800�� ������ 5%%\n");
	printf("------------------------------------\n");

	//txt������ �б� ���� �ҷ���
	if ((fp = fopen(fname, "w")) == NULL)
	{
		//������ ���� ���� ��� exit()�� ȣ���� ���α׷� ����
		fprintf(stderr, "%s������ �� �� �����ϴ�.\n", fname);
		exit(1);
	}
	
	while (1)
	{
		//��ǰ �̸�, ����, �������� �Է¹޾� txt���Ͽ� ����
		printf("��ǰ, ����, �������� �Է����ּ���. (����� 0) : ");
		scanf("%s", name);
		printf("\n");

		//0�� �Է¹������ �� �Է� ����
		if (name[0] == '0')
			break;

		scanf("%d %d", &price, &discount_rate);
		//txt���Ͽ��� float�������� ��µǾ�� �ϹǷ� ���� ��ȯ����
		f_discount_rate = (float)discount_rate;
		fprintf(fp, "%s %d %f\n", name, price, f_discount_rate);
		
	}
	fclose(fp);

	//txt������ �б� ���� �ҷ���
	if ((fp = fopen(fname, "r")) == NULL)
	{
		//������ ���� ���� ��� exit()�� ȣ���� ���α׷� ����
		fprintf(stderr, "%s������ �� �� �����ϴ�.\n", fname);
		exit(1);
	}
	
	//�� ������ �ʱ�ȭ
	total = 0;
	discount = 0;
	int k = 0;
	int t = 0;

	//txt���Ͽ��� ���ݰ� �������� �о� �� �ݾװ� ���ι��� �ݾ��� ����
	while (!feof(fp))
	{
		fscanf(fp, "%s %d %f\n", name, &price, &f_discount_rate);
		discount += ((price / 100) * f_discount_rate);
		total += price - ((price / 100) * f_discount_rate);
	}
	
	k = discount - ((price / 100) * f_discount_rate);
	t = total - (price - ((price / 100) * f_discount_rate));
	
	printf("�����Ͻ� �� �ݾ��� %d�� ����, %d�� ���� �����̽��ϴ�.", t, k);
	fclose(fp);
	return 0;
}