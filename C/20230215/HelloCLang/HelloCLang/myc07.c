#include<stdio.h>
//가위 바위 보
#define GAWI 0
#define BAWI 1
#define BO 2

//결과
#define WIN 'W'
#define DRAW 'D'
#define LOOSE 'L'

int main()
{
	char result = DRAW; //결과를 저장하는 변수
	for (; result != WIN; )//선언부, 증감부를 생략
	{
		int first, second;
		printf("가위 바위 보! 1p와 2p 동시에 내세요!\n");
		scanf_s("%d %d", &first, &second);
		//4. 2번 문제를 풀고, 3번 조건을 하되 1p와 2p의 수의 범위를 제한두지 말 것
		first %= 3; //3으로 나눈 나머지를 이용한 가위, 바위, 보
		second %= 3; 
		//숫자 100같은 거 집어넣어도 100을 1로 보고 즉 바위로 본다.
		if (
			(first != GAWI && first != BAWI && first != BO) ||
			(second != GAWI && second != BAWI && second != BO)
			)
		{
			continue; //다시 돌아가는 것
		}
		else
		{
			switch (first)
			{
				case GAWI:
					printf("1P : 가위\n");
					if (second == BO)
					{
						printf("2P : 보\n");
						result = WIN;
						printf("1P 승리!!!\n");
					}
					else
					{
						if(second==BAWI)
						{
							printf("2P : 바위\n");
							result = LOOSE;
							printf("1P 패배!!!\n");
						}
						else
						{
							printf("2P : 가위\n");
							result = DRAW;
							printf("무승부\n");
						}
					}
					break; //for문을 빠져나가는 break가 아니고 switch문용 break
				case BAWI:
					printf("1P : 바위\n");
					if (second == GAWI)
					{
						printf("2P : 가위\n");
						result = WIN;
						printf("1P 승리!!!\n");
					}
					else
					{
						if (second == BO)
						{
							printf("2P : 보\n");
							result = LOOSE;
							printf("1P 패배!!!\n");
						}
						else
						{
							printf("2P : 바위\n");
							result = DRAW;
							printf("무승부\n");
						}
					}
					break;//for문을 빠져나가는 break가 아니고 switch문용 break
				case BO:
					printf("1P : 보\n");
					if (second == BAWI)
					{
						printf("2P : 바위\n");
						result = WIN;
						printf("1P 승리!!!\n");
					}
					else
					{
						if (second == GAWI)
						{
							printf("2P : 가위\n");
							result = LOOSE;
							printf("1P 패배!!!\n");
						}
						else
						{
							printf("2P : 보\n");
							result = DRAW;
							printf("무승부\n");
						}
					}
					break;//for문을 빠져나가는 break가 아니고 switch문용 break
				default:
					break;//for문을 빠져나가는 break가 아니고 switch문용 break
			}
		}

	}
	return 0;
}