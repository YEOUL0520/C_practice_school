/*--------------------------------------------------------------
작성자 : 22112144 류효정
작성한 날짜 : 2021.11.11
마지막 수정일 : 2021.11.15
입력받은 시저 암호문을 복호화하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#define SIZE 15

int main(void)
{

	char key[SIZE];
	int number;

	//암호문을 입력받는다.
	printf("암호화된 문자열: ");
	for (int p = 0; p < SIZE; p++)
		scanf("%c", &key[p]);

	int a, b, count;
	count = 0;

	for (a = 0; a < 26; a++)
	{
		for (b = 0; b < SIZE; b++)
		{
			//key[b]의 인덱스 값이 z일 경우 다시 a로 되돌아가야 한다.
			if (key[b] == 'z')
				key[b] = 'a';
			//그 외의 경우 key[b]의 인덱스 값에 1을 더하는 과정을 a번 반복한다.
			else
				key[b] = key[b] + 1;
		}
		
		for (b = 0; b < SIZE; b++)
		{
			//key[b]의 인덱스 값이 모음일 경우 count를 통해 그 수를 세아려준다.
			if (key[b] == 'a' || key[b] == 'e' || key[b] == 'i' || key[b] == 'o' || key[b] == 'u')
				count++;
		}
		if (count == 6)//모음의 개수가 6개일때 원본 가능 문자열을 출력한다.
		{
			printf("원본 가능 문자열: ");
			for (b = 0; b < SIZE; b++)
				printf("%c", key[b]);
			printf("\n");
		}

	}

	return 0;
}
