/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.11.03
도로망의 가로 세로 길이를 입력받아
최단거리의 길이와 그 경우의 수를 출력하는 프로그램
------------------------*/
#include <stdio.h>

long long factorial(long long n);

int main()
{
    //overflow막기위해 long long형 사용
    long long length;
    long long width;

    //값 범위 벗어나면 조건 충족시까지 계속 반복
    while (1)
    {
        printf("도로망의 가로 길이와 세로 길이를 정수의 형태로 입력해주세요 : ");
        scanf("%lld %lld", &length, &width);
        if (length <= 0 || width <= 0)
        {
            printf("가로와 세로의 길이는 1이상의 정수입니다. 다시 입력해주세요.\n\n");
            continue;
        }
        if (2 > length + width && length + width > 20)
        {
            printf("최단거리의 범위는 20이하 입니다. 다시 입력해주세요.\n\n");
            continue;
        }
        else
            break;
    }
    //최단거리와 그 경우의 수 산출
    printf("\n도로망의 최단거리 (%lld)\n", (length + width));
    printf("도로망에서 최단거리로 목적지로 갈 수 있는 경우의 수 : %lld\n", (factorial(length + width) / (factorial(length) * factorial(width))));
}

//팩토리얼 함수
long long factorial(long long n)
{
    if (n <= 1)
        return 1;
    else
        return (n * factorial(n - 1));
}