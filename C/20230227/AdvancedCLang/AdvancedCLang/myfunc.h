#pragma once //헤더파일이 중복되도 허용한다는 뜻
//stdio.h등의 헤더파일에도 해당 키워드가 있음.

//myfunc안에 stdio를 넣었기 때문에
//이 헤더 파일을 쓸 경우엔 stdio.h를 생략 가능
#include<stdio.h>
//a부터 b까지의 합을 구하되 c만큼 증가하는 합 구함
//ex) 1부터 100까지의 합을 구하되 3만큼 증가하는 합 구하기
//1 4 7 10 ... 100이하까지 다 더해서 sum을 리턴
int sum(int a, int b, int c)
{
	int sum = 0;
	for (int i = a; i <= b; i += c)
		sum += i;
	return sum;
}
//주의사항
//헤더 파일 안에 함수의 정의를 썼다면
//일관되게 함수의 정의만 써야하고
//함수의 원형(머리만 있는 것)을 썼다면 일관되게 원형만 써야 한다.
//즉 여기서 int pitagoras(int, int); 이렇게 추가는 안 됩니다.
