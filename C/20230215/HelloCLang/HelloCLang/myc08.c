#include<stdio.h>
int main()
{
	//1부터 100까지 더하되 3의 배수만 더해서 출력할 것
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0) //3의 배수
			sum += i; //sum = sum + i;
	}
	printf("3의 배수만 더한 것(1~100) : %d\n", sum);

	 
 
	//1부터 n까지 더하되 m의 배수를 제외하고 더해서 출력하는 것
	printf("n,m 입력하세요.\n");
	int n, m;
	scanf_s("%d %d", &n, &m);
	if (n >= 1 && m >= 1) //n이나 m은 둘 다 1 이상일 수 밖에 없다.
	{
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i % m != 0)
				sum += i;
		}
		printf("결과 : %d\n", sum);
	}

	 
	//문제 3. 숫자를 입력받고 해당 숫자에 따라서 다음과 같은 출력을 
	//하는 프로그램을 작성해보세요.
	//ex) 3 입력시
	//*
	//**
	//***
	//5를 입력
	//*
	//**
	//***
	//****
	//*****

	printf("몇 층을 쌓겠느냐?\n");
	int floor;
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");

		printf("\n");
	}
	//3번 문제랑 반대로 출력되게 해보세요.
	//ex) 3 입력시
	//  *
	// **
	//***

	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < floor - i - 1; j++)
			printf(" ");
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}