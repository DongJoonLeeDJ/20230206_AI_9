#include<stdio.h>
int main()
{
	int a, b, c, d, e, f;

	printf("1번문제: 3자리 숫자 2개를 입력하시오\n");
	scanf_s("%d %d", &a, &b);
	c = b % 10;
	d = (b % 100-c)/10;
	e = (b - c - d) / 100;
	printf("1) 첫번째 숫자와 두번째 숫자의 일의자리 곱의 값은 %d\n", a * c);
	printf("1) 첫번째 숫자와 두번째 숫자의 십의자리 곱의 값은 %d\n", a * d);
	printf("1) 첫번째 숫자와 두번째 숫자의 백의자리 곱의 값은 %d\n", a * e);
	printf("1) 첫번째 숫자와 두번째 숫자 곱의 값은 %d\n\n", a * b);



	printf("2번 문제: \"5 4 6 2 3 1\"중 한 숫자를 입력하시오\n");
	scanf_s("%d", &a);

	b = (a * 5) % 7;
	c = (b * 5) % 7;
	d = (c * 5) % 7;
	e = (d * 5) % 7;
	f = (e * 5) % 7;


	printf("%d %d %d %d %d %d", a,b, c, d,e,f);


	return 0;

}