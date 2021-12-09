#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void print_RSP(int d, int x);
int human_choose, cpu_choose, result;

int main(void)
{
	int count = 0, loose = 0;
	float victory;

	srand((unsigned)time(NULL));

	printf("컴퓨터와 다른 것을 낼 때까지 반복해 50%%의 승률을 기록하시오!(3번의 목숨이 존재합니다.)\n");
	while (1)
	{
		printf("\n묵(1) 찌(2) 빠(3) 중에서 하나를 선택 하시오 : ");
		scanf("%d", &human_choose);
		printf("#############################\n");
		cpu_choose = rand() % 3 + 1;
		result = cpu_choose - human_choose;
		if (human_choose == 1)
		{
			if (result == 1)
			{
				printf("승리하였습니다.\n");
				print_RSP(human_choose, cpu_choose);
			}
			else
			{
				printf("당신은 패배하였습니다.\n");
				print_RSP(human_choose, cpu_choose);
				loose++;
			}
			
		}
		else if (human_choose == 2)
		{
			if (result == 1)
			{
				printf("승리하였습니다.\n");
				print_RSP(human_choose, cpu_choose);
			}
			else
			{
				printf("당신은 패배하였습니다.\n");
				print_RSP(human_choose, cpu_choose);
				loose++;
			}
		}
		else if (human_choose == 3)
		{
			if (result == -2)
			{
				printf("승리하였습니다.\n");
				print_RSP(human_choose, cpu_choose);
			}
			else
			{
				printf("당신은 패배하였습니다.\n");
				print_RSP(human_choose, cpu_choose);
				loose++;
			}
		}
		else
			continue;
		count++;
		printf("상대방이 계속 공격합니다.\n");
		printf("#############################\n");
		if (loose == 3)
			break;
	}
	victory = ((float)(count - loose) / (float)count) * 100;
	printf("당신의 승률은 %.2f%%입니다. 축하합니다.", victory);

	return 0;
}