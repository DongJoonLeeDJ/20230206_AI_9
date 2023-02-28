#include<stdio.h>
int main()
{
	//자료형, 변수, 입출력, 조건문, 반복문

	//자료형 : 정수, 실수, 문자
	// 문자 : 따옴표로 감싸짐
	// 문자열 : 1글자 이상의 글자이고 큰따옴표로 감싸짐
	//변수
	int a = 10;
	double b = 3.14;
	char c = 'A'; // char는 1byte만 저장하므로, 변수 하나에
	//숫자, 특수문자, 영어는 되지만 한글은 안 된다.
	//한글은 C 언어 입장에선 "문자열"이다.

	//출력, 입력
	printf("%d %f %c\n", a, b, c);

	//입력
	printf("a값 입력해\n");
	scanf_s("%d", &a);
	printf("a=%d\n", a);
	printf("b값 입력해\n");
	scanf_s("%lf", &b);
	printf("b=%f\n", b);
	//문자를 입력하는 방법은 scanf랑 getchar()라 있다.
	//그 전에 또 다른 문자나 숫자를 입력받았다면 그 전엔 rewind를 해줘야 한다.
	rewind(stdin);
	printf("c 값 입력해(scanf)");
	scanf_s("%c", &c, 1);
	printf("c=%c\n", c);
	rewind(stdin);
	printf("c 값을 다시 입력해\n");
	c = getchar();
	printf("c=%c %d\n", c, c);

	//조건문
	//3개
	//1. 삼항연산자
	//2. if문 
	//3. switch문

	//삼항 연산자
	a > 0 ? printf("a는 양의 정수!\n") : printf("a는 양의 정수가 아니다.\n");
	c = a >= 0 ? '+' : '-'; //c에 대입되는 값을 다르게 한다.
	printf("c=%c(삼항연산자 이후)\n", c);

	//if문
	if (c == '+') //<--- 이 부분에는 세미콜론 쓰면 안 된다.(반복문에서도 마찬가지다)
		printf("C는 플러스입니다\n");

	if (b >= 3.14) //코드가 2줄 이상 길어지면 중괄호를 반드시 써야 한다.
	{
		printf("b는 3.14보다 크거나 같습니다.\n");
		printf("아마도 원주율을 나타내는 것 같습니다.\n");
	}

	a = -1;
	if (a > 0) printf("a는 양수입니다.\n");
	printf("a는 0보다 커요\n"); //이런 경우엔 중괄호로 묶어야 한다.

	if (a < 0)
	{
		printf("a는 음수\n");
	}
	else if (a == 0)
	{
		printf("a는 0!\n");
	}
	else
	{
		printf("a는 양수!\n");
	}


	//if-else if - else if - else if - else랑
	//if-if-if-else랑은 전혀 다른 코드
	if (a < 0)
	{
		printf("a는 음수\n");
	}
	if (a == 0)
	{
		printf("a는 0!\n");
	}
	else
	{
		printf("a는 양수!\n");
	}

	//else if로 끝내도 됨
	if (a == 0)
	{
		printf("a는 0!!!\n");
	}
	else if (a > 0)
	{
		printf("a>0!!\n");
	}
	//else 상황이 떠오르지 않으면 저렇게 마무리지어도 됨

	a = 10;
	switch (a)
	{
	case 1:
		printf("a는 1입니다.\n");
		break;
	case 2:
	case 3:
	case 10:
		printf("a는 2이거나 3이거나 10입니다.\n");
	default:
		printf("a는 이도저도 아닙니다.\n");
		break;
	}





	//앞으로 배울 것
	//포인터, 배열, 문자열, 함수, 구조체


	return 0;
}