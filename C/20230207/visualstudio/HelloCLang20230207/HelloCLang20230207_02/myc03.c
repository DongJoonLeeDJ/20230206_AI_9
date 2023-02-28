#include<stdio.h>
int main()
{
	printf("나이는?");
	int age;
	//&(shift+7) : 앤드(AND)라고 읽음
	scanf_s("%d", &age); //백준에선 _s 붙이면 안 됨
	printf("\n내 나이는 %d살입니다.\n", age);

	//1. 올해 연도도 입력받게 한다.
	//2. 올해 연도랑 내 나이를 이용해서 내가
	//언제 태어났는지 출력하게 한다.

	return 0;
}