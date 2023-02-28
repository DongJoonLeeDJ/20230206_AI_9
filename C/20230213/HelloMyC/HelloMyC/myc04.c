#include<stdio.h>
int main()
{
	//경우의 수를 여러 개 나열하고 싶을 때
	//적는 것을 바로 switch문
	//if else if else if else if else 이렇게 적는것보다
	//경우의 수가 더 잘 보이고 더 간결해보인다.

	int dice;
	printf("주사위 눈을 굴려보세요.\n");
	scanf_s("%d", &dice);
	if (dice == 1)
		printf("눈은 하나 입니다.\n");
	else if (dice == 2)
		printf("눈은 둘 입니다.\n");
	else if (dice == 3)
		printf("눈은 셋 입니다.\n");
	else if (dice == 4 || dice == 5 || dice == 6)
		printf("눈은 일이삼은 아님\n");
	else
		printf("이상한 값\n");

	switch (dice)
	{
	case 1:
		printf("일");
		break;
	case 2:
		printf("이");
		break;
	case 3:
		printf("삼");
		break;
	case 4:
		printf("사");
	case 5:
	case 6:
		printf("일이삼은 아님");
		break;
	default:
		printf("%d는 잘못된 값\n", dice);
		break;
	}

	return 0;
}