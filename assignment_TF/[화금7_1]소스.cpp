/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.12.09
랜덤으로 나오는 주사위의 수를 사용자가 맞힐 때까지 반복하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//주사위 값을 키보드로 입력받아 그 값을 return 해주는 함수
int check_dice(void);
//주사위 눈의 수를 랜덤으로 나오게 해 그 값을 return 해주는 함수
int rolling_dice(void);

int main(void)
{
	int count = 0;
	int sum = 0;
	int human,dice;

	srand((unsigned)time(NULL));//시간에 따라 초기화

	while (1)
	{
		printf("주사위의 눈을 맞히시오 : ");
		human = check_dice();//일케 값 지정해줘야만 하는듯
		printf("주사위를 던집니다.\n");
		dice = rolling_dice();//이쪽도 마찬가지
		printf("주사위 눈의 수는 %d 입니다.\n", dice);
		count++;
		sum += dice;
		if (human == dice)
		{
			printf("맞히셨습니다. 총 던진 횟수는 %d입니다.\n", count);
			printf("눈의 수들의 합은 %d 이고 주사위 눈의 수의 평균은 %.2f입니다.", sum, (float)sum/(float)count);//float형 출력 위해 형변환 잊지 말기
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