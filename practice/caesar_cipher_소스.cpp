#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* key;
	int SIZE, number;

	printf("���ڿ��� ũ��: ");
	scanf("%d", &SIZE);

	key = (char*)malloc(sizeof(char) * SIZE+1);

	printf("��ȣȭ�� ���ڿ�: ");
	scanf("%s", key);
	
	/*for (int p = 0; p < in_size; p++)
		scanf("%c", &key[p]);*/

	printf("������ ����: ");
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
			printf("���� ���� ���ڿ�: ");
			printf("%s", key);
			printf("\n");
		}
	}
	free(key);
	return 0;
}
