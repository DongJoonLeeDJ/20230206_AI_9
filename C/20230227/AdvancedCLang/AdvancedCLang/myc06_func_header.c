#include<stdio.h>
void printMyName(char* name); //함수의 원형 혹은 함수의 헤더라고 표현
int sum(int, int, int); //매개변수의 이름을 붙이지 않고 형태만 정의해도 됨.
int main()
{
	printMyName("이동준");
	int mysum = sum(0, 100, 3);
	printf("%d\n", mysum);
	return 0;
}
//이렇게 쓰는 이유는 함수의 정의가 너무 길거나 많을 때
//간결하게 하려고 그렇다. 위엔 원형들만 늘어놓고 아래에 정의를 해놓는다.
void printMyName(char* name) //함수 정의
{
	printf("내 이름은 %s 입니다.\n", name);
}
int sum(int a, int b, int c)
{
	int sum = 0;
	for (int i = a; i <= b; i += c)
		sum += i;
	return sum;
}