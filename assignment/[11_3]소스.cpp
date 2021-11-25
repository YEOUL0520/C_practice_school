/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.23
행렬을 이용해 이원 일차 연립방정식을 푸는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>

float determinant(float A[2][2]);
void matrix_inverse(float A[2][2], float A_inv[2][2]);

int main(void)
{
    char x1, x2, y1, y2;
    char p1, p2, q1, q2;

    float A[2][2] = { 0 };
    float B[2] = { 0 };
    float inverse_A[2][2] = { 0 };

    float solution_x, solution_y = 0;

    printf("첫번째 1차 방정식을 입력하시오(예: 1 x + 2 y = 1)\n");
    scanf("%f %c %c %f %c %c %f", &A[0][0], &x1, &p1, &A[0][1], &y1, &q1, &B[0]);

    printf("두번째 1차 방정식을 입력하시오(예: 1 x + 2 y = 1)\n");
    scanf("%f %c %c %f %c %c %f", &A[1][0], &x2, &p2, &A[1][1], &y2, &q2, &B[1]);

    //부호가 -일 경우 원래의 값을 음수값으로 바꿈
    if (p1 == '-')
        A[0][1] = A[0][1] * (-1);
    if (p2 == '-')
        A[1][1] = A[1][1] * (-1);

    //행렬식이 0일 경우 해가 무수히 많거나 해가 존재하지 않음
    if (determinant(A) == 0)
    {
        if (B[0] == B[1])

            printf("해가 무수히 많음.\n");

        else

            printf("해가 존재하지 않음.\n");
    }

    else
    {
        matrix_inverse(A, inverse_A);
        solution_x = (inverse_A[0][0] * B[0]) + (inverse_A[0][1] * B[1]);
        solution_y = (inverse_A[1][0] * B[0]) + (inverse_A[1][1] * B[1]);

        printf("=================================================\n");
        printf("x = %f, y = %f", solution_x, solution_y);
    }

}
//행렬식을 구하는 함수
float determinant(float A[2][2])
{
    float k;
    k = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    return k;
}
//역행렬을 구하는 함수
void matrix_inverse(float A[2][2], float A_inv[2][2])
{
    A_inv[0][0] = A[1][1] / determinant(A);
    A_inv[0][1] = A[0][1] * (-1) / determinant(A);
    A_inv[1][0] = A[1][0] * (-1) / determinant(A);
    A_inv[1][1] = A[0][0] / determinant(A);
}