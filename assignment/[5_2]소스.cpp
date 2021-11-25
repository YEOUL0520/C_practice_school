/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.10.06
버스 카드 잔액과 나이를 입력하면
요금과 차액, 사용 가능 횟수를 표시하는 프로그램
------------------------*/
#include <stdio.h>

int main(void)
{
	int money, age, bill;
	int x, y;

	printf("소유 잔액 입력:");
	scanf("%d", &money);

	if (money > 0)
	{
		printf("나이 입력:");
		scanf("%d", &age);

		//입력한 나이에 따라 요금을 설정하고, 잔액에서 요금을 뺀 차액과 사용 가능 횟수를 계산하여 산출
		if (0 <= age && age < 7) //나이가 0보다 크거나 같으면서 7보다 작아야하므로 AND연산자(&&)사용
		{
			bill = 0;
			if (money > bill)
				printf("유아 요금은 0원입니다.\n영유아는 요금 부과가 없습니다.");
			else
				printf("교통비를 지불할 수 없습니다.\n현재 잔액은 %d원입니다.", money);

		}
		else if (7 <= age && age < 13)
		{
			bill = 450;
			x = money - bill;
			y = x / bill;
			if (money > bill)
				printf("어린이 요금은 450원입니다.\n남은 잔액은 %d원 남았습니다.\n앞으로 사용 가능한 횟수는 %회 입니다.", x, y);
			else
				printf("교통비를 지불할 수 없습니다.\n현재 잔액은 %d원입니다.", money);

		}
		else if (13 <= age && age < 19)
		{
			bill = 720;
			x = money - bill;
			y = x / bill;
			if (money > bill)
				printf("청소년 요금은 720원입니다.\n남은 잔액은 %d원 남았습니다.\n앞으로 사용 가능한 횟수는 %d회 입니다.", x, y);
			else
				printf("교통비를 지불할 수 없습니다.\n현재 잔액은 %d원입니다.", money);

		}
		else if (age >= 19)
		{
			bill = 1200;
			x = money - bill;
			y = x / bill;
			if (money > bill)
				printf("성인 요금은 1200원입니다.\n남은 잔액은 %d원 남았습니다.\n앞으로 사용 가능한 횟수는 %d회 입니다.", x, y);
			else
				printf("교통비를 지불할 수 없습니다.\n현재 잔액은 %d원입니다.", money);

		}
		//나이가 음수값일수는 없으므로 허용되지 않은 값을 출력한다.
		else
			printf("%d가 입력되었습니다. 입력된 나이가 허용되지 않은 값입니다.", age);
	}

	//금액이 음수값일수는 없으므로 허용되지 않은 값을 출력한다.
	else
		printf("%d가 입력되었습니다. 입력된 잔액이 허용되지 않은 값입니다.", money);

	return 0;

}