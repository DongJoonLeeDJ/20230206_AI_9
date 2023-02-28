//피보나치 수열
/*다음 규칙을 갖는 함수를 작성하시오.(재귀함수, 반복문)
	n == 0 = > 0
	n == 1 = > 1
	n > 1 = > f(n - 1) + f(n - 2)
	숫자 패턴
	1, 1, 2, 3, 5, 8, 13   21
	n = 1 n = 2  n = 3   n = 4  n = 5   n = 6   n = 7  n = 8
	*/
#include<stdio.h>
int f(int n)//자기 자신을 호출하되 종료조건이 있는 것
{
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return f(n - 1) + f(n - 2);
}
int main()
{
	
	//1 1 2 3 5 8 13 21
	printf("피보나치 수열 8번째 : %d\n", f(8));
	return 0;
}