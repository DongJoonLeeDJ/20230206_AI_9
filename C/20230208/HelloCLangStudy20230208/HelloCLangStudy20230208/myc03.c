//기본사칙연산과 나머지 연산
//연산의 기본적인 우선순위
#include<stdio.h>
int main() 
{
	printf("%d\n", 1 + 1);
	printf("%d\n", 2 - 1);
	printf("%d\n", 2 * 3); //shift + 8 혹은 텐키에 있음
	printf("%d %f\n", 7 / 3, 7 / 3);
	printf("%f\n",7.0 / 3);
	printf("%d\n", 7 % 3);

	printf("%d\n", 1 + 2 * 5);
	printf("%d\n", (1 + 2) * 5);

	int age = 35;
	int year = 1989;
	printf("%d\n", age + year - 1);//2023

	//%d : decimal, 10진수 = 정수
	//%f, %lf : 실수
	//%c : 문자
	//%s : 문자열(쌍따옴표 안에 들어가는 문장)


	return 0;
}