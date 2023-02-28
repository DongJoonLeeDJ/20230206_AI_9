/*
2. 반환값만 있고 매개변수는 없는 함수를 작성 후 main에서 호출
내용 : 1부터 100까지의 합을 구하되 3의 배수만 포함한 값을 반환하는 함수를 만들고
이를 메인에서 호출하여 값 확인
*/
#include<stdio.h>
int sum_3baesu()
{
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			sum += i;
	}
	return sum;
}
int main()
{
	printf("%d\n", sum_3baesu());
	int a = sum_3baesu();
	printf("%d\n", a);
	return 0;
}