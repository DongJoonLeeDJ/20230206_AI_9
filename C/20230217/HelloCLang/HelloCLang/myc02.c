#include<stdio.h>
int main()
{
	//4. 알파벳 A부터 Z까지 순차로 출력하게 하시오.(대문자)
	//hint) ascii이용, char는 숫자로 바로 대응이 된다
	for (char c = 'A'; c <= 'Z'; c++)
		printf("%c", c);
	printf("\n");
	//5. 알파벳 a부터 a까지 순차로 출력하게 하시오.(소문자)
	for (char c = 'a'; c <= 'z'; c++)
		printf("%c", c);
	printf("\n");
	//6. 알파벳 A부터 z까지 순차로 출력하게 하시오.(대소문자 모두)
	for (char c = 'A'; c <= 'z'; c++)
	{
		if(c<='Z' || c>='a')
			printf("%c", c);
	}
	//7. 다음 입력에 따른 출력을 해보세요.
	printf("\n층 수를 입력하세요\n");
	int floor;
	scanf_s("%d", &floor);

	//2입력시 4층, 3입력시 6층, 4입력시 8층
	for (int i = 0; i < 2 * floor; i++)
	{
		int onOffSwitch = i;
		for (int j = 0; j < floor; j++)
		{
			if (onOffSwitch % 2 == 0)
				printf("*");
			else
				printf(" ");
			onOffSwitch++;
		}
		printf("\n");
	}

	return 0;
}