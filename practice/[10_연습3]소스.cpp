/*--------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.11.16
11개의 int형 정수를 입력받아 가운데 값을 찾고,
그 값의 입력 순서를 출력하는 프로그램
----------------------------------------------------------------*/
#include <stdio.h>
int find_midium(int list[]);

int main(void)
{
	int list1[11];
	printf("11개의 int형 정수를 입력하시오:\n");
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
		//담겨 있는 수 중 최소값을 찾는다.
		minimum = j;
		for (int i = j+1; i < 11; i++)
			if (list[i] < list[minimum])
				minimum = i;
		
		//list[j]와 list[minimum]을 서로 교환한다.
		temp = list[j];
		list[j] = list[minimum];
		list[minimum] = temp;
	}
	printf("\n가운데값 = %d", list[5]);

	for (int k = 0; k < 11; k++)
	{
		if (list[k] == list[5])
			printf("\n가운데값 순서 = %d", k);
	}

	return 0;
}

