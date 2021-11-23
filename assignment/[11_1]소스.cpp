/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.17
최종 수정 : 2021.11.23
입력받은 문자열을 알파벳 출현 빈도수에 따라 정렬 및 출력하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>

void swap_num(int* n1, int* n2);
void swap_char(char* n1, char* n2);

int main(void)
{
	int number;

	printf("<<문자열 분석 프로그램>>\n");

	//0을 누를때까지 무한반복
	while (1)
	{
		
		printf("========================\n");
		printf("1. 문자열 분석\n");
		printf("0. 프로그램 종료\n");
		printf("========================\n");
		printf("번호 입력 : ");
		scanf("%d", &number);

		if (number == 1)
		{
			char list[100];
			printf("분석할 문자열 입력: ");
			scanf("%s", list);

			int size = 0;
			//입력된 문자열의 길이를 size에 지정
			for (int k = 0; k < 100; k++)
				if (list[k] == NULL)
					break;
				else
					size++;

			int i, k;
			int alpa_count[26] = { 0 };
			char beta_count[26] = { 0 };
			//각 알파벳의 출현 빈도수를 셀 배열 alpa_count
			for (i = 0; i < size; i++)
			{
				alpa_count[list[i] - 'a']++;
			}
			//각 알파벳을 출현 빈도수대로 정렬할 배열 beta_count
			for (int a = 0; a < 26; a++)
			{
				beta_count[a] = 'a' + a;
			}

			int max, temp;

			//swap함수를 이용해 출현 빈도수가 높은 순대로 alpa_count와 beta_count를 정렬
			for (int j = 0; j < 25; j++)
			{
				max = j;
				for (int i = j + 1; i < 26; i++)
					if (alpa_count[i] > alpa_count[max])
						max = i;
				swap_num(&alpa_count[j], &alpa_count[max]);
				swap_char(&beta_count[j], &beta_count[max]);

			}

			//정렬한 값을 출력
			printf("\n출연 빈도수가 높은 5개의 알파벳\n");
			for (int print = 0; print < 5; print++)
				printf("%d         %c         %d개\n", print + 1, beta_count[print], alpa_count[print]);
			printf("\n\n");
		}
		else
			break;
	}

	return 0;
}
void swap_num(int* n1, int* n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
void swap_char(char* n1, char* n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}