#include<stdio.h>
#define MAXSIZE 1024
int main()
{
	char input[MAXSIZE] = { NULL, }; //input에 전부 0을 집어넣음
	//이거 안 하면 쓰레기 값(=임의의 값)이 들어감
	printf("문장을 입력하세요.\n");
	gets(input);
	//a~z까지 26개이므로 26칸짜리 정수 배열을 활용할 것
	int checkAlphabet[26] = { 0 }; //이 배열에 전부 0이 들어감
	for (int i = 0; input[i] != NULL; i++)
	{
		if (input[i] >= 'A' && input[i] <='Z')
			input[i] += ('a' - 'A');
		if (input[i] < 'a' || input[i] > 'z')
			return 0; //프로그램 종료
		checkAlphabet[input[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (checkAlphabet[i] != 0)
			printf("%s에서 %c는 %d글자나옵니다.\n", input, 'a' + i, checkAlphabet[i]);
	}
	return 0;//프로그램 종료
}