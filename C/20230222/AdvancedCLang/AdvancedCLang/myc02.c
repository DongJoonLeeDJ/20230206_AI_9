#include<stdio.h>
int main()
{
	char name[100];//이름
	int age;//나이
	char bType[100]; //혈액형
	printf("이름은?\n");
	gets(name);
	printf("나이는?\n");
	scanf_s("%d", &age);//visual studio용 함수, _s는 메모리 오버플로우 방지
	rewind(stdin);//버퍼처리하는 시점. 직전에 숫자나 문자(1글자)를 입력한 경우
	//엔터키가 버퍼에 남아 있다. 이 것때문에 그 다음에 입력할 문자에 \n이 들어가버리므로
	//이를 방지하기 위한 기능
	printf("혈액형은?\n");
	gets(bType);
	printf("%s %d %s\n", name, age, bType);

	
	//이거 안 됨
	//동적할당 배워야 함
	//수업시간엔 안 할 것이고, 별도로 공부하시거나
	//나중에 java나 c#할 때 언급해드릴 것
	//int size = 100;
	//int mynum[size]; 

	return 0;
}