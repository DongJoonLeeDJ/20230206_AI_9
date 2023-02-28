#include<stdio.h>
int main()
{
	//1.수를 입력받고
	//그 수가 2022면 한반두
	//아니면 날강두 출력
	int year;
	printf("중꺾마 입력");
	scanf_s("%d", &year);
	year == 2022 ? printf("한반두") : printf("날강두");

	//2. 나이를 입력한다.
	//그리고 20살 미만이면 아이, 20살 이상이면 성인이라고 출력한다.
	int age;
	printf("몇 살?");
	scanf_s("%d", &age);
	age < 20 ? printf("아이\n") : printf("성인\n");

	//3. 1번에 대해서 0 미만의 수인 경우는 잘못된 것이라는 
	//메시지 예외처리 추가한다.
	//삼항 연산자는 중첩이 가능함.
	age < 20 ? (age < 0 ? printf("잘못된 나이\n") : printf("아이\n")) : printf("성인\n");

	//4. 수를 입력한다. 양수 0 음수 중 하나 출력
	int number;
	printf("수를 입력해주세요.\n");
	scanf_s("%d", &number);
	number != 0 ? ( number > 0 ? printf("양수\n"): printf("음수\n")) : printf("0\n");

	//5. char 변수 선언한다. int 변수 선언한다. int 변수에 수를 입력한다.
	int mynum;
	printf("수를 입력할 것\n");
	scanf_s("%d", &mynum);
	char c = mynum > 0 ? '+' : (mynum == 0 ? '0' : '-');
	printf("결과 : %c\n", c);
}