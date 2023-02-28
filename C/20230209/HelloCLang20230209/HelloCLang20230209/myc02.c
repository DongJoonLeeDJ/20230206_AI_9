#include<stdio.h>
int main()
{
	//논리 연산
	//"[AND OR] XOR" NOT

	// AND : & , 하나라도 거짓이면 모두 거짓
	// OR : | , 하나라도 참이면 모두 참
	// XOR : ^ , 전부 거짓이거나 전부 참이면 거짓
	//			하나라도 다른 게 있으면 참
	//배타적 OR(eXclusive OR)
	//논리연산
	printf("AND : %d\n", 9 & 8); //8
	printf("OR : %d\n", 9 | 8); //9
	printf("XOR : %d\n", 9 ^ 8); //1
 

	//bit연산
	//shift 연산. 0을 이동시킴
	//숫자를 2진수로 바꾼 다음 0을 더 삽입하거나
	//숫자를 자리수만큼 이동한다.
	printf("%d\n", 8 << 2); //32
	printf("%d\n", 8 >> 2); //2
	return 0;
}