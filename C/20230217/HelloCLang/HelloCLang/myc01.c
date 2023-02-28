#include<stdio.h>
int main()
{
	int floor;
	printf("몇층?\n");
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < floor - i - 1; j++)
			printf(" "); //띄어쓰기 감소
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*"); //별이 증가 2j+1 (n은 0부터 시작)
		printf("\n");
	}
	for (int i = 0; i < floor - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
			printf(" ");//띄어쓰기 갈수록 증가
		for (int j = 0; j < (2 * (floor - i - 1)) - 1; j++)
			printf("*"); //별이 감소 2j-1패턴으로 감소
		printf("\n");
	}
	return 0;
}