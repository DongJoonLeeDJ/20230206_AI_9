#include<stdio.h>
int main()
{
	int a, b, c, d, e, f;
printf("2번 문제: \"5 4 6 2 3 1\"중 한 숫자를 입력하시오\n");
scanf_s("%d", &a);

b = (a*5)%7;
c = (b*5)%7;
d = (c*5)%7;
e = (d*5)%7;
f = (e*5)%7;


printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);



return 0;
}