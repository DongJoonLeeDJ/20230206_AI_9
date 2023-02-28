#include<stdio.h>
int main()
{
	//조건문
	//변수의 값에 따라서 동작이 달라지는 것

	//삼항 연산자
	//항 : 코드
	//숫자를 입력하고, 그 숫자가 양수이거나
	//아닌 경우에 따라서 다른 출력을 할게요.

	int num;
	printf("숫자 입력");
	scanf_s("%d", &num);
	num > 0 ? printf("양수\n") : printf("양수아님\n");
	//(코드) ? (코드가 참) : (코드가 거짓);
	printf("%d\n", num > 0);
	printf("%d\n", num < 0);
	printf("%d\n", num == 0);
	printf("%d\n", num = 0);
	printf("%d\n", num == 0);
	printf("%d\n", num != 0); //다르다
	num = 2002;
	num != 2002 ? printf("월드컵모르네") : printf("4강신화");
	num = 10;
	char c = num == 0 ? '0' : '!'; //c에 값을 대입하는 데,
									//num에 따라서 다르다.
	printf("\n%c\n", c);
	return 0;
}