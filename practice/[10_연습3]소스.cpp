/*--------------------------------------------------------------
�ۼ��� : 22112144 ��ȿ��
��¥ : 2021.11.16
11���� int�� ������ �Է¹޾� ��� ���� ã��,
�� ���� �Է� ������ ����ϴ� ���α׷�
----------------------------------------------------------------*/
#include <stdio.h>
int find_midium(int list[]);

int main(void)
{
	int list1[11];
	printf("11���� int�� ������ �Է��Ͻÿ�:\n");
	for(int i=0; i<11; i++)
		scanf("%d", &list1[i]);

	find_midium(list1);

	return 0;
}
int find_midium(int list[])
{
	int minimum, temp;
	
	for (int j = 0; j < 10; j++)
	{
		//��� �ִ� �� �� �ּҰ��� ã�´�.
		minimum = j;
		for (int i = j+1; i < 11; i++)
			if (list[i] < list[minimum])
				minimum = i;
		
		//list[j]�� list[minimum]�� ���� ��ȯ�Ѵ�.
		temp = list[j];
		list[j] = list[minimum];
		list[minimum] = temp;
	}
	printf("\n����� = %d", list[5]);

	for (int k = 0; k < 11; k++)
	{
		if (list[k] == list[5])
			printf("\n����� ���� = %d", k);
	}

	return 0;
}

