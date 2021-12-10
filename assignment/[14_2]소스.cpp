/*----------------------------------------------------------------------------------
작성자 : 22112144 류효정
날짜 : 2021.12.02
지원자의 이름, 학점, 자격증 소지 여부, 토익점수를 분석하고 기준에 맞추어 출력하는 프로그램
------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#define SIZE 30

typedef struct applicants
{
	char name[10];
	double grade;
	char get;
	int point;
} APPLICANTS; //지원자의 자격 요건에 대한 구조체를 정의하고 새로운 자료형 APPLICANTS로 선언함

void quality_test(APPLICANTS list[30], int n);
int selection_cort_grade(APPLICANTS* a, int n);
void print_list(APPLICANTS* list, int n);

//전역변수로 지정
int count = 0;
double sum = 0;

int main(void)
{
	int choice, number, j;
	APPLICANTS list[SIZE];
	
	while (1)
	{
		printf("===========================\n");
		printf("0. 지원자 분석\n");
		printf("1. 종료\n");
		printf("===========================\n");
		printf("입력 : ");
		scanf("%d", &choice);


		if (choice == 0)
		{
			printf("지원자 수를 입력하세요. : ");
			scanf("%d", &number);
			printf("지원자의 이름, 학점, 자격증 소지 여부, 토익점수를 순서대로 입력하세요.\n");

			int i = 0;

			while (i < number)//지원자의 수만큼 배열 구조체를 입력받음
			{
				printf("입력 : ");
				scanf("%s %lf %c %d", list[i].name, &list[i].grade, &list[i].get, &list[i].point);
				i++;
			}

			quality_test(list, number);//지원자들의 지원자격을 테스트함

			printf("\n\n지원자 명단 : \n");
			printf("===========================\n");
			printf("내림차순으로 출력\n");
			printf("===========================\n");
			printf("         이름       학점        소지     토익점수\n");

			if (selection_cort_grade(list, number) == 2)//내림차순으로 정렬이 완료되었을 경우
			{
				print_list(list, number);//list를 출력
			}

			printf("지원자격을 충족하는 학생의 수는 %d입니다.\n", count);//지원자격을 충족하는 학생수 출력
			printf("지원자격을 충족하는 학생들의 평균학점은 %.2lf이다.\n", sum / count);//지원자격을 충족하는 학생들의 평균학점 출력
		}
		else if (choice == 1)
			break;
	}
	return 0;
}
//지원자격을 테스트하는 함수
void quality_test(APPLICANTS list[30], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (list[i].point < 500)//점수 기준을 충족하지 못할 경우 값을 0으로 만듦
			list[i].point = 0;
	}

	int t;
	for (t = 0; t < n; t++)
	{
		if (list[t].get != 'o')//자격증을 소지하지 않을 경우 값을 0으로 바꿈
			list[t].get = NULL;
	}
}
//선택 정렬을 사용해서 내림차순으로 정렬하는 함수
int selection_cort_grade(APPLICANTS* a, int n)
{
	int max;
	APPLICANTS temp;

	for (int l = 0; l < n-1; l++)
	{
		max = l;
		for (int i = l+1; i < n; i++)
			if (a[i].grade > a[max].grade)
				max = i;
		temp = a[l];
		a[l] = a[max];
		a[max] = temp;
	}

	return 2;
}
//APPLICANTS배열을 출력하는 함수
void print_list(APPLICANTS* list, int n)
{
	count = 0;
	sum = 0;

	for (int i = 0; i < n; i++)
	{
		//자격을 충족하지 않는 경우의 값을 전부 0으로 바꿔주었으므로 0이 나오지 않을 경우에만 print함
		if (list[i].point == 0 || list[i].get == NULL)
		{
			continue;
		}
		else
		{
			sum += list[i].grade; //지원자격을 충족하는 경우 학점을 총합에 합산
			count++;//지원자격을 충족하는 학생의 수를 셈
			printf("%d. %10s %10.2lf %10c %10d\n", i + 1, list[i].name, list[i].grade, list[i].get, list[i].point);//지원자격을 충족한 경우 print해줌
		}
	} 
}

