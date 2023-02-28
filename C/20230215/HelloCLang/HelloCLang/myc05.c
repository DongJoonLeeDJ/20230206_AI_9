#include<stdio.h>
int main()
{
	//1부터 100까지 더하는 데, 짝수만 더해서 출력을 한다.
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0) //짝수
			sum += i; //이 때만 값을 누적
	}
	printf("1부터 100까지의 짝수 합은 %d입니다.\n", sum);

	sum = 0;
	//값을 2씩 증가시키는 방법
	for (int i = 2; i <= 100; i += 2)
		sum += i;
	printf("sum=%d\n", sum);

	//continue 문법, break랑 많이 헷갈려 함
	//continue는 반복문 종료가 아니고 현재 단계 생략 후 다음 단계로 넘어가는 것
	sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 != 0)//짝수가 아니라면
			continue; //밑에 코드 생략하고 i++로 바로 건너 뜀
		sum += i; //짝수라면 i를 누적
	}
	printf("sum=%d\n", sum);


	return 0;
}