#include <stdio.h>

int main(void)
{
	float a;
	float b;
	float bmi;

	printf("BMI지수 계산기\n");
	printf("키를 입력하세요(cm) : ");
	scanf("%f", &a);

	printf("몸무게를 입력하세요(kg) : ");
	scanf("%f", &b);

	bmi = b/((a/100)*(a/100));
	printf("BMI지수는 %f입니다.", bmi);

	return 0;
}
