#include<stdio.h>
int main()
{
	//1부터 100까지 더하는 코드를 작성
	//1. for문은 100번 돈다는 것
	//2. 100번 돌 동안 i 값을 어딘가에 누적을 시켜놔야 한다.
	int sum = 0;
	for (int i = 1; i <= 100; i++)
		sum += i;
	printf("sum=%d\n", sum);

	//1부터 10까지 곱하는 코드를 작성
	//출력1) 1부터 10까지 곱은 3628800 다.
	//출력2) 10! = 1x2x3x4x5x6x7x8x9x10 = 3628800
	sum = 1; //sum을 0으로 초기화하면 곱의 의미가 없다.

	for (int i = 1; i <= 10; i++)
		sum *= i;
	printf("1부터 10까지 곱은 %d이다.\n", sum);

	printf("10!=1"); //10!=1
	for (int i = 2; i <= 10; i++)
		printf("x%d", i); //x2x3x4x5x6x7x8x9x10
	printf("=%d\n", sum);//=3628800
	return 0;
}