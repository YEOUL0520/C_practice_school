/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.23
����� �̿��� �̿� ���� ������������ Ǫ�� ���α׷�
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

    printf("ù��° 1�� �������� �Է��Ͻÿ�(��: 1 x + 2 y = 1)\n");
    scanf("%f %c %c %f %c %c %f", &A[0][0], &x1, &p1, &A[0][1], &y1, &q1, &B[0]);

    printf("�ι�° 1�� �������� �Է��Ͻÿ�(��: 1 x + 2 y = 1)\n");
    scanf("%f %c %c %f %c %c %f", &A[1][0], &x2, &p2, &A[1][1], &y2, &q2, &B[1]);

    //��ȣ�� -�� ��� ������ ���� ���������� �ٲ�
    if (p1 == '-')
        A[0][1] = A[0][1] * (-1);
    if (p2 == '-')
        A[1][1] = A[1][1] * (-1);

    //��Ľ��� 0�� ��� �ذ� ������ ���ų� �ذ� �������� ����
    if (determinant(A) == 0)
    {
        if (B[0] == B[1])

            printf("�ذ� ������ ����.\n");

        else

            printf("�ذ� �������� ����.\n");
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
//��Ľ��� ���ϴ� �Լ�
float determinant(float A[2][2])
{
    float k;
    k = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    return k;
}
//������� ���ϴ� �Լ�
void matrix_inverse(float A[2][2], float A_inv[2][2])
{
    A_inv[0][0] = A[1][1] / determinant(A);
    A_inv[0][1] = A[0][1] * (-1) / determinant(A);
    A_inv[1][0] = A[1][0] * (-1) / determinant(A);
    A_inv[1][1] = A[0][0] / determinant(A);
}