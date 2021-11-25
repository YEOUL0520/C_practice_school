/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.09.29
표준 몸무게를 이용해 몸무게의 범위를 나누는 프로그램
------------------------*/
#include <stdio.h>

int main()
{
	float tall, weight;
	float a, b, c, d, e;

	printf("키(cm), 몸무게(kg)를 입력하시오.");
	scanf("%f %f", &tall, &weight);

	a = (tall - 100) * 0.9;
	b = a + 10;
	c = a - 10;

	//비정상 몸무게의 오차를 구할 최댓값과 최솟값 지정
	d = weight - c;
	e = weight - b;

	//weight의 값이 b의 값보다 작을 경우(참), c의 값이 weight의 값보다 큰 값인지를 판단.
	//두 경우 모두 참이면 첫 번째 printf가 산출. b의 값보다 작지만(참) c의 값보다 작을 경우(거짓) 두 번째 printf가 산출. b의 값보다 클 경우(거짓) 마지막printf값이 산출된다.
	(b > weight) ? (c < weight) ? printf("정상 몸무게입니다.") : printf("비정상 몸무게입니다. %.3f kg 벗어났습니다.", d) : printf("비정상 몸무게입니다. %.3f kg 벗어났습니다.", e);

	return 0;					

	
	
}