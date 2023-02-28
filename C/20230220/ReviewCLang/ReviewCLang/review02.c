//문제
//나이를 입력하세요. 나이가 10대미만이면 응애 10대이면 잼민 20대이면 청춘 30대랑 40대면 사회의 main
//50 60대면 관리자이고 70대 이상이면 지혜의 도서관 그리고 100살이면 불멸자
//음수인 경우 타노스
//주의사항 : 예외처리는 if문으로 하되 10대부터 70대까지는 switch문으로 표현하기
//단, case 10: case 11 이런 노가다 하시면 안 됩니다.
//추가 예외 100살을 넘는 경우에도 불멸자라고 합시다. 즉 70~99까진 지혜의 도서관
//100살부턴 불멸자.
#include<stdio.h>
int main()
{
	printf("몇 살 이에요?\n");
	int age;
	scanf_s("%d", &age);

	if (age < 0) //범위 관련된 것은 switch문으로 설정할 수 없다.
	{
		printf("타노스\n");
	}
	else
	{
		//age / 10 = age값이 9면 9/10 => 0
		//age 값이 19면 19/10 => 1
		//age 값이 21이면 21/10 => 2
		//이런식으로 10대 20대를 나눌 수 있다.
		switch (age / 10)
		{
			case 0:
				printf("응애\n");
				break;
			case 1:
				printf("잼민\n");
				break;
			case 2:
				printf("청춘\n");
				break;
			case 3:
			case 4:
				printf("사회의 main\n");
				break;
			case 5:
			case 6:
				printf("관리자\n");
				break;
			case 7:
			case 8:
			case 9:
				printf("지헤의 도서관");
				break;
			default:
				printf("불멸자\n");
				break;
		}
	}

	return 0;
}