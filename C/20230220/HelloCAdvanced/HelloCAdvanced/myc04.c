#include<stdio.h>
#define MAXSIZE 1024 //굳이 매크로 상수 안 써도 됨
int main()
{
	//문자열 = 문자의 배열
	//넉넉한 크기의 문자 배열을 선언해야
	//문자열을 입력받는 것이 가능
	char a = NULL; //변수 a와 b는 똑같은 것이다. 
	char b = '\0';

	char name[MAXSIZE];
	char bloodType[100];

	printf("이름은?\n");
	gets(name);

	printf("혈액형은?\n");
	gets(bloodType);

	printf("%s %s", name, bloodType);


	//이름, 나이, 키, 혈액형, mbti를 물어보고
	//그 정보를 출력해보세요.
	printf("이름은?\n");
	gets(name);
	printf("나이는?\n");
	int age;
	scanf_s("%d", &age);
	printf("키는?\n");
	double cm;
	scanf_s("%lf", &cm);
	//숫자를 입력받고나서 gets를 쓸 깬 rewind를 쓴다.
	rewind(stdin); //버퍼 청소
	printf("혈액형은?\n");
	gets(bloodType);
	char mbti[5]; //mbti는 4글자이므로 최소 크기는 5다.
	gets(mbti);
	printf("나이 %d, 키 %lf, 이름 %s, 혈액형 %s mbti %s\n",
		age,cm,name,bloodType,mbti);

	return 0;
}