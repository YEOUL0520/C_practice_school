/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.12.02
말을 움직여 먹이를 먹는 간단한 이동 게임 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define ROWS 20
#define COLUMNS 80

void print_matrix(int matrix[ROWS][COLUMNS], int score);

int main(void)
{
	int pos[ROWS][COLUMNS] = { 0 }; //말과 먹이의 위치를 나타내 줄 2차원 배열을 정의함
	int set = 0;
	int x, y;
	int count = 0;
	int score = 0;
	char input;

	srand((unsigned)time(NULL));
	
	printf("RIGHT key : k\n");
	printf("LEFT key : j\n");
	printf("UP key : i\n");
	printf("DOWN key : m\n");
	printf("QUIT : q\n");
	printf("====================\n");
	printf("Press any key to start");

	while (1)
	{
		x = rand() % 20;
		y = rand() % 80;
		if(pos[x][y] != 1)
		{
			count++;
			pos[x][y] = 1;
		}
		if (count == 6)
			break;
	}
	pos[x][y] = 2;
	
	while(1)
	{
		if (_kbhit())
		{
			input = _getch();//입력한 키의 값을 input(int형 변수)으로 지정
			if (input == 109)//'m'키를 누를 경우
			{
				if (x < 20)
				{
					pos[x][y] = 0;//원래 말의 위치를 공백으로 바꿈
					x++;
					if (pos[x][y] == 1)//원래 말의 위치보다 한 칸 아래에 먹이가 위치하면
						score += 100;//점수를 100 증가시킴
					pos[x][y] = 2;//원래 말의 위치보다 한 칸 아래의 값을 말의 위치로 바꿈
				}
			}
			else if (input == 105)//'i'키를 누를 경우
			{
				if (x > 0)
				{
					pos[x][y] = 0;//원래 말의 위치를 공백으로 바꿈
					x--;
					if (pos[x][y] == 1)//원래 말의 위치보다 한 칸 위에 먹이가 위치하면
						score += 100;//점수를 100 증가시킴
					pos[x][y] = 2;//원래 말의 위치보다 한 칸 위의 값을 말의 위치로 바꿈
				}
			}
			else if (input == 107)//'k'키를 누를 경우
			{
				if (y < 80)
				{
					pos[x][y] = 0;//원래 말의 위치를 공백으로 바꿈
					y++;
					if (pos[x][y] == 1)//원래 말의 위치보다 한 칸 오른쪽에 먹이가 위치하면
						score += 100;//점수를 100 증가시킴
					pos[x][y] = 2;//원래 말의 위치보다 한 칸 오른쪽의 값을 말의 위치로 바꿈
				}
			}
			else if (input == 106)//'j'키를 누를 경우
			{
				if (y > 0)
				{
					pos[x][y] = 0;//원래 말의 위치를 공백으로 바꿈
					y--;
					if (pos[x][y] == 1)//원래 말의 위치보다 한 칸 왼쪽에 먹이가 위치하면
						score += 100;//점수를 100 증가시킴
					pos[x][y] = 2;//원래 말의 위치보다 한 칸 왼쪽의 값을 말의 위치로 바꿈
				}
			}
			else if (input == 113)//'q'키를 누를 경우
			{
				printf("Game over by user!");
				Sleep(100);
				break;
			}
			print_matrix(pos, score);
			//500점 달성 시 게임을 종료함
			if (score == 500)
			{
				printf("Congratulations! Mission Cleared!");
				Sleep(100);
				break;
			}
		}
	}
	return 0;
}
void print_matrix(int matrix[ROWS][COLUMNS], int score)
{
	system("cls");//전체 화면을 지움(키 안내창을 지움)
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (matrix[i][j] == 0)//0일때는 공백,
				printf(" ");
			else if (matrix[i][j] == 1)//1일때는 *,
				printf("*");
			else if (matrix[i][j] == 2)//2일때는 @를 출력함
				printf("@");
		}
		printf("\n");
	}
	printf("===========================\n");
	printf("total score = %d\n", score);
}