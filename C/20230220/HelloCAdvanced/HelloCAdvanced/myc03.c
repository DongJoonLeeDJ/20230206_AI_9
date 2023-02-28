//1. 사람 5명의 나이를 입력하세요.
//2. 5명의 나이를 출력하세요.
//3. 5개의 나이 중 가장 큰 값을 찾아서 출력하세요.
#include<stdio.h>
#define MAXSIZE 5
int main()
{
	//1. 사람 5명의 나이를 입력하세요.
	//변수 5개를 쓸 수도 있지만, 하나의 변수로 5개의 값을 관리할 수 있다.
	int ages[5]; //크기를 수로 정해야 함 //혹은 #define(매크로상수)를 써야 한다.
	int a[MAXSIZE]; //이건 된다.
	

	//int size=5;
	//int ages[size];
	//이렇게는 안 된다. 변수를 이용해서 크기 할당하려면
	//동적할당해야 함
	//malloc 이라는 문법 검색하거나 chat gpt한테 물어보세요.

	//for (int i = 0; i < 5; i++)
	for (int i = 0; i < sizeof(ages) / sizeof(ages[0]); i++)
	{
		printf("숫자를 입력하세요\n");
		scanf_s("%d", &ages[i]);
	}
	//2. 5명의 나이를 출력하세요.
	for (int i = 0; i < 5; i++)
		printf("%d\n", ages[i]);


	//한 번에 입력하기
	printf("숫자를 입력하세요 ex) 10 20 30 40 50 이렇게 입력\n");
	for (int i = 0; i < sizeof(ages) / sizeof(ages[0]); i++)
	{
	scanf_s("%d", &ages[i]);
	}

	for (int i = 0; i < 5; i++)
		printf("%d\n", ages[i]);


	//3. 5개의 나이 중 가장 큰 값을 찾아서 출력하세요.
	int max = ages[0];
	for (int i = 1; i < 5; i++)
	{
		if (max < ages[i])
			max = ages[i];
	}
	printf("가장 고령은 %d살입니다.\n", max);


	return 0;
}