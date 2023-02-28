/*
3. int a = 3; int b = 5일 때, 두 수의 값을 서로 바꿔주는 함수를 만드세요.
a와 b는 main에서 선언하며, 함수를 통해서 main의 a와 b가 바뀌어야 합니다.
*/
#include<stdio.h>
void swap(int* x, int* y)
{
	int temp = *x; //x가 가리키는 메모리의 값을 temp에 저장
	*x = *y; //x가 가리키는 메모리의 값을 y가 가리키는 메모리의 값으로 변경
	*y = temp; //y가 가리키는 메모리의 값을 temp에 저장된 값으로 변경
}
int main()
{
	int a = 3, b = 5;
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);//a=5, b=3으로 변경됨
	return 0;
}