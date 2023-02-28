#include<stdio.h>
int main()
{
	//while : ~ 하는 동안에
	//for문은 보통 반복 횟수가 정해져 있을 때 많이 쓰임
	//while문은 반복 횟수가 정해져 있지 않을 때 많이 쓰임
	while (1) //괄호 안에 있는 값이 참이면 계속 수행한다.
	{
		int num;
		printf("숫자를 입력하세요.\n");
		scanf_s("%d", &num);
		if (num < 0) //음수 입력하면 반복문을 종료하고, 그게 아니면 반복문 계속 수행
			break;
		printf("%d\n", num * num);

	}
	//printf("num=%d\n", num); //while문 밖에선 num을 못 씀. num은 while문 안에서 선언해서 그렇다.
	// 이 특징은 for, if와 동일하다.
	
	//1부터 100까지의 합 구하기
	int sum = 0;
	int i = 0;
	while (i <= 100)
	{
		sum += i;
		i++;
	}
	printf("sum=%d\n", sum);
	return 0;
}