#include<stdio.h>
int main()
{
	//주석 단축키 ctrl 누르고 k 누른 다음 바로 c 누르면 됨
	//주석 해제 ctrl 누르고 k 누른 다음 바로 u 누르면 됨
	/*
		1. 원의 반지름 r 값을 입력받고, 원의 넓이와 원의 둘레값 출력하기
		원의 넓이 : r * r * 3.14
		원의 둘레 : 2 * r * 3.14
	*/
	//상수
	//const 키워드가 앞에 붙으면 '상수'임을 의미함
	//이름은 있으나 값 변경은 불가능하다.
	//통상적으로 대문자를 씁니다.
	const double PI = 3.14;
	int r;
	printf("원의 반지름을 입력하세요.\n");
	scanf_s("%d", &r);
	printf("원의 넓이 : %f\n", r * r * PI);
	printf("원의 둘레 : %f\n", r * 2 * PI);

	/*2.byte를 입력받고 그에 해당하는 bit값 출력하기
		입력 : 1  입력 : 5
		출력 : 8  출력 : 40
		*/
	int mybyte; 
	//키워드 : int, double과 같이 언어에서 이미 쓰고 있는 단어
	printf("바이트값 입력하세요.\n");
	scanf_s("%d", &mybyte);
	printf("%dbyte = %dbit\n", mybyte, mybyte * 8);

	/*
		3.bit값을 입력받고 그에 해당하는 byte값 출력하기
		단, 소수점은 모두 버릴 것
		입력 : 8  출력 : 1
		입력 : 40 출력 : 5
		*/
	int mybit;
	printf("bit값 입력하세요.\n");
	scanf_s("%d", &mybit);
	printf("%d\n", (mybit / 8) );
	
}