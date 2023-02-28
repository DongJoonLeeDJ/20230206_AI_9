//1. 문자열의 개수를 세보세요
//2. 문자열의 개수를 세보세요(한글도 같이 샐 것)
#include<stdio.h>
int main()
{
	//영어버전
	//그냥 바이트수를 그대로 세면 된다.
	char sentense[1024];
	printf("문장을 입력하세요. 일단 영어만 합시다.\n");
	gets(sentense);
	int count = 0;
	//두 개의 for문이 서로 똑같은 거임...
	//for (count = 0; sentense[count] != NULL; count++);
	for (count = 0; sentense[count] != NULL;  count++)
	{
	}
	printf("%d\n", count);

	return 0;
}
