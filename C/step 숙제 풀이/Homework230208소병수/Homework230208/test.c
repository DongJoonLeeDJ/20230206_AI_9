#include<stdio.h>
int main()
{
	int a, b, c, d, e, f;
printf("2�� ����: \"5 4 6 2 3 1\"�� �� ���ڸ� �Է��Ͻÿ�\n");
scanf_s("%d", &a);

b = (a*5)%7;
c = (b*5)%7;
d = (c*5)%7;
e = (d*5)%7;
f = (e*5)%7;


printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);



return 0;
}