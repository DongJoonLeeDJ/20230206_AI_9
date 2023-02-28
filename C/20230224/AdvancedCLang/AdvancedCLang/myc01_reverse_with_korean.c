#include<stdio.h>
int main()
{
	//char a[1024] = "이진곤";
	//char b[1024] = { NULL };
	//b[5] = a[0];
	//b[4] = a[1];
	//b[3] = a[2];
	//b[2] = a[3];
	//b[1] = a[4];
	//b[0] = a[5];
	/*
		ァケずつ하핳ㅋ안녕Hello
		ァケずつ하핳ㅋ안녕Helloo
		ァケずつ하핳ㅋ안녕Hello핰
		ァケずつ하핳ㅋ안녕Hello핰o
		sentense1 = "あいうエオ"
		sentense1 = "ァケずつ하핳ㅋ안녕Hello핰o" (혹은 더 긴 문자열)
		"안녕하세요? Hello World! 이것은 테스트입니다."
	*/
	
	char sentense1[1024] = { NULL }; //1024칸 배열에 0을 다 넣은 것
	char sentense2[1024] = { NULL };
	printf("문자열1 입력하세요.\n");
	gets(sentense1);
	int count = 0;
	for (count = 0; sentense1[count] != NULL; count++);//글자수 세기
	int i = 0; //앞쪽부터 읽을 변수
	int len = count - 1; //뒤쪽부터 쓸 변수
	for (i = 0; sentense1[i] != NULL; i++, len--)//i는 증가 len은 감소
	{
		if (sentense1[i] >= 0 && sentense1[i] <= 127) //아스키코드에 포함된 경우
			sentense2[len] = sentense1[i];
		else //아스키코드에 해당되지 않는 경우, 즉 2byte 일수도 있는 경우
		{
			if (len <= 0) //이런 경우 발생하기 전에 반복문이 종료되긴하나 혹시나싶어 예외처리함
				break;
			sentense2[len - 1] = sentense1[i];
			sentense2[len] = sentense1[i+1];
			i++;
			len--;
		}
	}
	printf("\n%s %s\n", sentense1, sentense2);

	return 0;
}