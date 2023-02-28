//int a = 3; int b = 5일 때, 두 수의 값을 서로 바꿔주는 함수를 만드세요.
//a와 b는 main에서 선언하며, 함수를 통해서 main의 a와 b가 바뀌어야 합니다.

#include<stdio.h>
void myswap(int a, int b) //반환형 필요 없음.
{
	int temp = a;
	a = b;
	b = temp;
}
void swap(int* a, int* b) //변수 이름은 어차피 가독성 있게만 지으면 됨. main이랑 맞추지 않아도 됨
{
	int temp = *a; //*a란 a가 가리키는 곳의 값
	*a = *b;
	*b = temp;
}
int main()
{
	//함수 없이 두 변수의 값을 바꿔보자.
	int a = 3, b = 5;
	int temp = a;
	a = b;
	b = temp;
	printf("a=%d, b=%d\n", a, b);
	myswap(a, b); //값만 복사함. 원본에 영향을 주지 못 함.
	printf("a=%d, b=%d\n", a, b); //과연 다시 a는 3을 차지할 것인가?
	
	swap(&a, &b); //a와 b의 주소를 매개변수로 함
	printf("%d %d\n", a, b); //값이 3,5로 바뀌는 걸 볼 수 있다.

	//숙제 : 이걸 외워서 손으로 써서 a4용지에 옮겨 적고 사진 찍어서 step에 올린다.
	// 문제 총 3개니 모두 컴파일 되게끔 손으로 써서 사진찍어서 올린다.

	return 0;
}