#include<stdio.h>
int main()
{
	system("color ac"); //녹색 배경에 빨간 글자
	printf("Hello World\n");

	//문자열을 입력을 받아서 그에 맞게 색깔 바뀌게 해보세요.
	//단 뒤에 두 글자만 입력하면 됨
	//ex ) ac 입력하면 녹색 배경에 빨간 글자 나오게 하기
	char color[1024] = "color";
	//color 뒤에 들어갈 글자를 gets로 입력받고
	//system(color);이렇게 하라는 것
	//예외처리도 해볼 것

	char input[3];
	//2글자를 입력받고 그걸 color 뒤에 더할 것
	while (1)
	{
		printf("색깔 입력해\n");
		gets(input);
		int count = 0;
		for (count = 0; input[count] != NULL; count++); //글자수 세기
		if (count != 2) //색상은 2글자로 표현된다.
		{
			printf("글자수가 부적합해요.");
			continue;
		}
		//1. 임의의 배열을 만든 다음에 거기에 포함된 문자인 경우 통과
		//배열에는 0123456789ABCDEF 이렇게 넣는다.
		//2. 범위를 지정하는 방법이 있다. => 이걸로 해보겠습니다.
		if ((input[0] >= '0' && input[0] <= '9') || (input[0] >= 'A' && input[0] <= 'F')
			|| (input[0] >= 'a' && input[0] <= 'f'))
		{

			if ((input[1] >= '0' && input[1] <= '9') || (input[1] >= 'A' && input[1] <= 'F')
				|| (input[1] >= 'a' && input[1] <= 'f'))
			{
				break;
			}

		}
	}



	color[5] = ' ';
	color[6] = input[0];
	color[7] = input[1];
	color[8] = NULL;
	system(color);


	return 0;
}