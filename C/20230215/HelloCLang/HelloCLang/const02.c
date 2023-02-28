//const, 매크로상수(#define) 없앤 것
//myc06을 분리한 것


#include<stdio.h>
//세 번째 방법 = 열거형 = Enumeration
enum RCP //Rock Scissor Paper 
{
	//RCP는 미국식이므로 한국식으로 재배열한다.
	//가위 바위 보
	SCISSOR, ROCK, PAPPER
};
//enum의 특징
enum MyRCP
{
	ROCK2 = 1, SCISSOR2, PAPPER2, GUN = 5, WOLF, AIR
};
int main()
{
	//0=가위, 1=바위, 2=보
	
	int first, second; //1p, 2p
	printf("가위 바위 보!(1p)\n");
	scanf_s("%d", &first);
	if (first != SCISSOR && first != ROCK && first != PAPPER) //0,1,2보단 가독성이 좋음
		printf("잘못된 값!\n");
	else
	{
		printf("가위 바위 보!(2p)\n");
		scanf_s("%d", &second);
		//second 값이 0, 1, 2 중 하나인 경우
		if (second == SCISSOR || second == ROCK || second == PAPPER)
		{
			//enum RCP a = ROCK;
			switch (first)
			{
			case SCISSOR: //1P가 가위를 낸 경우
				printf("1P : 가위\n");
				switch (second) //2가 낸 것들
				{
				case SCISSOR: //2P 가위
					printf("2P : 가위\n");
					printf("무승부\n");
					break;
				case ROCK: //2P 바위
					printf("2P : 바위\n");
					printf("1P 패\n");
					break;
				case PAPPER: //2P 보
					printf("2P : 보\n");
					printf("1P 승\n");
					break;
				default:
					break;
				}
				break;
			case ROCK: //1P가 바위를 낸 경우
				printf("1p: 바위!\n");
				switch (second)
				{
				case SCISSOR: //매크로 상수 이용한 것
					printf("2P 가위\n");
					printf("1P 승!\n");
					break;
				case ROCK:
					printf("2P 바위\n");
					printf("무승부!\n");
					break;
				case PAPPER:
					printf("2P 보\n");
					printf("1P 패!\n");
					break;
				default:
					break;
				}
				break;
			case PAPPER: //1P가 보를 낸 경우
				printf("1P : 보\n");
				switch (second)
				{
				case SCISSOR: //매크로 상수 이용한 것
					printf("2P 가위\n");
					printf("1P 패!\n");
					break;
				case ROCK:
					printf("2P 바위\n");
					printf("1P 승리!\n");
					break;
				case PAPPER:
					printf("2P 보\n");
					printf("무승부!\n");
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
		else
		{
			printf("게임을 할 수 없습니다.\n");
		}
	}

	return 0;
}