#include<stdio.h>
int main()
{
	//앞에서 배운 논리연산의 AND OR XOR보다
	//훨씬 중요한 내용
	//AND &&
	//조건들이 모두 맞아야 참
	//나이를 입력받는 데, 0 초과, 200미만이어야 한다.
	int age;
	printf("몇살?");
	scanf_s("%d", &age);
	age > 0 && age < 200 ? printf("나이:%d\n", age) : printf("X\n");
	//OR
	//조건들 중 하나라도 맞으면 참
	age <= 0 || age >= 200 ? printf("X\n") : printf("나이:%d\n", age);
	//<= : 이하
	//>= : 이상

	//XOR (^) => 논리 연산이랑 똑같이 ^ 이거 하나만 쓴다.
	//적절한 예시는 생각나지 않음...
	//조건이 전부 참 혹은 전부 거짓인 경우엔 거짓이며
	//그 외에는 전부 참
	return 0;
}