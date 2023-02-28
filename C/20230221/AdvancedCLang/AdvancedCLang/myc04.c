//1. 이걸 그대로 출력한다.
//2.여기서 영어에 대해서는 대문자를 소문자로, 소문자를 대문자로 바꿔서 출력한다.
//문자열을 입력할 때 비밀번호를 입력한다고 생각하고 해보세요.
//1. 숫자만 입력받게 할 것.  ex) 123a 이렇게 입력받으면 오류를 출력, 1234 이렇게 입력시 통과
//2. 숫자와 영어가 조합되어야 하고 8글자 이상이어야지만 통과
//3. 숫자, 영어, 특수문자 조합이어야 하고 8글자 이상이어야지만 통과하며 특수문자는 !와 _만 허용
//4. 출력할 땐 글자수에 따라서 *로 바꿔서 출력 ex) 1234abcd! => *********
#include<stdio.h>
int main()
{
	char sentense[100];
	printf("문장 입력해주세요.\n");
	fgets(sentense, sizeof(sentense), stdin); //stdin 사용자 키보드 입력
	printf("%s\n", sentense);

	for (int i = 0; sentense[i] != NULL; i++)
	{
		char temp = sentense[i];
		if (sentense[i] >= 'A' && sentense[i] <= 'Z')
			printf("%c", temp + ('a' - 'A'));
		else if (sentense[i] >= 'a' && sentense[i] <= 'z')
			printf("%c", temp - ('a' - 'A'));
		else
			printf("%c", temp);
	}
	printf("\n");

	printf("문장 다시 입력해~\n");
	fgets(sentense, sizeof(sentense), stdin);
	printf("%s\n", sentense);
	for (int i = 0; sentense[i] != NULL; i++)
	{
		if ( (sentense[i] >= '0' && sentense[i] <= '9') || sentense[i] == '\n')
		{
		}
		else 
		{
			printf("숫자만 입력하라구!\n");
			break;
		}
	}
	/////////////// 배열 문법 말고 포인터 문법으로도 해볼 것 *(ptr+i) 이런거 쓰기
	

	return 0;
}