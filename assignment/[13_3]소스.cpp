/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.12.02
���� ������ ���̸� �Դ� ������ �̵� ���� ���α׷�
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
	int pos[ROWS][COLUMNS] = { 0 }; //���� ������ ��ġ�� ��Ÿ�� �� 2���� �迭�� ������
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
			input = _getch();//�Է��� Ű�� ���� input(int�� ����)���� ����
			if (input == 109)//'m'Ű�� ���� ���
			{
				if (x < 20)
				{
					pos[x][y] = 0;//���� ���� ��ġ�� �������� �ٲ�
					x++;
					if (pos[x][y] == 1)//���� ���� ��ġ���� �� ĭ �Ʒ��� ���̰� ��ġ�ϸ�
						score += 100;//������ 100 ������Ŵ
					pos[x][y] = 2;//���� ���� ��ġ���� �� ĭ �Ʒ��� ���� ���� ��ġ�� �ٲ�
				}
			}
			else if (input == 105)//'i'Ű�� ���� ���
			{
				if (x > 0)
				{
					pos[x][y] = 0;//���� ���� ��ġ�� �������� �ٲ�
					x--;
					if (pos[x][y] == 1)//���� ���� ��ġ���� �� ĭ ���� ���̰� ��ġ�ϸ�
						score += 100;//������ 100 ������Ŵ
					pos[x][y] = 2;//���� ���� ��ġ���� �� ĭ ���� ���� ���� ��ġ�� �ٲ�
				}
			}
			else if (input == 107)//'k'Ű�� ���� ���
			{
				if (y < 80)
				{
					pos[x][y] = 0;//���� ���� ��ġ�� �������� �ٲ�
					y++;
					if (pos[x][y] == 1)//���� ���� ��ġ���� �� ĭ �����ʿ� ���̰� ��ġ�ϸ�
						score += 100;//������ 100 ������Ŵ
					pos[x][y] = 2;//���� ���� ��ġ���� �� ĭ �������� ���� ���� ��ġ�� �ٲ�
				}
			}
			else if (input == 106)//'j'Ű�� ���� ���
			{
				if (y > 0)
				{
					pos[x][y] = 0;//���� ���� ��ġ�� �������� �ٲ�
					y--;
					if (pos[x][y] == 1)//���� ���� ��ġ���� �� ĭ ���ʿ� ���̰� ��ġ�ϸ�
						score += 100;//������ 100 ������Ŵ
					pos[x][y] = 2;//���� ���� ��ġ���� �� ĭ ������ ���� ���� ��ġ�� �ٲ�
				}
			}
			else if (input == 113)//'q'Ű�� ���� ���
			{
				printf("Game over by user!");
				Sleep(100);
				break;
			}
			print_matrix(pos, score);
			//500�� �޼� �� ������ ������
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
	system("cls");//��ü ȭ���� ����(Ű �ȳ�â�� ����)
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (matrix[i][j] == 0)//0�϶��� ����,
				printf(" ");
			else if (matrix[i][j] == 1)//1�϶��� *,
				printf("*");
			else if (matrix[i][j] == 2)//2�϶��� @�� �����
				printf("@");
		}
		printf("\n");
	}
	printf("===========================\n");
	printf("total score = %d\n", score);
}