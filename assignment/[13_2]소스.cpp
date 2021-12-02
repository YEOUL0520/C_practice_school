/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.12.02
스트림 개념을 활용해 사용자가 입력한 값을 
텍스트 파일로 정리하여 저장하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>

int main(void)
{
	FILE* fp;
	int year, month, day, money; //날짜 및 기존 보유 자산을 입력받을 변수
	int choice;//메뉴 선택값을 입력받을 변수

	printf("가계부 작성을 시작합니다.\n\n");
	printf("날짜를 입력하세요. (예: 2020 04 13) : ");
	scanf("%d %d %d", &year, &month, &day);
	printf("\n");
	getchar();
	printf("기존 보유 자산을 입력하세요. : ");
	scanf("%d", &money);
	printf("\n");
	fp = fopen("cashbook.txt", "a");//cashbook이름의 메모장 생성
	//입력받은 날짜를 형식에 맞추어 메모장에 출력함
	fprintf(fp, "========= %d년 %d월 %d일 사용 내역 =========\n", year, month, day);
	fprintf(fp, "\n");

	//변수 선언 및 초기화
	int balance = 0;
	char income_list[100];
	int t_income_money = 0;
	int income_count = 0;
	int income_money = 0;
	char expenditure_list[100];
	int expenditure_count = 0;
	int expenditure_money = 0;
	int t_expenditure_money = 0;

	//프로그램 종료를 선택하기 전까진 계속 반복함
	while (1)
	{
		printf("입력 선택 (1. 수입액 2. 지출액 3. 프로그램 종료) : ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			//수입 내역과 금액을 입력받고 누적 수입을 계산
			printf("수입 내역을 입력하세요 : ");
			scanf("%s", income_list);
			getchar();
			printf("수입 금액을 입력하세요 : ");
			scanf("%d", &income_money);
			getchar();
			income_count++;
			t_income_money += income_money;
			printf("입력하신 누적 수입은 %d원 입니다.\n\n", t_income_money);
			//메모장에 수입 목록을 기록함
			fprintf(fp, "수입 목록 %d %s %d원\n", income_count, income_list, income_money);
		}
		else if (choice == 2)
		{
			//지출 내역과 금액을 입력받고 누적 지출을 계산
			printf("지출 내역을 입력하세요 : ");
			scanf("%s", expenditure_list);
			getchar();
			printf("지출 금액을 입력하세요 : ");
			scanf("%d", &expenditure_money);
			getchar();
			expenditure_count++;
			t_expenditure_money += expenditure_money;
			printf("입력하신 누적 지출은 %d원 입니다.\n\n", t_expenditure_money);
			//메모장에 지출 목록을 기록함
			fprintf(fp, "지출 목록 %d %s %d원\n", expenditure_count, expenditure_list, expenditure_money);
		}
		else if (choice == 3)
		{
			//총 수입과 총 지출을 메모장에 출력함
			fprintf(fp, "[합계] 수입 : %d원 지출 : %d원\n", t_income_money, t_expenditure_money);
			//잔액을 계산해 메모장에 출력하고, 금일 지출과 잔여 금액을 출력함
			balance = money + t_income_money - t_expenditure_money;
			fprintf(fp, "잔액 : %d원\n", balance);
			printf("=> 금일 지출은 %d원, 잔여 금액은 %d원 입니다.", t_expenditure_money, balance);
			break;//3번 선택시 프로그램을 종료함
		}
		else
		{
			printf("알맞은 번호를 재입력하세요.\n");
		}
	}

	fclose(fp);
	return 0;
}
