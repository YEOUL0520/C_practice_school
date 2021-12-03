#include <stdio.h>
#define number 10

int main(void)
{
	int i, x, search;
	int list[number];
	printf("10개의 정수를 입력하세요:\n");
	for (i = 0; i < number; i++)
		scanf("%d", &list[i]);

	while (1)
	{
		printf("탐색할 값을 입력하시오:");
		scanf(" %d", &search);

		for (x = 0; x < number; x++)
		{
			if (search == list[x])
			{
				printf("탐색 성공 인덱스 = %d\n\n", x);
			}
			else if (x == number-1)
				printf("%d 가 존재하지 않음\n\n", search);
		}
		

	}
	return 0;
}