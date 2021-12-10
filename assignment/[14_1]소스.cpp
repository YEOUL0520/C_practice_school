/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.12.02
구조체를 이용해 사용자가 직접 음식점 메뉴를 작성하고
저장된 메뉴를 선택할 수 있는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#define SIZE 2

void krmenu_writing(struct korean* k);
void chmenu_writing(struct chinese* c);
void jpmenu_writing(struct japanese* j);
//한식 메뉴를 받아오는 구조체
struct korean
{
	char name_k[100];
	int price_k;
};
//중식 메뉴를 받아오는 구조체
struct chinese
{
	char name_c[100];
	int price_c;
};
//일식 메뉴를 받아오는 구조체
struct japanese
{
	char name_j[100];
	int price_j;
};

int main(void)
{
	struct korean k[SIZE];
	struct chinese c[SIZE];
	struct japanese j[SIZE];

	printf("========= 메뉴판 작성 =========\n\n");
	krmenu_writing(k);
	chmenu_writing(c);
	jpmenu_writing(j);
	printf("\n");
	printf("========= 나만의 메뉴판 =========\n\n");
	printf("-한식-\n");
	for (int y=0; y<SIZE; y++)
		printf("%d. %s | %d원\n", y+1, k[y].name_k, k[y].price_k);
	printf("\n");
	printf("-중식-\n");
	for (int y = 0; y < SIZE; y++)
		printf("%d. %s | %d원\n", y + 3, c[y].name_c, c[y].price_c);
	printf("\n");
	printf("-일식-\n");
	for (int y = 0; y < SIZE; y++)
		printf("%d. %s | %d원\n", y + 5, j[y].name_j, j[y].price_j);
	printf("\n");

	int choice;
	while (1)
	{
		printf("주문하실 메뉴의 번호를 입력하세요 : ");
		scanf("%d", &choice);
		if (choice < 0 || choice > 6)//입력받은 메뉴가 1~6의 범위에서 벗어날 경우 다시 입력
		{
			printf("잘못된 번호입니다. 다시 입력해 주세요.\n");
			continue;
		}
		else
			break;
	}
	
	printf("주문이 완료되었습니다."); //선택한 각 번호에 맞게 음식 이름과 가격을 출력함
	if (choice == 1)
		printf("주문하신 음식은 %s이고 가격은 %d원입니다.", k[0].name_k, k[0].price_k);
	else if (choice == 2)
		printf("주문하신 음식은 %s이고 가격은 %d원입니다.", k[1].name_k, k[1].price_k);
	else if (choice == 3)
		printf("주문하신 음식은 %s이고 가격은 %d원입니다.", c[0].name_c, c[0].price_c);
	else if (choice == 4)
		printf("주문하신 음식은 %s이고 가격은 %d원입니다.", c[1].name_c, c[1].price_c);
	else if (choice == 5)
		printf("주문하신 음식은 %s이고 가격은 %d원입니다.", j[0].name_j, j[0].price_j);
	else if (choice == 6)
		printf("주문하신 음식은 %s이고 가격은 %d원입니다.", j[1].name_j, j[1].price_j);


	return 0;
}
//사용자로부터 한식 메뉴를 입력받는 함수
void krmenu_writing(struct korean* k)
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		printf("한식의 %d 번째 음식을 입력하세요 : ", i + 1);
		scanf("%s", k[i].name_k);
		printf("음식의 가격을 입력하세요 : ");
		scanf("%d", &k[i].price_k);
		printf("\n");
	}
	printf("\n");
}
//사용자로부터 중식 메뉴를 입력받는 함수
void chmenu_writing(struct chinese* c)
{
	int l;
	for (l = 0; l < SIZE; l++)
	{
		printf("중식의 %d 번째 음식을 입력하세요 : ", l + 1);
		scanf("%s", c[l].name_c);
		printf("음식의 가격을 입력하세요 : ");
		scanf("%d", &c[l].price_c);
		printf("\n");
	}
	printf("\n");
}
//사용자로부터 일식 메뉴를 입력받는 함수
void jpmenu_writing(struct japanese* j)
{
	int m;
	for (m = 0; m < SIZE; m++)
	{
		printf("일식의 %d 번째 음식을 입력하세요 : ", m + 1);
		scanf("%s", j[m].name_j);
		printf("음식의 가격을 입력하세요 : ");
		scanf("%d", &j[m].price_j);
		printf("\n");
	}
	printf("\n");
}