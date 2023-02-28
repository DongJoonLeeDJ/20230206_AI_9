//a부터 b까지의 합을 구하는 함수를 만드세요.(매개변수 a,b)
//a부터 b까지의 합 혹은 곱을 구하는 함수를 만드세요.(매개변수 a,b,c)
//끝에 c는 + 혹은 x 혹은 X 혹은 *만 들어가고 그 외의 값이 오면 0을 리턴하게 한다.
#include<stdio.h>
int sum_a_to_b(int a, int b) //예외처리가 필요하나 그냥 넘어감
{
	int sum = 0;
	for (int i = a; i <= b; i++)
		sum += i;
	return sum;
}
int calc_a_to_b(int a, int b, char c)
{
	int sum = 0;
	switch (c)
	{
	case '+':
		//for (int i = a; i <= b; i++)
		//	sum += i;
		//sum_a_to_b가 위에 선언돼있으니 아래에서도 쓸 수 있다!
		sum = sum_a_to_b(a, b); //함수에서 또 다른 함수 호출 가능함!
		break;
	case '*':
	case 'x':
	case 'X':
		sum = 1; //곱이므로 sum을 1로 초기화
		for (int i = a; i <= b; i++)
			sum *= i;
		break;
	default:
		sum = 0;
		printf("잘못된 수식 %c\n", c);
		break;
	}

	return sum;

}

int main()
{
	int result = sum_a_to_b(2, 5); //14
	printf("합 : %d\n", result);
	result = calc_a_to_b(2, 5,'x'); //120
	printf("곱 : %d\n", result);
	return 0;
}