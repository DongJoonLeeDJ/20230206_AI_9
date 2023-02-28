#include<stdio.h>
int main()
{
	//1. 변수 a와 b와 c의 값을 입력받고, 
	//a부터 b까지의 합을 구하되, c의 배수 부분은
	//제외하고 합을 구할 것.
	int a, b, c;
	printf("숫자 3개를 입력하세요.\n");
	scanf_s("%d %d %d", &a, &b, &c);
	int s = 0;
	if (a <= b)
	{
		for (int i = a; i <= b; i++)
		{
			if (i % c != 0)
				s += i;
		}
		printf("%d부터 %d까지의 합(%d 배수 제외) : %d\n",a,b,c,s);
	}
	else //a가 b보다 더 크다면 어떻게 해야 할까요?
	{
		//1. 단순히 잘못됐다는 메시지를 띄울 수도 있다.
		printf("a(%d)가 b(%d)보다 큽니다. 값을 바꾸겠습니다.\n",a,b);
		//2. a와 b의 값을 서로 바꾼 다음에 연산을 수행할 수 있다.
		int temp = a;
		a = b;
		b = temp;

		for (int i = a; i <= b; i++)
		{
			if (i % c != 0)
				s += i;
		}
		printf("%d부터 %d까지의 합(%d 배수 제외) : %d\n", a, b, c, s);
	}


	return 0;
}