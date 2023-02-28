#include<stdio.h>
void mytest1()
{
	int a = 10;
	a++;//함수가 종료되면 자동 소멸
	printf("a=%d\n", a);
}
void mytest2()
{
	//스태틱 변수 = 정적 변수
	static int a = 10;//static이 붙은 변수는 정적 변수
	a++;//별도의 메모리 영역에 저장이 된다. 그래서 프로그램이 종료될 때 소멸됨
	printf("static a=%d\n", a);
}
//int aa = 10; //글로벌에서 변수선언시 지역변수로 똑같은 이름 사용 가능
static int cx = 1000; //전역변수에도 static이 붙네!?
int main()
{
	//printf("%d\n", aa);
	//int aa = 100;
	//printf("%d\n", aa); //그러나 값이 가려진다(이런 걸 하이딩(Hiding)이라고 함)
	mytest1();//11
	mytest1();//11
	mytest2();//static a = 11
	mytest2();//static a = 12



	return 0;
}