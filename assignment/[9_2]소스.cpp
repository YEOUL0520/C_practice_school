/*----------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.03
���θ��� ���� ���� ���̸� �Է¹޾�
�ִܰŸ��� ���̿� �� ����� ���� ����ϴ� ���α׷�
------------------------*/
#include <stdio.h>

long long factorial(long long n);

int main()
{
    //overflow�������� long long�� ���
    long long length;
    long long width;

    //�� ���� ����� ���� �����ñ��� ��� �ݺ�
    while (1)
    {
        printf("���θ��� ���� ���̿� ���� ���̸� ������ ���·� �Է����ּ��� : ");
        scanf("%lld %lld", &length, &width);
        if (length <= 0 || width <= 0)
        {
            printf("���ο� ������ ���̴� 1�̻��� �����Դϴ�. �ٽ� �Է����ּ���.\n\n");
            continue;
        }
        if (2 > length + width && length + width > 20)
        {
            printf("�ִܰŸ��� ������ 20���� �Դϴ�. �ٽ� �Է����ּ���.\n\n");
            continue;
        }
        else
            break;
    }
    //�ִܰŸ��� �� ����� �� ����
    printf("\n���θ��� �ִܰŸ� (%lld)\n", (length + width));
    printf("���θ����� �ִܰŸ��� �������� �� �� �ִ� ����� �� : %lld\n", (factorial(length + width) / (factorial(length) * factorial(width))));
}

//���丮�� �Լ�
long long factorial(long long n)
{
    if (n <= 1)
        return 1;
    else
        return (n * factorial(n - 1));
}