#include<stdio.h>
int main()
{
	// 올해 연도 입력받기
	int year; //정수만 저장하므로 소수점은 전부 버림
	printf("올해는 몇년도인가요?"); //출력
	scanf_s("%d", &year); //입력, year 변수에 값 입력하게 함
	printf("\n올해는 %d년도입니다.\n", year);

	int age;
	printf("내 나이는?");
	scanf_s("%d", &age);
	printf("\n저는 %d년생입니다.\n", year - age + 1);

	//한 번에 여러 개의 숫자를 입력할 수 있다.
	printf("태어난 연도랑 나이를 입력하세요.\n");
	int birth;
	scanf_s("%d %d", &birth, &age);//1989 35 이렇게 입력
	printf("지금은 %d년도입니다.\n", birth + age - 1);

	scanf_s("%d,%d", &birth, &age); //1989,35 이렇게 입력해야 함
	printf("birth:%d, age:%d\n", birth, age);
	return 0;
}