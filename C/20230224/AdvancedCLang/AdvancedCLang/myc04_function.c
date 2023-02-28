//function 펑션
//function = 기능
//수학에서의 함수 => 특정 input에 따른 특정 output이 나오는 것
//y=f(x)
//f(x) = x+9
//f(11) = 20
//f(x) = 9
//f(x) = x*0 + 9
//f(x) = 0
//특정한 값을 받아와서 그 것에 따라서 동작을 다르게 하는 것 
//=> 코딩에서는 값을 받는 게 없거나, 값을 받아도 항상 같은 동작을 하는 함수들도 있다.
//코딩에서의 함수 : 코드 뭉치, 기능 뭉치, 코드 덩어리, 미리 정의된 기능 등으로 볼 수 있다.
#include<stdio.h>
//피타 고라스의 정리
int pita(int a, int b) //이런식으로 생긴 걸 "함수"
{
	return (a * a) + (b * b);
}
int calculator(int a, int b, char c) //계산기
{
	int result = 0;
	switch (c)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
	case 'x':
	case 'X':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	case '%':
		result = a % b;
		break;
	default:
		printf("%c는 잘못된 연산입니다.\n", c);
		break;
	}
	return result;
}

//오일러의 평면 도형의 공식
//F+V-E=2
//F 면의 개수
//V 꼭짓점의 개수
//E 모서리의 개수
//앞에 붙은 int를 "반환형 혹은 리턴형"이라고 부릅니다.
//괄호 안에 있는 것들을 매개변수 혹은 파라메터(parameter) 혹은 아규먼트(arg)라고도 부르기도 합니다.
//return은 반환형 혹은 리턴형이라고 부른다.
int isEuler(int F, int V, int E) //숫자 3개가 오일러의 평면 공식을 만족하는 지 여부 체크
{
	int result = F + V - E;
	if (result == 2)
		return 1;
	else
		return 0;
}

int main() //main = 함수
{
	printf("%d\n", pita(3, 4));
	int c = pita(3, 4);
	printf("%d\n", c);
	int a = 3;
	int b = 4;
	c = pita(3, 4);
	printf("%d\n", c);

	int d = calculator(10, 20, '+');
	printf("%d %d\n", d, calculator(20, 10, '-'));
	int n = printf("안녕하세요\n");
	printf("%d\n", n);
	printf("%d\n", printf("안녕하세요"));


	int result = isEuler(10, 20, 30);//10+20-30 = 0
	if (result)
		printf("오일러공식 만족!\n"); //만족하지 못 함
	if (isEuler(2, 4, 4))
		printf("Euler 공식 만족해요\n"); //만족하므로 출력을 한다.



	return 0;
}