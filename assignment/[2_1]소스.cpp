#include <stdio.h>

int main(void)
{
	float a;
	float b;
	float bmi;

	printf("BMI���� ����\n");
	printf("Ű�� �Է��ϼ���(cm) : ");
	scanf("%f", &a);

	printf("�����Ը� �Է��ϼ���(kg) : ");
	scanf("%f", &b);

	bmi = b/((a/100)*(a/100));
	printf("BMI������ %f�Դϴ�.", bmi);

	return 0;
}
