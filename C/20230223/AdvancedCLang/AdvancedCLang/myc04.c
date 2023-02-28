//문자열을 입력할 때 비밀번호를 입력한다고 생각하고 해보세요.
//- 숫자와 영어가 조합되어야 하고 8글자 이상이어야지만 통과
//- 숫자, 영어, 특수문자 조합이어야 하고 8글자 이상이어야지만 통과하며 특수문자는 !와 _만 허용
//- 출력할 땐 글자수에 따라서 *로 바꿔서 출력 ex) 1234abcd! => *********
#include<stdio.h>
int main()
{
	char password[1024];
	printf("입력하기\n");
	gets(password); //비밀번호 입력하기
	int isalpha = -1; //알파벳 존재 여부 체크
	int isnum = -1; //숫자 존재 여부 체크
	int isgood = -1; //특수문자존재 여부 체크(허용하는 것은 !랑 @)
	int i = 0; //길이
	while (1)
	{
		for (i = 0; password[i] != NULL; i++)
		{
			if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z'))
				isalpha = i;
			if (password[i] >= '0' && password[i] <= '9')
				isnum = i;
			if (password[i] == '!' || password[i] == '_')
				isgood = i;
		}
		if (i >= 8 && isalpha != -1 && isnum != -1 && isgood != -1)
			break;
		else
		{
			isalpha = -1;
			isnum = -1;
			isgood = -1;
			printf("다시 입력\n");
		}
		gets(password);
	}
	printf("%s\n", password);
	for (i = 0; password[i] != NULL; i++)
		printf("*");
	printf("\n");
	

	return 0;
}