#include<stdio.h>
int main()
{
	//반복문
	//3개
	//for
	//for(선언부;조건부;증감부)
	//for(;;) // <- 무한루프
	for (int i = 0; i < 10; i++)
	{
		printf("안녕하세요 %d번째 출력입니다.\n", i + 1);
	}
	//while
	int count = 0;
	while (count < 10)
	{
		printf("%d\n", count + 1);
		count++;
	}
	//do-while
	do
	{
		printf("count값이 10 이상이어도 한 번은 출력함 ㅇㅇ count=%d\n", count);
	} while (count<10);

	//while문 이용해서 구구단 하나 작성해보기
	int i = 2;
	int j = 1;
	while (i < 10)
	{
		while (j < 10)
		{
			printf("%d x %d = %d\n", i, j, i * j);
			j++;
		}
		j = 1;
		i++;
	}

	return 0;
}