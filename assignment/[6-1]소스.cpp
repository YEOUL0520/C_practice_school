/*----------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.10.14
���� �л����� ������ �հ� ���,
�׸��� ������ ������ ���� ����� ����ϴ� ���α׷�
------------------------*/
#include <stdio.h>

int main(void)
{
	unsigned int i, number;
	float score, sum;

	printf("���� �л��� ���� �Է��ϼ��� : ");
	scanf("%d", &number);

	for (i = 1, sum=0; i <= number; i++)
	{
		printf("%d��° �л��� ������ �Է��ϼ��� : ", i);
		scanf("%f", &score);

		sum += score;

		if (score < 0 || score>100) //���� �������� ��� ��� �ٽ� i���� �޴´�.
		{
			printf("�Է��� ������ �߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n\n");
			sum = sum - score;
			i--;
			continue;
		}
		//���� ������ ���� ����� �����Ѵ�.
		else if (score >= 90)
			printf("%d�л��� %.1f �������� A����Դϴ�.\n\n", i, score);
		else if (score >= 80)
			printf("%d�л��� %.1f �������� B����Դϴ�.\n\n", i, score);
		else if (score >= 70)
			printf("%d�л��� %.1f �������� C����Դϴ�.\n\n", i, score);
		else if (score >= 60)
			printf("%d�л��� %.1f �������� D����Դϴ�.\n\n", i, score);
		else
			printf("%d�л��� %.1f �������� F����Դϴ�.\n\n", i, score);

		
	}

	//���� �л����� ���� ���հ� ����� ����Ѵ�.
	printf("���� �л����� ���� ������ %.1f�Դϴ�.\n", sum);
	printf("���� �л����� ��� ������ %.3f�Դϴ�.", sum / number);

	return 0;
}