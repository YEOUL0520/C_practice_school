/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.12.09
�������� ������ �ֻ����� ���� ����ڰ� ���� ������ �ݺ��ϴ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�ֻ��� ���� Ű����� �Է¹޾� �� ���� return ���ִ� �Լ�
int check_dice(void);
//�ֻ��� ���� ���� �������� ������ �� �� ���� return ���ִ� �Լ�
int rolling_dice(void);

int main(void)
{
	int count = 0;
	int sum = 0;
	int human,dice;

	srand((unsigned)time(NULL));//�ð��� ���� �ʱ�ȭ

	while (1)
	{
		printf("�ֻ����� ���� �����ÿ� : ");
		human = check_dice();//���� �� ��������߸� �ϴµ�
		printf("�ֻ����� �����ϴ�.\n");
		dice = rolling_dice();//���ʵ� ��������
		printf("�ֻ��� ���� ���� %d �Դϴ�.\n", dice);
		count++;
		sum += dice;
		if (human == dice)
		{
			printf("�����̽��ϴ�. �� ���� Ƚ���� %d�Դϴ�.\n", count);
			printf("���� ������ ���� %d �̰� �ֻ��� ���� ���� ����� %.2f�Դϴ�.", sum, (float)sum/(float)count);//float�� ��� ���� ����ȯ ���� ����
			break;
		}
		
	}
	return 0;
}

int check_dice(void)
{
	int choice;
	scanf("%d", &choice);
	return choice;
}
int rolling_dice(void)
{
	int dice;
	dice = (rand() % 6) + 1;
	return dice;
}