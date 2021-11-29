/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.23
최종 수정일 : 2021.11.29
비밀번호의 변경을 허용하는 비밀번호 기반 인증 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int change_password(char* password);
int authentication(char* password);

int main(void)
{
	int choice;//choice로 메뉴 선택값을 받음
	char key[100] = { "1234" };//초기비밀번호는 1234로 지정

	while (1)
	{
		printf("1: change password\n");
		printf("2: authentication\n");
		printf("Made selection: ");
		scanf("%d", &choice);

		if (choice == 1)//1번을 선택할 경우 비밀번호 변경 모드 실행
		{
			change_password(key);
		}
		else if (choice == 2)//2번을 선택할 경우 비밀번호 인증 모드 실행
		{
			//authentication이 결과값 0을 반환 시 종료
			if (authentication(key) == 0)
				break;
		}

	}

	return 0;

}
//비밀번호를 변경해주는 함수
int change_password(char* password)
{
	char list[100] = { 0 };//입력받은 비밀번호

	printf("Enter the current password: ");
	getchar();
	gets_s(list, 100);//현재 비밀번호를 입력받음

	//입력받은 비밀번호와 현재 비밀번호를 비교해 같을 경우 새 비밀번호를 입력할 수 있음
	if (strcmp(list, password) == 0)
	{
		printf("Enter new password: ");
		gets_s(password, 100);//새 비밀번호를 입력받음
		printf("Password updated:");
		puts(password);//입력받은 새 비밀번호를 출력
		printf("\n");

	}
	else
	{
		printf("Your password is incorrect!\n\n");
	}

	return 0;
}
//비밀번호를 인증해주는 함수
int authentication(char* password)
{
	char list[100] = { 0 };//입력받은 비밀번호
	int incorrect_number = 0;//틀린 비밀번호 개수

	printf("Enter the password: ");
	getchar();
	gets_s(list, 100);//비밀번호를 입력받음

	//입력받은 비밀번호와 현재 비밀번호를 비교
	if (strcmp(list, password) == 0)
	{
		printf("Your password is correct!\n");
		printf("You can access the syetem.");
		return 0;//같을 경우에만 0값을 반환한다.
	}
	else
	{
		printf("Your password is incorrect!\n");

		int i;

		for (i = 0; list[i] != NULL; i++)
		{
			//입력받은 비밀번호와 현재 비밀번호 각각을 비교해 다를 경우, incorrect_number의 개수를 센다.
			if (list[i] != password[i])
				incorrect_number++;
		}

		printf("Password is different by %d characters.\n\n", incorrect_number);
		//값을 반환하지 않고 선택창으로 되돌아간다.

	}

}

