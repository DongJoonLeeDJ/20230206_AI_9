#include"myfunc.h"//사용자가 만든 헤더파일은 큰따옴표로 적는다.
//myfunc.h안에 stdio.h가 있으니 printf도 자동으로 된다.
//함수도 바로 호출 가능
#include<stdio.h> //이런식으로 또 써도 된다는 의미(#pragma once)
int main()
{
	printf("%d\n", sum(1, 100, 3));
	return 0;
}