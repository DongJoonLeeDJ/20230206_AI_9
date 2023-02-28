//열거형 없앤 것
//myc06을 분리한 것
#include<stdio.h>
#define GAWI 0
#define BAWI 1
#define BO 2
int main()
{
	//0=가위, 1=바위, 2=보
	//상수를 이용해서 가독성을 증가시킨다.
	//방법 3개
	//첫번째 const
	//const가 들어가면 상수는 맞는 데
	//const int의 정확한 의미 : 값이 변하지 않는 변수. 처음 선언시에만 값이
	//정의되고 그 이후엔 값이 변화되지 않는 변수라고 보면 된다.
	//그래서 case 뒤에는 올 수 없다.
	const int 가위 = 0; //참고로 한글변수는 권장하지 않는다. 차라리 GAWI라고 쓸 것
	const int 바위 = 1;
	const int 보 = 2;

	int first, second; //1p, 2p
	printf("가위 바위 보!(1p)\n");
	scanf_s("%d", &first);
	if (first != 가위 && first != 바위 && first != 보) //0,1,2보단 가독성이 좋음
		printf("잘못된 값!\n");
	else
	{
		printf("가위 바위 보!(2p)\n");
		scanf_s("%d", &second);
		//second 값이 0, 1, 2 중 하나인 경우
		if (second == 가위 || second == 바위 || second == 보)
		{
			//enum RCP a = 바위;
			switch (first)
			{
				//const를 이용해서 만든 상수는 못 들어감
			case GAWI: //#define한 거나 enum한 것만 들어감.       //1P가 가위를 낸 경우
				printf("1P : 가위\n");
				switch (second) //2가 낸 것들
				{
				case GAWI: //2P 가위
					printf("2P : 가위\n");
					printf("무승부\n");
					break;
				case BAWI: //2P 바위
					printf("2P : 바위\n");
					printf("1P 패\n");
					break;
				case BO: //2P 보
					printf("2P : 보\n");
					printf("1P 승\n");
					break;
				default:
					break;
				}
				break;
			case BAWI: //1P가 바위를 낸 경우
				printf("1p: 바위!\n");
				switch (second)
				{
				case GAWI: //매크로 상수 이용한 것
					printf("2P 가위\n");
					printf("1P 승!\n");
					break;
				case BAWI:
					printf("2P 바위\n");
					printf("무승부!\n");
					break;
				case BO:
					printf("2P 보\n");
					printf("1P 패!\n");
					break;
				default:
					break;
				}
				break;
			case BO: //1P가 보를 낸 경우
				printf("1P : 보\n");
				switch (second)
				{
				case GAWI: //매크로 상수 이용한 것
					printf("2P 가위\n");
					printf("1P 패!\n");
					break;
				case BAWI:
					printf("2P 바위\n");
					printf("1P 승리!\n");
					break;
				case BO:
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