#include<stdio.h>
int main()
{
	//논리 식이 쓰이는 곳
	//조건문
	int a = 5, b = 5;
	//두 개의 숫자를 비교했는 데, 값이 같은 경우
	//두 개의 숫자를 비교했는 데 값이 다른 경우
	//두 개의 숫자를 비교했는 데 첫 번째가 두번째보다 더 큰 경우
	//두 개의 숫자를 비교했는 데 첫 번째가 두번째보다 같거나 더 작은 경우
	printf("%d %d %d %d\n", a == b, a != b, a > b, a <= b); //1 0 0 1

	//삼항 연산자
	printf("숫자를 입력받는다. 나 보다 나이가 많은지 체크한다.\n");
	int age1, age2;
	printf("나와 상대의 나이를 출력한다.\n");
	scanf_s("%d %d", &age1, &age2);
	age1 >= age2 ? printf("내가 형일 수도 있나?") : printf("난 동생이야");

	char c = age1 >= age2 ? '+' : '-';
	printf("\nc=%c\n", c);

	//1. 나이를 입력한다. 짝수 나이일 경우에는 "짝짝꿍"출력. 그외엔 "..."출력
	printf("몇 살이세요????");
	int myage;
	scanf_s("%d", &myage);
	myage % 2 == 0 ? printf("\n짝짝꿍\n") : printf("\n...\n");
	
	//2. 1번 문제를 풀되, 0살 이하인 경우에 대해서 예외처리 한다.
	myage % 2 == 0 ? (myage <= 0 ? printf("\n예외\n") : printf("\n짝수\n")) 
		: printf("...");
	


	//if문
	if (myage % 2 == 0)
		printf("짝짝꿍");
	else
		printf("...");

	if (myage % 2 == 0)
	{
		if (myage <= 0)
			printf("예외");
		else
			printf("짝짝꿍");
	}
	else
	{
		printf("...");
	}

	//짝수이면서 양수인 경우
	//&&를 이용함!!!
	if (myage % 2 == 0 && myage > 0)
		printf("응애응애 짝짝꿍!");

	//내가 생후 몇개월인지 출력하게 해주세요.
	//예를 들자면 박준호 : 아마도 생후 약 300개월은 넘었을 것...
	//입력해야 할 값 = 4개
	//현재 연도, 내가 태어난 연도, 현재 월, 내가 태어난 월

	//다 하셨다면 예외처리도 같이 해보세요.(음수나 0에 대한 예외처리 등등)



	return 0;
}