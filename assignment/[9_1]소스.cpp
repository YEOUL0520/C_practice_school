/*--------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.03
도로망의 가로 세로 길이를 입력받아
최단거리의 길이와 그 경우의 수를 출력하는 프로그램
----------------------------------------------------*/
#include <stdio.h>

//누적 메뉴 개수와 누적 주문 금액은 전역 변수를 사용
int count_all, price_all;
int count_1, count_2, count_3;

void choose(int n);
void password_check(void);
int main(void)
{
	int number;

	//선택을 완료할때까지 계속 반복
	while (1)
	{
		printf("-------------------------------------------------------\n");
		printf("              주문할 메뉴를 선택해주세요\n");
		printf("-------------------------------------------------------\n");
		printf("              1. 아메리카노\n");
		printf("              2. 아이스티\n");
		printf("              3. 빙수\n");
		printf("              4. 선 택 완 료\n");
		printf("-------------------------------------------------------\n");
		printf("메뉴를 선택하세요 : ");
		scanf("%d", &number);

		if (number == 4)
			break;
		else
		{
			choose(number);
		}
	}
	
	printf("-------------------------------------------------------\n");
	printf("                    주문결과 조회\n");
	printf("-------------------------------------------------------\n");
	printf("아메리카노 %d개\n아이스티 %d개\n빙수 %d개\n", count_1, count_2, count_3);
	printf("총 메뉴 개수 : %d개\n", count_all);
	printf("누적 금액 : %d원\n\n", price_all);
	
	password_check();
	
	return 0;
}
//메뉴의 가격과 누적 주문 금액, 누적 메뉴 개수를 계산하는 함수
void choose(int n)
{
	
	
	int price;

	//번호를 선택할때마다 선택한 횟수의 총합, 선택에 해당되는 메뉴의 금액과 그 총합을 계산
	if (n == 1)
	{
		price = 3000;
		printf("아메리카노는 3000원 입니다.\n");
		count_1++;
		count_all++;
		price_all = price_all + 3000;
	}
	if (n == 2)
	{
		printf("아이스티는 3000원 입니다.\n");
		count_2++;
		count_all++;
		price_all = price_all + 3000;
	}
	if (n == 3)
	{
		printf("빙수는 6000원 입니다.\n");
		count_3++;
		count_all++;
		price_all = price_all + 6000;
	}
	
	//계산된 총 선택 횟수와 금액을 산출
	printf("지금까지 선택하신 메뉴의 갯수는 %d개 입니다.\n", count_all);
	printf("지금까지 선택하신 메뉴의 누적 금액은 %d원 입니다.\n", price_all);

}
//패스워드를 검사하는 함수
void password_check(void)
{
	int password,password_count;
	password_count = 0;

	while (1)
	{
		//비밀번호 시도 횟수 4회 초과시(5회부터) 종료
		if (password_count == 5)
		{
			printf("로그인 시도 횟수를 초과하였습니다. 다음에 주문해 주시기 바랍니다.");
			break;
		}
		else
		{
			printf("결제 번호 입력 : ");
			scanf("%d", &password);
			password_count++;
			//비밀번호가 1234와 일치시 종료
			if (password == 1234)
			{
				printf("주문이 완료되었습니다. 이용해주셔서 감사합니다.");
				break;
			}
			//비밀번호가 1234와 일치하지 않을 경우 계속
			else
				continue;

		}
	}
}