#include<stdio.h>
int main()
{
	if (0) //0의 의미 = 거짓, 0이 아닌 숫자의 의미 = 참
	{		//이 코드의 의미 = 이 중괄호 안에 있는 코드를 절대로 실행하지 않는다.

	



	//저번에 풀었던 수열 문제 (반복되는 순환 수열 5 4 6 2 3 1)  이제 조건문으로 풀어보세요.
	// 5를 입력하면 5 4 6 2 3 1
	// 4를 입력하면 4 6 2 3 1 5
	// 1을 입력하면 1 5 4 6 2 3


	int input;
	printf("숫자를 입력하세요.");

	//scanf랑 scanf_s 차이 : _s = safe를 의미, 최신 문법, 메모리상에 문제가 발생하는 걸 막아줌
	//&input 할 때 잘못된 변수를 집어넣어서 엉뚱한 주소지에 값을 잘못바꾸면 프로그램이 꺼지거나
	//치명적인 오류가 발생할 수 있다. 그걸 대비해주는 것이 _s이다.
	scanf_s("%d", &input);

	//if문으로 입력
	//|| = OR(~이거나) , shift 키 + escape 문자 같이 누르면 생김
	if (input < 1 || input > 6)
		printf("잘못된 값\n");
	else //if에 있는 조건이 아니면...
	{
		if (input == 1) //if문 끝에 세미콜론 붙이지 말기!!!!!! ex) if(input==1); 
			printf("1 5 4 6 2 3\n");
		else if (input == 2)
			printf("2 3 1 5 4 6\n");
		else if (input == 3)
			printf("3 1 5 4 6 2\n");
		else if (input == 4)
			printf("4 6 2 3 1 5\n");
		else if (input == 5)
			printf("5 4 6 2 3 1\n");
		else //경우의 수가 6만 남음
			printf("6 2 3 1 5 4\n");
	}

	//switch문
	//case by case로 경우의 수를 한 줄로 편하게 나열할 때 쓴다.
	//if문보다 성능은 나쁘지만 간결하다.
	//어떤 부분에서 성능이 나쁘다고 한 건지 생각해보기 hint) 3.1과 3.2 사이의 숫자 개수는?

	switch (input)
	{
	case 1:
		printf("1 5 4 6 2 3\n");
		break;
	case 2:
		printf("2 3 1 5 4 6\n");
		break;
	case 3:
		printf("3 1 5 4 6 2\n");
		break;
	case 4:
		printf("4 6 2 3 1 5\n");
		break;
	case 5:
		printf("5 4 6 2 3 1\n");
		break;
	case 6:
		printf("6 2 3 1 5 4\n");
		break;
	default:
		printf("잘못된 값입니다.\n");
		break;
	}


	}

	if (0) 
	{
#pragma region study birth season



	//주석 : 이런 녹색글자, 컴퓨터가 아닌 사람이 읽는 문서
	//ctrl k c = 주석
	//ctrl k u = 주석 해제
	//4. 내가 태어난 월을 입력하고, 그 달의 계절을 출력하세요,
	/*12, 1, 2는 겨울이며 3, 4, 5는 봄, 6, 7, 8은 여름, 9, 10, 11은 가을이며 그 외의 값에 대해선 예외처리하기

	(단, if문이랑 switch문을 모두 사용해서 풀어보세요.)*/

	//if문
	int month;
	printf("몇 월에 태어나셨어요?\n");
	scanf_s("%d", &month);
	if (month == 12 || month == 1 || month == 2)
		printf("겨울\n");
	else if (month == 3 || month == 4 || month == 5)
		printf("봄\n");
	else if (month >= 6 && month <= 8)
		printf("여름\n");
	else if (month >= 9 && month <= 11)
		printf("가을\n");
	else
		printf("잘못된 값입니다.\n");

	switch (month)
	{
	case 12:
	case 1:
	case 2:
		printf("winter is comming\n");
		break;
	case 3:	case 4:	case 5: printf("spring\n"); //이렇게 한 줄로 적진 마세요. 가독성이 떨어짐
		break;
	case 6:
	case 7:
	case 8:
		printf("summer\n");
		break;
	case 9:
	case 10:
	case 11:
		printf("autumn\n");
		break;
	default:
		printf("wrong month\n");
		break;
	}
#pragma endregion


	}

	if (0)
	{

	printf("밑변 A와 높이 B의 길이를 입력하시오.\n");
	int A, B, C; //이런식으로 변수 여러 개 선언하는 것 가능해요.
	scanf_s("%d %d", &A, &B); //한 번에 2개 값 입력
	C = (A * A) + (B * B);
	printf("%d^2 + %d^2 = %d\n", A, B, C);

	printf("A B를 입력하고 그에 맞는 해를 맞춰보세요.(C^2 값을 맞추기)\n");
	//ex) 2 3 13 => 2^2 + 3^2 = 13 => O 2 3 14 => X
	scanf_s("%d %d %d", &A, &B, &C); //한 번에 숫자 3개 입력하는 것
	if (((A * A) + (B * B)) == C)
		printf("O\n");
	else
		printf("X\n");

	//더크면 + 
	//더 작으면 -를 출력
	if (((A * A) + (B * B)) == C)
		printf("O\n");
	else 
	{
		if (((A * A) + (B * B)) < C)
			printf("+\n");
		else
			printf("-\n");
	}

	}

	//6. 페르마의 마지막 정리에 나오는 수식에서 Z^n의 값을 구하시오.
	//('n> 2 일 때, xⁿ +yⁿ =zⁿ 방정식을 만족하는 양의 정수 x, y, z는 존재하지 않는다')
	//n이 3이라고 가정하고 진행
	int x, y;
	printf("x와 y의 값을 입력하세요.\n");
	scanf_s("%d %d", &x, &y);
	printf("n=3, x=%d, y=%d 일 경우, z^3=%d\n", x, y, (x* x* x) + (y * y * y));


	return 0;
}