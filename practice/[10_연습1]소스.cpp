#include <stdio.h>
#define number 10

int main(void)
{
	int i, x, search;
	int list[number];
	printf("10���� ������ �Է��ϼ���:\n");
	for (i = 0; i < number; i++)
		scanf("%d", &list[i]);

	while (1)
	{
		printf("Ž���� ���� �Է��Ͻÿ�:");
		scanf(" %d", &search);

		for (x = 0; x < number; x++)
		{
			if (search == list[x])
			{
				printf("Ž�� ���� �ε��� = %d\n\n", x);
			}
			else if (x == number-1)
				printf("%d �� �������� ����\n\n", search);
		}
		

	}
	return 0;
}