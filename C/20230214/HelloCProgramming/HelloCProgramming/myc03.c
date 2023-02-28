#include<stdio.h>
int main()
{
	int N, X, Y;
	FIRST:
	printf("N 입력\n");
	scanf_s("%d", &N);

	if (N < 3)
	{
		printf("잘못된 값\n");
		goto FIRST;
	}

	int count = 0;
	printf("x, y 입력\n");
	//참고로 c언어는 (다른 언어들도 그렇지만)
	//변수명 지을 때 대소문자 구분한다.
	//그래도 대소문자 가지고만 구분하면 헷갈리지 주의한다.
	//참고로!!! 사실... 대문자는 상수에서만 쓰이는 문자
	//ex) PI=3.14처럼 정해진 상수에서만 사실 대문자를 쓴다.
	//대부분 변수는 소문자임
	scanf_s("%d %d", &X, &Y);
	int resultX = X;
	int resultY = Y;

이수성:
	count+=1;//count값 하나 증가
	if (count < N)
	{
		resultX *= X;
		resultY *= Y;
		goto 이수성;
	}
	else
		printf("z^%d = %d\n", N, resultX + resultY);
	


	return 0;
}