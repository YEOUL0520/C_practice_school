/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.23
최종 수정일 : 2021.11.29
임의의 문장을 입력 받은 후
그 문장을 다시 입력했을 때
오타가 있는지 없는지 점검하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	while (1)
	{
		int choice;//choice로 메뉴 선택값을 받음

		printf("======================\n");
		printf("  오타 점검 프로그램\n");
		printf("======================\n");
		printf("0. 프로그램 종료\n");
		printf("1. 프로그램 시작\n");
		printf("======================\n");
		printf("메뉴를 선택해주세요 : ");
		scanf("%d", &choice);
		printf("\n");

		if (choice == 1)
		{
			char list[30] = { 0 };//입력받는 문장
			char check[30] = { 0 };//첫번째 입력값과 비교할 문장
			printf("문장을 입력해주세요(최대길이 30) : ");
			getchar();
			gets_s(list, 30);//30개의 값을 가지는 배열list를 입력받음
			printf("\n\n문장 : ");
			puts(list);//입력받은 배열 list를 출력
			while (1)
			{
				printf("\n입력 : ");
				//getchar();
				gets_s(check, 30);//30개의 값을 가지는 배열 check를 입력받음

				//list와 check를 strcmp를 이용해 비교
				if (strcmp(list, check) == 0)//list와 check 문자열이 같을 때 (strcmp 값이 0이면 두 문자열이 같음)
				{
					printf("\n\n오타가 없습니다.\n\n");
					break;
				}
				else
				{
					printf("\n오타가 있습니다.");
					printf("\n다시 입력해주세요.\n");
				}
			}
		}
		else
			break;
	}
}

