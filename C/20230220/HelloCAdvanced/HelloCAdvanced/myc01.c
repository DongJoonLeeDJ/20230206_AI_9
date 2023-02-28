#include<stdio.h>
int main()
{
	int a = 10; //변수
	int* ptra = &a; //변수 a의 주소 = &a
	//ptra = 변수 a의 주소를 저장하는 변수
	//int = 정수형 변수
	//int* = 정수형 변수의 주소를 저장하는 타입
	//이 주소를 저장하는 걸 "포인터"라고 합니다.
	//문법은 * 이다.
	printf("%d %d %d %d\n", a, &a, ptra, *ptra);
	*ptra = 1000; //ptra라는 주소가 가리키는 곳의 값을 1000으로 바꿈(즉 a의 값을 1000으로 바꿈)
	printf("a=%d\n", a);//a값이 1000으로 바뀜
	int** pptt = &ptra;
	printf("%d %d %d %d\n", pptt, &ptra, *pptt, **pptt);



	//포인터를 잘 알아야 배열을 잘 알 수 있다.
	// 
	//포인터 나중에 함수 배울 때도 응용되는 개념이다!
	//가장 대표적으로는 swap 함수 문제가 있다.

	//어쨌든 포인터를 잘 알아야 배열을 알 수 있고 더 나아가서 문자열도 이해 가능하다.
	int numbers[5] = { 1,2,3,4,5 }; //5칸짜리 배열에 숫자 5개 저장된 것
	int numbers2[3]; //3칸짜리 배열에 숫자 3개 저장된 것

	//대괄호 안에 있는 숫자를 인덱스라고 하는 데,
	//가장 첫번째 칸에 있는 숫자를 가리킬 때 [0]을 쓴다.
	//가장 끝 칸에 있는 숫자를 가리킬 때 [길이-1]을 쓴다. ex) 길이가 3이면 [2]
	numbers2[0] = 100;
	numbers2[1] = 1000;
	numbers2[2] = 10000;

	//지금까지는 하나의 하나의 값 저장
	//배열을 쓰게 되면 하나의 변수로 여러 개의 숫자를 일괄적으로 관리 가능

	for (int i = 0; i < 5; i++)
		printf("%d\n", numbers[i]);//1 2 3 4 5

	for (int i = 0; i < 3; i++)
		printf("%d\n", numbers2[i]);//100 1000 10000



	for (int i = 0; i < 5; i++)
		printf("%d\n", *(numbers+i));

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *(numbers + i));// 1 2 3 4 5
		printf("%d\n", &(numbers[i]));// 1주소 2주소 3주소 4주소 5주소
	}

	int* p = numbers;
	for (int i = 0; i < 5; i++)
		printf("%d\n", p[i]);

	return 0;
}