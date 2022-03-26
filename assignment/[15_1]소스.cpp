/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.12.01
최종 수정일 : 2021.12.02
외부 텍스트 파일을 이용해 상품 주문 영수증을 작성하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	char fname[100];
	char name[100];
	int price, discount_rate, total, discount;
	float f_discount_rate;

	printf("파일 이름을 입력해주세요.: ");
	scanf("%s", fname);

	printf("----------------메뉴판---------------\n");
	printf("1. 사과 1000원 할인율 10%%\n");
	printf("2. 배 2000원 할인율 5%%\n");
	printf("3. 버섯 2600원 할인율 10%%\n");
	printf("4. 오렌지주스 1300원 할인율 5%%\n");
	printf("5. 코카콜라 1400원 할인율 10%%\n");
	printf("6. 필통 3000원 할인율 20%%\n");
	printf("7. 마스크 800원 할인율 5%%\n");
	printf("------------------------------------\n");

	//txt파일을 읽기 모드로 불러옴
	if ((fp = fopen(fname, "w")) == NULL)
	{
		//파일을 열지 못할 경우 exit()를 호출해 프로그램 종료
		fprintf(stderr, "%s파일을 열 수 없습니다.\n", fname);
		exit(1);
	}
	
	while (1)
	{
		//상품 이름, 가격, 할인율을 입력받아 txt파일에 저장
		printf("상품, 가격, 할인율을 입력해주세요. (종료는 0) : ");
		scanf("%s", name);
		printf("\n");

		//0을 입력받을경우 값 입력 종료
		if (name[0] == '0')
			break;

		scanf("%d %d", &price, &discount_rate);
		//txt파일에는 float형식으로 출력되어야 하므로 형을 변환해줌
		f_discount_rate = (float)discount_rate;
		fprintf(fp, "%s %d %f\n", name, price, f_discount_rate);
		
	}
	fclose(fp);

	//txt파일을 읽기 모드로 불러옴
	if ((fp = fopen(fname, "r")) == NULL)
	{
		//파일을 열지 못할 경우 exit()를 호출해 프로그램 종료
		fprintf(stderr, "%s파일을 열 수 없습니다.\n", fname);
		exit(1);
	}
	
	//각 변수를 초기화
	total = 0;
	discount = 0;
	int k = 0;
	int t = 0;

	//txt파일에서 가격과 할인율을 읽어 총 금액과 할인받은 금액을 구함
	while (!feof(fp))
	{
		fscanf(fp, "%s %d %f\n", name, &price, &f_discount_rate);
		discount += ((price / 100) * f_discount_rate);
		total += price - ((price / 100) * f_discount_rate);
	}
	
	k = discount - ((price / 100) * f_discount_rate);
	t = total - (price - ((price / 100) * f_discount_rate));
	
	printf("지불하실 총 금액은 %d원 으로, %d원 할인 받으셨습니다.", t, k);
	fclose(fp);
	return 0;
}