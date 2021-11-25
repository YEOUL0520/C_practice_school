/*----------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.02
2���� �ð��� �Է¹޾� 
�� ���̸� �� �� �� �ʷ� ������ ����ϴ� ���α׷�
------------------------*/

#include <stdio.h>

void convert_seconds(int sec);
void time_diff(int sec1, int sec2);
int main(void)
{
	int sec1, sec2;

	while (1)
	{
		printf("ù��° �ʸ� �Է��ϼ���: ");
		scanf("%d", &sec1);
		

		if (sec1 < 0)
		{
			printf("�ð��� 0���� Ŀ���մϴ�.\n");
			continue;
		}
		else
			break;
	}

	while (1)
	{
		printf("�ι�° �ʸ� �Է��ϼ���: ");
		scanf("%d", &sec2);
		
		if (sec2 < 0)
		{
			printf("�ð��� 0���� Ŀ���մϴ�.\n");
			continue;
		}
		break;
	}

	printf("ù ��° �ð��� ");
	convert_seconds(sec1);
	printf(" (%d ��)\n", sec1);
	printf("�� ��° �ð��� ");
	convert_seconds(sec2);
	printf(" (%d ��)\n", sec2);
	time_diff(sec1, sec2);

	return 0;
}

void convert_seconds(int sec)
{
	int min, hour, day, sec_left;

	day = ((sec/60)/60) / 24;
	hour = ((sec / 60) / 60) - (day * 24);
	min = (sec / 60) - (hour * 60) - ((day*24)*60);
	sec_left = sec % 60;

	printf("%d�� %d�� %d�� %d���Դϴ�.", day, hour, min, sec_left);

}

void time_diff(int sec1, int sec2)
{
	int diff;
	if (sec1 > sec2)
		diff = (sec1 - sec2);
	else
		diff = (sec2 - sec1);
	
	printf("�� �Էµ� �ð��� ���̴� ");
	convert_seconds(diff);
}
