/*----------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.02
���ĺ� �ҹ��� �� �ϳ��� �Է¹޾�
�� ���ĺ����� ������� ȭ���� �̵��ϸ� ����ϴ� ���α׷�
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
        printf("���ĺ��� �Է��Ͻÿ�(a~z):");
        scanf(" %c", &a);
        //�ҹ����� ��쿣 �ݺ� ����(�ҹ��� �ƴ� ��� �ٽ� �Է¹���)
        if (a >= 'a' && a <= 'z')
            break;
    }

    print_alpha(x, y, a);

}

void print_alpha(int x, int y, char a)
{
    //Ű���� ���������� �ݺ�
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
        
        //50�� ��� �� ���� �ٷ� �Ѿ
        if (x == 50)
        {
            x = 0;
            y++;
        }
    }
}