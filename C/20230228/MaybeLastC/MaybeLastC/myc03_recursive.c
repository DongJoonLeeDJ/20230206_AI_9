#include<stdio.h>
//피보나치 수열
/*다음 규칙을 갖는 함수를 작성하시오.(재귀함수, 반복문)
	n == 0 = > 0
	n == 1 = > 1
	n > 1 = > f(n - 1) + f(n - 2)
	숫자 패턴
	1, 1, 2, 3, 5, 8, 13   21
	n = 1 n = 2  n = 3   n = 4  n = 5   n = 6   n = 7  n = 8
	*/
int f(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n > 1)
		return f(n - 1) + f(n - 2);
}

//피보나치 반복문 버전
//처음값과 두 번째 값을 준 다음에
//처음값과 두 번째 값에 해당하는 값을 바꾸고
//그 것의 합을 그 다음 값으로 지정하면 된다.
int f_for(int n)
{
	int f0 = 0;
	int f1 = 1;
	int f2;
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", f0); //중간 결과
		f2 = f0 + f1; //첫번째+두번째 = 세번째
		f0 = f1; //첫번째 -> 두번째
		f1 = f2; //두번째 -> 세번째
	}
	printf("\n");
	return f0; //f0에 n번째 수열값이 저장이 됨
}

int main()
{
	printf("%d\n", f(4));//3
	printf("%d\n", f(8));//21
	printf("%d\n", f_for(4));
	printf("%d\n", f_for(8));
	return 0;
}