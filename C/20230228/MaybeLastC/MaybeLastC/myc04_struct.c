#include<stdio.h>
//#include<string.h> //c99 혹은 맥북사용자는 이 헤더 파일 추가해야 함
// 윈도 사용자는 이거 추가하면 sdl 검사 끄거나 strcpy_s를 써야함 ㅠㅠ

//기존에 정해진 변수가 아니고, 사용자가 직접 정의한 자료형을 사용할 수 있다.
//정수, 문자, 실수만으로 데이터를 저장하기 어렵고, 하나의 자료형이 종합적인 값을 갖게
//하고 싶을 때 사용하는 것이 바로 구조체입니다.
//(struct, java에선 class가 있고 c++과 c#에선 구조체, 클래스 둘 다 있음)
struct Student {
	char name[100];
	int age;
};
int main()
{
	struct Student sslee;
	strcpy(sslee.name,"이수성" ); //선언만 하고 문자열 집어넣을 땐 strcpy이용해야 함
	sslee.age = 20;
	printf("%s %d\n", sslee.name, sslee.age);
	struct Student djlee = { "이동준", 35 }; //선언과 동시에 문자열 넣기 가능
	struct Student dhshin = { .age = 20, .name = "신동훈" }; //속성 지정 가능
	struct Student bsSo;
	printf("이름이 뭐야?");
	gets(bsSo.name); //수동으로 입력받게 하는 것도 가능
	printf("나이는?");
	scanf_s("%d", &bsSo.age);
	printf("%s %d\n", sslee.name, sslee.age);
	printf("%s %d\n", djlee.name, djlee.age);
	printf("%s %d\n", dhshin.name, dhshin.age);
	printf("%s %d\n", bsSo.name, bsSo.age);

	return 0;
}