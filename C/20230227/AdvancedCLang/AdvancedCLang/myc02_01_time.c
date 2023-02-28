#include<stdio.h>
//1. 반환값 없고 매개변수는 s 하나인 함수를 작성 후 main에서 호출
//내용 : s = 123 = > 2분 3초라는 메시지를 프린트함
void mytime(int s)
{
	if (s <= 0)
	{
		printf("%d는 잘못된 값입니다.\n", s);
		return; //즉시 함수 종료됨. 밑에 코드 실행 안 함.
	}
	if (s % 60 == 0)
	{
		printf("%d분\n", s / 60);
		return;
	}
	printf("%d분 %d초\n", s / 60, s % 60);
}
int main()
{
	int s = 123;
	mytime(s);
	return 0;
}