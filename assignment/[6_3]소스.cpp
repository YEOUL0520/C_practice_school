/*----------------------
작성자 : 22112144 류효정
날짜 : 2021.10.19
색 종류의 개수를 입력받아 
조건을 만족하며 색을 채우는 모든 방법과 
전체 가짓수를 찾아내는 프로그램
------------------------*/
#include <stdio.h>

int main(void)
{
	int A, number = 0;
	int a, b, c, d = 0;

	printf("- number of colors (2 ~ 4) : ");
	scanf_s("%d", &A);

	
	if (A == 2) 
	{
		printf("Coloring is not possible with 2 colors!\n");
	}
	else if (A == 3 || A== 4)
	{
		for (a = 1; a <= A; a++)
			for (b = 1; b <= A; b++)
				for (c = 1; c <= A; c++)
					for (d = 1; d <= A; d++) 
					{
						if ((a != b) && (a != c) && (a != d) && (b != d) && (c != d))
						{
							number++;

							printf("%2d: (1):", number);
							if (a == 1) { printf("R "); }
							else if (a == 2) { printf("G "); }
							else if (a == 3) { printf("B "); }
							else if (a == 4) { printf("Y "); }

							printf("(2):");
							if (b == 1) { printf("R "); }
							else if (b == 2) { printf("G "); }
							else if (b == 3) { printf("B "); }
							else if (b == 4) { printf("Y "); }

							printf("(3):");
							if (c == 1) { printf("R "); }
							else if (c == 2) { printf("G "); }
							else if (c == 3) { printf("B "); }
							else if (c == 4) { printf("Y "); }

							printf("(4):");
							if (d == 1) { printf("R \n"); }
							else if (d == 2) { printf("G \n"); }
							else if (d == 3) { printf("B \n"); }
							else if (d == 4) { printf("Y \n"); }

						}
					}

		printf("- Total number of coloring: %d\n", number);
	}
	return 0;
}