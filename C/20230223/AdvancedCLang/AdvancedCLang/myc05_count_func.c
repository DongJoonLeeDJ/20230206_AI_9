#include<stdio.h>
//#include<string.h> //strlen 쓸 때 필요하나 없어도 될 때가 있음
#include<mbstring.h> //_mbslen 쓰려면 반드시 필요
int main()
{
	char sentense[1024] = { 0 };
	printf("문장 입력하세요\n");
	gets(sentense);
	printf("%d %d\n", strlen(sentense), _mbslen(sentense));
	//strlen 바이트 수 출력
	//_mbslen : 글자수를 출력
}