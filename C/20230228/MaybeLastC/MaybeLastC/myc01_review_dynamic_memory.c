#include<stdio.h>
#include<stdlib.h> //동적 메모리 할당시(malloc, calloc 등)
int main()
{
	//이 코드가 안 되는 이유
	//둘 다 같은 영역(stack, 스택)에 있기 때문
	//size값이 언제 바뀔지 알 수 없고, 둘이 동시에 메모리에 올라가기 때문
	int size = 10;
	int nums[size];//식에 상수값이 있어야 합니다.
	return 0;
}