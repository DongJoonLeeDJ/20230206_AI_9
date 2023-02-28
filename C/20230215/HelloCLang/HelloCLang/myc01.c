#include<stdio.h>
int main()
{
	int a = 10;
	a++; //a+=1 이거랑 의미가 같다. //a=a+1이거랑 의미가 같다.
	++a;
	printf("%d\n", a);
	printf("%d %d\n", a++ , ++a);
	printf("%d\n", a);
	printf("%d %d\n", ++a , a++);
	printf("%d\n", a);
	printf("%d\n", ++a); //값을 우선 1 더한 다음에 화면에 출력
	printf("%d\n", a++); //우선 화면에 출력하고 값을 더함
	printf("%d\n", a);

	int b = 100;
	printf("%d\n", b);
	printf("%d\n", ++b + b++);
	printf("%d\n", b);

	//가독성을 위해 그냥 2줄로 적을 것
	//줄 아낄려고 ++이나 --를 앞에 붙이기 보단 두 줄로 표현할 것
	int c = 100;
	c++;
	printf("%d\n", c + c);
	c++;
	printf("%d\n", c);

	return 0;
}