#include<stdio.h>
//전역변수(글로벌 변수)는 main이랑 다른 함수에서 공통적으로 읽고 쓸 수 있다.
int a = 3, b = 5; 
void swap()
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	//int a = 1000; //글로벌 변수의 주의점, 하이딩, a=1000이 출력되버림
	printf("a=%d, b=%d\n", a, b);
	swap();
	printf("a=%d, b=%d\n", a, b);
	return 0;
}