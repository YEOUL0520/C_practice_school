/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.11.02
2개의 시간을 입력받아 
그 차이를 일 시 분 초로 나누어 출력하는 프로그램
------------------------*/

#include <stdio.h>

void convert_seconds(int sec);
void time_diff(int sec1, int sec2);
int main(void)
{
	int sec1, sec2;

	while (1)
	{
		printf("첫번째 초를 입력하세요: ");
		scanf("%d", &sec1);
		

		if (sec1 < 0)
		{
			printf("시간은 0보다 커야합니다.\n");
			continue;
		}
		else
			break;
	}

	while (1)
	{
		printf("두번째 초를 입력하세요: ");
		scanf("%d", &sec2);
		
		if (sec2 < 0)
		{
			printf("시간은 0보다 커야합니다.\n");
			continue;
		}
		break;
	}

	printf("첫 번째 시간은 ");
	convert_seconds(sec1);
	printf(" (%d 초)\n", sec1);
	printf("두 번째 시간은 ");
	convert_seconds(sec2);
	printf(" (%d 초)\n", sec2);
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

	printf("%d일 %d시 %d분 %d초입니다.", day, hour, min, sec_left);

}

void time_diff(int sec1, int sec2)
{
	int diff;
	if (sec1 > sec2)
		diff = (sec1 - sec2);
	else
		diff = (sec2 - sec1);
	
	printf("두 입력된 시간의 차이는 ");
	convert_seconds(diff);
}
