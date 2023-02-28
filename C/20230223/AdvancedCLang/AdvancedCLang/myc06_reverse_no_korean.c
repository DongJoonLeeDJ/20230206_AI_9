#include<stdio.h>
int main()
{
	char sentense1[1024] = { NULL };
	char sentense2[1024] = { NULL };
	printf("입력하세요\n");
	gets(sentense1);
	int count = 0;
	for (count = 0; sentense1[count] != NULL; count++);//길이 구하기(strlen 대신임, byte값임)
	int i = 0; //sentense2의 인덱스
	int len = count; //원본(sentense1의 인덱스)
	for (i = 0; i <= count; i++, len--) //i는 증가, len은 감소해가며 값을 하나씩 추가
	{
		if (len == 0)
		{
			sentense2[i] = NULL; //맨 끝에 가선 끝부분에 NULL값 넣고 끝냄
			break;
		}
		sentense2[i] = sentense1[len - 1];
	}
	printf("%s %s\n", sentense1, sentense2);
	return 0;
}