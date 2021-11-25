/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.10.14
수강 학생들의 성적의 합과 평균,
그리고 각각의 성적에 따른 등급을 출력하는 프로그램
------------------------*/
#include <stdio.h>

int main(void)
{
	unsigned int i, number;
	float score, sum;

	printf("수강 학생의 수를 입력하세요 : ");
	scanf("%d", &number);

	for (i = 1, sum=0; i <= number; i++)
	{
		printf("%d번째 학생의 점수를 입력하세요 : ", i);
		scanf("%f", &score);

		sum += score;

		if (score < 0 || score>100) //점수 범위에서 벗어난 경우 다시 i값을 받는다.
		{
			printf("입력한 점수는 잘못된 점수입니다. 다시 입력해주세요.\n\n");
			sum = sum - score;
			i--;
			continue;
		}
		//점수 범위에 따른 등급을 산출한다.
		else if (score >= 90)
			printf("%d학생은 %.1f 성적으로 A등급입니다.\n\n", i, score);
		else if (score >= 80)
			printf("%d학생은 %.1f 성적으로 B등급입니다.\n\n", i, score);
		else if (score >= 70)
			printf("%d학생은 %.1f 성적으로 C등급입니다.\n\n", i, score);
		else if (score >= 60)
			printf("%d학생은 %.1f 성적으로 D등급입니다.\n\n", i, score);
		else
			printf("%d학생은 %.1f 성적으로 F등급입니다.\n\n", i, score);

		
	}

	//수강 학생들의 점수 총합과 평균을 계산한다.
	printf("수강 학생들의 점수 총합은 %.1f입니다.\n", sum);
	printf("수강 학생들의 평균 점수는 %.3f입니다.", sum / number);

	return 0;
}