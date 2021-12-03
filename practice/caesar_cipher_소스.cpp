#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* key;
	int SIZE, number;

	printf("문자열의 크기: ");
	scanf("%d", &SIZE);

	key = (char*)malloc(sizeof(char) * SIZE+1);

	printf("암호화된 문자열: ");
	scanf("%s", key);
	
	/*for (int p = 0; p < in_size; p++)
		scanf("%c", &key[p]);*/

	printf("모음의 개수: ");
	scanf("%d", &number);

	int a, b, count;
	count = 0;

	for (a = 0; a < 26; a++)
	{
		for (b = 0; b < SIZE; b++)
		{
			if (key[b] == 'z')
				key[b] = 'a';
			else
				key[b] = key[b] + 1;
		}
		count = 0;
		for (int x = 0; x < SIZE; x++)
		{
			if (key[x] == 'a' || key[x] == 'e' || key[x] == 'i' || key[x] == 'o' || key[x] == 'u')
				count++;
		}


		if (count == number)
		{
			printf("원본 가능 문자열: ");
			printf("%s", key);
			printf("\n");
		}
	}
	free(key);
	return 0;
}
