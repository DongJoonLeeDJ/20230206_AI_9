#include<stdio.h>
int main()
{
	//while 괄호 안에 있는 조건이 맞아야지만 실행
	//do while 괄호 안에 있는 조건이 틀려도 무조건 한 번은 실행함

	int num = 0; //num이 0이지만 일단 한 번은 실행한다.
	do
	{
		printf("num값 입력해보세요.\n");
		scanf_s("%d", &num);
		printf("%d\n", num * num);
	} while (num>0); //이 조건에 맞지 않아도 무조건 한 번은 실행함!!!!


	//do while은 뭔가를 입력받아서 앞으로 계속할지 말지 결정할 때 쓰임
	//while 통신하면서 특정한 문자를 입력받을 때 까지 계속 동작할 때 쓰임
	//for는 반복 횟수가 정해진 경우에 보통 많이 쓴다.

	return 0;
}