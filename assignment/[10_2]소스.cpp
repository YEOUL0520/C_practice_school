/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.11
영화를 선택하고 좌석을 선택하여 예약할 수 있도록 하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#define ROWS 2
#define COLS 6

//함수 원형 선언
void movie_choose();
void seat_choose();
void seat_check();

int main(void)
{
	printf("00영화관에 오신걸 환영합니다.\n");
	printf("-------------------00영화관-------------------\n");
	printf("       1.이터널스 2.싱크홀 3.라따뚜이\n");
	printf("----------------------------------------------\n");
	movie_choose();
	printf("좌석을 선택하세요. 현재 예약 현황입니다.\n");
	printf("(1 = 예약완료, 0 = 예약가능)\n");
	seat_choose();
	seat_check();

}

//영화를 택한 후 어떤 영화를 택했는지 출력하는 함수
void movie_choose()
{
	int choose;

	while (1)//1,2,3번 범위 외 영화 선택 경우 제대로 된 번호 선택 시까지 반복
	{
		printf("영화를 선택하세요: ");
		scanf("%d", &choose);

		if (choose == 1)
		{
			printf("선택한 영화는 이터널스입니다.\n");
			break;
		}
		else if (choose == 2)
		{
			printf("선택한 영화는 싱크홀입니다.\n");
			break;
		}

		else if (choose == 3)
		{
			printf("선택한 영화는 라따뚜이입니다.\n");
			break;
		}
		else
			continue;
	
	}

	return;

}

//배치되어있는 좌석을 확인하는 함수
void seat_choose()
{
	printf("---------------스크린---------------\n");
	printf("          1  2  3  4  5  6          \n");
	printf("------------------------------------\n");
	
	
	int x, y;
	int seat[ROWS][COLS] = { {0,0,1,0,1,0},{1,0,0,1,0,0} };//2차원 배열을 사용해 좌석 지정

	for (x = 0; x < ROWS; x++)
	{
		printf("%d  |    ", x + 1);
		for (y = 0; y < COLS; y++)
		{
			printf("%3d", seat[x][y]);
		}
		printf("\n");
	}
	printf("------------------------------------\n");
}

//선택한 좌석이 예약되어있는지 확인하고 예약이 완료될 경우 결과를 출력하는 함수
void seat_check()
{

	int x, y;
	int a, b;
	int seat[ROWS][COLS] = { {0,0,1,0,1,0},{1,0,0,1,0,0} };

	while (1)
	{
		printf("몇 번 좌석을 선택하시겠습니까?(행과 열 입력):");
		scanf("%d %d", &a, &b);

		if (seat[a-1][b-1] == 1)//배열은 0부터 시작하므로 택한 좌석의 행과 열 좌표에서 1을 빼 주어야 함
		{
			printf("예약된 좌석입니다. 다시 선택해주세요.\n");
		}
		else
		{
			printf("예약이 완료되었습니다.\n");
			printf("선택좌석: %d행 %d열\n\n", a, b);
			break;
		}
	}

	seat[a-1][b-1] = 1;//선택한 좌석의 인덱스 값을 1로 바꿈

	printf("예약결과\n");
	printf("---------------스크린---------------\n");
	printf("          1  2  3  4  5  6          \n");
	printf("------------------------------------\n");
	for (x = 0; x < ROWS; x++)
	{
		printf("%d  |    ", x + 1);
		for (y = 0; y < COLS; y++)
		{
			printf("%3d", seat[x][y]);
		}
		printf("\n");
	}
	printf("------------------------------------\n");
	printf("이용해주셔서 감사합니다.");
}