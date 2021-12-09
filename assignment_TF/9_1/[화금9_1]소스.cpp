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

	printf("��ǻ�Ϳ� �ٸ� ���� �� ������ �ݺ��� 50%%�� �·��� ����Ͻÿ�!(3���� ����� �����մϴ�.)\n");
	while (1)
	{
		printf("\n��(1) ��(2) ��(3) �߿��� �ϳ��� ���� �Ͻÿ� : ");
		scanf("%d", &human_choose);
		printf("#############################\n");
		cpu_choose = rand() % 3 + 1;
		result = cpu_choose - human_choose;
		if (human_choose == 1)
		{
			if (result == 1)
			{
				printf("�¸��Ͽ����ϴ�.\n");
				print_RSP(human_choose, cpu_choose);
			}
			else
			{
				printf("����� �й��Ͽ����ϴ�.\n");
				print_RSP(human_choose, cpu_choose);
				loose++;
			}
			
		}
		else if (human_choose == 2)
		{
			if (result == 1)
			{
				printf("�¸��Ͽ����ϴ�.\n");
				print_RSP(human_choose, cpu_choose);
			}
			else
			{
				printf("����� �й��Ͽ����ϴ�.\n");
				print_RSP(human_choose, cpu_choose);
				loose++;
			}
		}
		else if (human_choose == 3)
		{
			if (result == -2)
			{
				printf("�¸��Ͽ����ϴ�.\n");
				print_RSP(human_choose, cpu_choose);
			}
			else
			{
				printf("����� �й��Ͽ����ϴ�.\n");
				print_RSP(human_choose, cpu_choose);
				loose++;
			}
		}
		else
			continue;
		count++;
		printf("������ ��� �����մϴ�.\n");
		printf("#############################\n");
		if (loose == 3)
			break;
	}
	victory = ((float)(count - loose) / (float)count) * 100;
	printf("����� �·��� %.2f%%�Դϴ�. �����մϴ�.", victory);

	return 0;
}