//재귀란? 자기 자신을 호출하는 함수
#include<stdio.h>
void test()
{
	//printf("안녕\n");
	//test(); //test가 test를 호출.
}

//재귀 함수를 이용하여 합 구하기
int sum(int s) //sum이 sum을 계속 호출한다.
{
	if (s <= 0) //그러나 s가 0이하가 되는 시점에선 함수 호출 안 함
		return 0;
	return s + sum(s - 1); //이걸 이용하여 값을 하나씩 감소시켜가며
}							//더하는 것
int main()
{
	//test();
	//main();
	printf("%d\n", sum(3));
	return 0;
}