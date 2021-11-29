/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.23
���� ������ : 2021.11.29
��й�ȣ�� ������ ����ϴ� ��й�ȣ ��� ���� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int change_password(char* password);
int authentication(char* password);

int main(void)
{
	int choice;//choice�� �޴� ���ð��� ����
	char key[100] = { "1234" };//�ʱ��й�ȣ�� 1234�� ����

	while (1)
	{
		printf("1: change password\n");
		printf("2: authentication\n");
		printf("Made selection: ");
		scanf("%d", &choice);

		if (choice == 1)//1���� ������ ��� ��й�ȣ ���� ��� ����
		{
			change_password(key);
		}
		else if (choice == 2)//2���� ������ ��� ��й�ȣ ���� ��� ����
		{
			//authentication�� ����� 0�� ��ȯ �� ����
			if (authentication(key) == 0)
				break;
		}

	}

	return 0;

}
//��й�ȣ�� �������ִ� �Լ�
int change_password(char* password)
{
	char list[100] = { 0 };//�Է¹��� ��й�ȣ

	printf("Enter the current password: ");
	getchar();
	gets_s(list, 100);//���� ��й�ȣ�� �Է¹���

	//�Է¹��� ��й�ȣ�� ���� ��й�ȣ�� ���� ���� ��� �� ��й�ȣ�� �Է��� �� ����
	if (strcmp(list, password) == 0)
	{
		printf("Enter new password: ");
		gets_s(password, 100);//�� ��й�ȣ�� �Է¹���
		printf("Password updated:");
		puts(password);//�Է¹��� �� ��й�ȣ�� ���
		printf("\n");

	}
	else
	{
		printf("Your password is incorrect!\n\n");
	}

	return 0;
}
//��й�ȣ�� �������ִ� �Լ�
int authentication(char* password)
{
	char list[100] = { 0 };//�Է¹��� ��й�ȣ
	int incorrect_number = 0;//Ʋ�� ��й�ȣ ����

	printf("Enter the password: ");
	getchar();
	gets_s(list, 100);//��й�ȣ�� �Է¹���

	//�Է¹��� ��й�ȣ�� ���� ��й�ȣ�� ��
	if (strcmp(list, password) == 0)
	{
		printf("Your password is correct!\n");
		printf("You can access the syetem.");
		return 0;//���� ��쿡�� 0���� ��ȯ�Ѵ�.
	}
	else
	{
		printf("Your password is incorrect!\n");

		int i;

		for (i = 0; list[i] != NULL; i++)
		{
			//�Է¹��� ��й�ȣ�� ���� ��й�ȣ ������ ���� �ٸ� ���, incorrect_number�� ������ ����.
			if (list[i] != password[i])
				incorrect_number++;
		}

		printf("Password is different by %d characters.\n\n", incorrect_number);
		//���� ��ȯ���� �ʰ� ����â���� �ǵ��ư���.

	}

}

