#include<stdio.h>
#include<stdlib.h> //동적 메모리 할당시(malloc, calloc 등)
int main()
{
	//이 코드가 안 되는 이유
	//둘 다 같은 영역(stack, 스택)에 있기 때문
	//size값이 언제 바뀔지 알 수 없고, 둘이 동시에 메모리에 올라가기 때문
	//int size = 10;
	//int nums[size];//식에 상수값이 있어야 합니다.

	//heap 메모리 영역을 활용해야 함
	//heap영역은 프로그램 구동중에 할당되는 메모리 영역
	int size;
	printf("배열 길이?\n");
	scanf_s("%d", &size);
	int* numbers = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		numbers[i] = i + 10;
	for (int i = 0; i < size; i++)
		printf("%d\n", numbers[i]);


	//malloc과 마찬가지로 heap영역에 동적으로 메모리를 할당
	//차이점1. 문법이 다르다.
	int* mynumbers = (int*)calloc(size, sizeof(int)); 
	int* mynumbers2 = (int*)malloc(size* sizeof(int)); 
	//차이점2. 기본으로 들어가 있는 값이 다릅니다.
	for (int i = 0; i < size; i++)
	{
		printf("calloc[%d] = %d\n", i, mynumbers[i]);
		printf("malloc[%d] = %d\n", i, mynumbers2[i]);
	}


	free(numbers); //사용자가 임의로 할당한 메모리이므로 다 쓴 후에는 반드시 해제
	//java, c#에선 GC(Garbage Collector)라는 것이 자동으로 메모리 해제함

	return 0;
}