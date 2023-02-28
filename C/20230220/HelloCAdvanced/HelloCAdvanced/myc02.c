#include<stdio.h>
int main()
{
	////배열 = 포인터

	////배열 : 하나의 변수를 통해서 여러 개의 숫자를 관리함
	////메모리 상에서 연속된(=붙어있는) 위치에 있는 공간들을 관리

	//int n[5];
	//printf("%d\n", sizeof(n)); //https://m.blog.naver.com/123gtf/220905979083 // 8
	///*
	//컴파일 설정이 64bit인 경우엔 포인터변수들의 크기는 4바이트가 아니다.
	//(64bit의 컴파일러에서 포인터 변수의 크기가 8바이트이며 , 16bit의 컴파일러에서는 2바이트이다.)
	//C언어의 컴파일 시, 운영체제의 bit가 아닌 컴파일러의 bit에 따라서 포인터 변수의 크기가 달라짐 참조 링크 :
	//http://stackoverflow.com/questions/16823752/why-size-of-void-pointer-is-4-on-windows-64-bit-platform
	//*/
	//int* p = n;
	//printf("%d\n", sizeof(p));

	//값을 집어넣는 방법
	//1. 선언할 때 대입
	int n2[3] = { 10,1,-1 };
	//2. 인덱스에 직접 대입
	n2[2] = 100;
	//3. scanf로 입력
	//scanf_s("%d", &n2[0]);

	//출력
	//sizeof(n2) / sizeof(int) 배열의 크기이며
	//sizeof(n2) / sizeof(n2[0])이라고 해도 똑같음
	for (int i = 0; i < sizeof(n2) / sizeof(int); i++)
	{
		printf("%d\n", n2[i]);
	}
	printf("%d", sizeof(n2));







	return 0;
}