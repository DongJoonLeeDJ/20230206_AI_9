#include<stdio.h>
int main()
{
	//현재 연도, 내가 태어난 연도, 현재 달, 내가 태어난 달
	int thisYear, birthYear, thisMonth, birthMonth;
	printf("현재연도, 내가 태어난 연도, 현재 달, 내가 태어난 달 입력\n");
	scanf_s("%d %d %d %d", &thisYear, &birthYear, &thisMonth, &birthMonth);
	int gapYear = thisYear - birthYear; //2023-1989 = 34
	
	//코드 표기법
	//1. 스네이크 표기법 : 단어와 단어 사이에 밑줄(underbar, _)를 쓴다.
	//ex) int this_year
	//2. 카멜 표기법 : camel(낙타) 등같은 표기법
	//ex) int thisYear 이렇게 쓴다. thisyear 이렇게 쓰면 가독성이 떨어진다.

	//변수 표기의 중요한 원칙
	//숫자를 가장 첫번째로 쓸 수 없다. ex) int 1, int 1Year; 이렇게 쓸 수 없음
	// 단, 뒤에 쓰는 건 얼마든지 가능 ex) int Year1, Year2;
	//공백도 불가능하며 허용되는 특수문자는 _(밑줄)이다. 
	//되도록이면 변수명은 영어로 지어라. 한글이나 다른 언어도 되긴 
	//하지만 그래도 영어가 가장 일반적

	if (gapYear < 0)
	{
		printf("이 값은 잘못됐습니다\n");
	}
	else
	{
		int month = gapYear * 12; //34가 나왔다면 34*12 = 408
		int myMonth = month + thisMonth - birthMonth;
		printf("당신은 생후 %d개월입니다.\n", myMonth);
	}


	return 0;
}