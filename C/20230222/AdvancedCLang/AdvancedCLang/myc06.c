//문자열이랑 별개로... 숫자 5개 입력하고 그 중에 최댓값, 최솟값 찾기
//그 다음  그 것들이 각각 몇번째 있는지 찾아서 출력하세요
//그 다음 다 풀고 이 것들도 포인터 문법 이용하기(처음 배열 선언시에만 대괄호쓰기)
#include<stdio.h>
int main()
{
	int num[5];
	//for (int i = 0; i < 5; i++)
	printf("숫자 5개 입력해\n");
	for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++)
	{
		scanf("%d", &num[i]);
	}
	printf("%d %d %d %d %d\n", num[0], num[1], num[2], num[3], num[4]);


	int maxth, minth, max, min;
	maxth = 0;
	minth = 0;
	max = num[0];
	min = num[0];
	for (int i = 0; i < 5; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
			maxth = i;
		}
		if (num[i] < min)
		{
			min = num[i];
			minth = i;
		}
	}
	printf("큰 값 : %d, 큰 값의 인덱스 : [%d], 작은 값 : %d, 작은 값 인덱스 : [%d]\n",
		max,maxth,min,minth);
	return 0;
}
