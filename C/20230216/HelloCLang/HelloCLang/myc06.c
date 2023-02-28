#include<stdio.h>
int main()
{
	//피라미드
	//별의 개수가 1 3 5 7 9 이런 패턴
	int floor;
	printf("몇 층?\n");
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < floor - i - 1; j++) //띄어쓰기 수가 갈수록 줄어듦
			printf(" ");
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*");//2j+1 j는 0부터 시작하는 양의 정수
		printf("\n");
	}

	return 0;
}