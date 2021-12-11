/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.12.11
중복없이 생성된 1~30까지의 수와 사용자가 입력한 수 6가지 수 중
몇 개의 숫자가 맞는지 확인할 수 있는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;
int list[6] = { 0 };
int lotto[6] = { 0 };

void random_number();
void lotto_number();
void check_lotto();

int main(void)
{
	srand((unsigned)time(NULL));
	random_number();
	printf("로또 번호:");
	lotto_number();
	check_lotto();
	if (count == 6)
		printf("축하합니다! 1등입니다.");
	else if (count == 5)
		printf("축하합니다! 2등입니다.");
	else if (count == 4)
		printf("축하합니다! 3등입니다.");
	else if (count == 3)
		printf("축하합니다! 4등입니다.");
	else
		printf("등수 안에 들지 못했습니다.");

	return 0;
}
void random_number()
{
	int i;
	for (i = 0; i < 6; i++)
	{
		printf("%d번째 로또 번호를 입력해주세요: ", i+1);
		scanf("%d", &list[i]);

		for (int j = 0; j < i; j++)
		{
			if (list[j] == list[i])
			{
				printf("중복없이 입력해주세요.\n");
				i--;
				break;
			}
		}
		if (list[i] > 30)
		{
			printf("1~30까지의 숫자를 입력해주세요.\n");
			i--;
			continue;
		}

	}
}
void lotto_number()
{
	for (int i = 0; i < 6; i++)
	{
		lotto[i] = rand() % 30 + 1;

		for (int j = 0; j < i; j++)
		{
			if (lotto[j] == lotto[i])
			{
				i--;
				continue;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", lotto[i]);
	}
}
void check_lotto()
{
	printf("\n맞춘 번호는 ");
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (lotto[j] == list[i])
			{
				printf("%d ", lotto[j]);
				count++;
			}
		}
	}
	if(count==0)
		printf("없습니다.");
	else
		printf("입니다.");
	printf("\n\n맟춘 개수는 %d 입니다.\n\n", count);
}