#include<stdio.h> //Legacy of the void = 공허의 유산
//void : 공허, 아무 것도 없는 = 반환형이 없다. 아무 것도 없다.
void Introduce() //매개변수와 반환형이 없는 형태
{
	char name[100];
	printf("이름은?\n");
	gets(name);
	printf("안녕하세요\n");
	printf("내 이름은 %s입니다.\n", name);
}
//반환형만 없는 스타일
void printPower(int num)
{
	printf("%d의 제곱 : %d\n", num, num * num);
}
//반환형만 있는 스타일(=매개변수가 없는 스타일)
int isPlus() //매개변수가 없으므로 int isPlus(void)라고 적어도 됨
{
	printf("숫자 2개 입력\n");
	int a, b;
	scanf_s("%d %d", &a, &b);
	if (a > b)
		return 1; //a-b할 때 양수
	else if (a < b)
		return -1; //a-b할 때 음수
	else
		return 0;//a-b할 때 0
}
int main()
{
	Introduce();
	printPower(10);
	//1. 함수 만들기 -> 반환형만 있는 함수를 만들어보세요.(매개변수없음)
	//함수 안에서 수 2개를 입력받고 두 수를 서로 뺍니다.
	//그 때 값이 양수면 1, 0이면 0, 음수면 -1을 반환합니다.
	int result = isPlus();
	printf("결과 : %d\n", result);
	printf("결과 : %d\n", isPlus());
	if (result == 1)
		printf("양수\n");
	else if (result == -1)
		printf("음수\n");
	else
		printf("zero\n");


	//2. printPower에 들어갈 값을 아무거나 집어넣어서 결과 확인해보세요.
	//대신에 main에 변수 선언하고, scanf로 값 입력받고 그 변수를 함수의 매개변수로 쓰세요.
	printPower(3);
	int num;
	printf("제곱할 수 입력\n");
	scanf_s("%d", &num);
	printPower(num);

	//int a = 3; int b = 5일 때, 두 수의 값을 서로 바꿔주는 함수를 만드세요.
	//a와 b는 main에서 선언하며, 함수를 통해서 main의 a와 b가 바뀌어야 합니다.

	return 0;
}