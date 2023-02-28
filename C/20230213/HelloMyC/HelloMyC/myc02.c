#include<stdio.h>
int main()
{




	//#region 치고 tab키 2번 누르기
	//XCode(맥북의 C 실행하는 프로그램)에선 안 됨
#pragma region first question


	//if(x=0) 이런 코드는 절대 실행하지 않는 코드
	//if(x==0) x가 0일 때 실행하는 코드
	if (0) //절대 실행되지 않는 코드
	{
		int x, y;
		printf("두 개의 숫자를 입력하세요.\n");
		scanf_s("%d %d", &x, &y);//두 개의 숫자를 입력할 수 있다.
		if (x > 0 && y > 0) //주의사항! if, else if, else 끝에 ; 붙이지 마세요.
			printf("1\n");
		else if (x < 0 && y>0)
			printf("2\n");
		else if (x < 0 && y < 0)
			printf("3\n");
		else if (x > 0 && y < 0)
			printf("4\n");
		else
			printf("0\n");

		//똑같은 결과에 다른 코드
		if (x > 0)
		{
			if (y > 0)
				printf("1\n");
			else if (y == 0)
				printf("0\n");
			else
				printf("4\n");
		}
		else if (x == 0)
		{
			printf("0");
		}
		else
		{
			if (y > 0)
				printf("2\n");
			else if (y == 0)
				printf("0\n");
			else
				printf("3\n");
		}
	}


#pragma endregion
	

	if (0)
	{


	printf("나이를 입력하세요.\n");
	int age;
	scanf_s("%d", &age);
	if (age < 0 || age>200)
		printf("타노스\n");
	else if (age < 20) //age 값은 0부터 19까지
		printf("미성년자\n");
	else if (age < 51) //age값은 20부터 50까지
		printf("사회의 주 구성원\n");
	else if (age < 71)//age값은 51부터 70까지
		printf("관리자\n");
	else //70부터 200까지는 
		printf("지혜의 도서관\n");

#pragma region 두번째문제


	printf("나이 입력");
	//int age;
	scanf_s("%d", &age);
	if (age < 0 || age>200)
		printf("\n타노스\n");
	else
	{
		if (age < 20)//age는 0이상이라는 게 전제됨
			printf("\n미성년자\n");
		else if (age >= 20 && age <= 50)
			printf("\n사회의 주 구성원\n");
		else if (age <= 70)//51~70세까지
			printf("관리자");
		else if (age >= 71)//else로 끝내도 되긴 함
			printf("지혜의 도서관");
		//else if로 끝내도 된다. 억지로 else 안 써도 됨
	}

#pragma endregion

	}

	int h, m;
	printf("시간은?\n");
	scanf_s("%d", &h);
	
	//만약 시간을 24 이상의 값을 입력한다면?
	//1. if else
	//2. 24로 나눈 나머지를 구하는 방법
	h = h % 24;
	printf("분 입력\n");
	scanf_s("%d", &m);
	if (m >= 60)
	{
		printf("잘못된 값\n");
	}
	else
	{
		m = m - 45;
		if (m < 0)
		{
			m += 60; //m = m + 60이랑 동일한 코드
			h -= 1; //h = h-1이랑 동일한 코드
			if (h < 0)
				h += 24; // h= h+24랑 동일한 코드
		}
		printf("알람 시간 : %d시 %d분\n", h, m);
	}
	


	return 0;
}