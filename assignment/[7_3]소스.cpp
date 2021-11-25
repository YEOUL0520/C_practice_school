/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.11.02
알파벳 소문자 중 하나를 입력받아
그 알파벳부터 순서대로 화면을 이동하며 출력하는 프로그램
------------------------*/

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void print_alpha(int x, int y, char a);
int main(void)
{
    char a;
    int x = 0, y = 0;

    while (1)
    {
        printf("알파벳을 입력하시오(a~z):");
        scanf(" %c", &a);
        //소문자일 경우엔 반복 종료(소문자 아닐 경우 다시 입력받음)
        if (a >= 'a' && a <= 'z')
            break;
    }

    print_alpha(x, y, a);

}

void print_alpha(int x, int y, char a)
{
    //키보드 누를때까지 반복
    while (!_kbhit())
    {
        if (a == 'z')
        {
            a -= 26;
        }
        else
        {
            a++;
            for (int k = 0; k < y; k++)
            {
                printf("\n");
            }
            for (int z = 0; z < x; z++)
            {
                printf(" ");
            }
            printf("%c", a);
            Sleep(50);
            system("cls");
            x += 1;
        }
        
        //50번 출력 후 다음 줄로 넘어감
        if (x == 50)
        {
            x = 0;
            y++;
        }
    }
}