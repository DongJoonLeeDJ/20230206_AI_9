#include<stdio.h>
#include<stdlib.h>

int main()
{
	//이게 안 되는 이유
	// 둘 다 stack 영역에 있다.
	// 같은 메모리 영역에 있으므로 우리 눈에는 size에 먼저 10이 들어가는 것처럼 보이지만
	// 메모리 처리를 할 때 mynums가 먼저 메모리에 올라갈 수도 있다.
	// 그럴 경우 size에 10이 있는 지 모르는 상태이므로 크기를 할당할 수 없다.
	//int size = 10;
	//int mynums[size];


	int n;
	printf("배열의 크기 입력 해\n");
	scanf_s("%d", &n);
	//배열의 크기를 원래는 매크로상수나 수로만 정의할 수 있으나
	//heap 영역을 이용하면 동적 할당이 가능
	
	//동적 할당 : 프로그램을 실행하는 도중에 메모리를 할당
	//dynamic allocate
	//정적 할당 : 우리가 여태 한 것처럼 변수 선언하는 거고, 메모리가 프로그램 시작 전에 미리 할당됨
	int* mynumbers = (int*)malloc(sizeof(int) * n);
	printf("숫자를 %d개 입력해\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &mynumbers[i]);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", mynumbers[i]);

	//단점
	//사용자가 인위적으로 할당했으므로 사용자가 직접 해제해야 한다.
	free(mynumbers);
	//해제하지 않고 이런 것들이 계속 쌓이면 메모리 누수문제(memory leak)가 일어난다.
	//메모리 샌다. 즉 메모리가 낭비된다. 
	return 0;
}