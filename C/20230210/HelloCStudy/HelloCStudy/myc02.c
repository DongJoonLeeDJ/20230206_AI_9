#include<stdio.h>
int main()
{
	//실수를 입력받는 방법
	printf("나의 몸무게는?\n");
	double kg;
	scanf_s("%lf", &kg);//double = long float
	//& 의 의미 : 주소
	//컴퓨터 메모리 상에서 해당 변수의 위치
	//scanf_s = 메모리 상에서 해당 변수의 위치에 가서
	//값을 집어넣어 주는 것

	printf("내 몸무게는 %fkg입니다.\n", kg);

	//문자를 입력받는 방법과 그 주의 사항
	//rewind(stdin); //버퍼라는 공간을 청소해주는 것
	printf("외향적이면 E 입력, 내향이면 I 입력하기\n");
	char mytype;
	//문자를 입력할 땐 바이트 값을 명시해줘야 함
	scanf_s("%c", &mytype, sizeof(char));
	printf("나는 %c형 인간입니다.\n",mytype);


	//문자를 입력받는 방법은 2개가 있다.
	//1. scanf
	//2. getchar라는 함수
	//rewind(stdin);
	char c2 = getchar();


	//값을 여러 개 입력하는 방법
	
	//실수나 정수만 입력하는 경우
	printf("숫자 3개 입력해보세요.\n");
	int a, b; //변수 여러 개 한 번에 선언 가능
	double d;
	scanf_s("%d %d %lf", &a, &b, &d);
	printf("a=%d, b=%d d=%f\n", a, b, d);

	//숫자나 문자 섞어서 입력해보기
	//권장하진 않는다... 
	//차라리 문자랑 숫자는 따로 적는 게 좋습니다.
	//문자 여러 개인 경우에도 따로 적는 게 좋습니다.
	rewind(stdin); //앞에서 숫자를 입력했기 때문
	printf("혈액형 RH +인지 -인지 적고 나이도 적기");
	char rh;
	int age;
	scanf_s("%c %d", &rh, 1, &age);
	printf("혈액형 rh + - 여부 : %c, 나이 : %d\n", rh, age);



	return 0;
}