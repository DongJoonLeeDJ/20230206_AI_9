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
	int i = 0;
	//한글을 만나면 2칸을 건너뛰기 위해 i를 사용
	//count는 글자세기용
	for (i = 0; sentense[i] != NULL; i++,count++) 
	{
		if (sentense[i] < 0) //아스키가 아닌 경우
		{
			i++;
			continue;
		}
	}
	printf("%d\n", count);

	return 0;
}
