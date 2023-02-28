#include<stdio.h>
extern mya;//test_static.c에 있는 그 변수를 읽어옴
//static 키워드 없는 전역변수는 외부에서 읽어올 수 있다.
extern myb;//일단 선언까진 됨
int main()
{
	printf("%d\n", mya); //mya에 원래 10있었음
	mya = 0;//extern 통해서 test_static의 mya에 접근해서 값 바꿈
	printf("%d\n", mya); //다시 출력해 봄
	increase(); //mya는 하나 증가하고 myb도 증가함
	
	//그러면 여기서 myb는 접근이 될까?
	myb++; //정답 : 안 됨, 이유 : static(정적)변수라서 외부에서 못 씀

	//static변수(정적 변수)의 특징
	//1. 데이터 영역에 저장되며 프로그램 시작시 미리 메모리에 올라가 있음
	//메모리에 올라가 있는 시점이 스택, 힙보다 빠르다.
	//2. 다른 c 파일에서 해당 키워드 붙은 변수 쓸 수 없음(ex. myb)

	return 0;
}