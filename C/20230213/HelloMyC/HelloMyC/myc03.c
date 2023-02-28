#include<stdio.h>
int main()
{
	if (0)
	{
		printf("문제 시작");
		START: //일종의 선언이니 중복을 주의하라
		printf("시간과 분을 입력하세요.\n");
		int h, m;
		scanf_s("%d %d", &h, &m);
		if (h < 0 || h>23 || m < 0 || m>60)
		{
			printf("다시 입력하세요.\n");
			goto START;
		}//1. 나머지 부분 다 적어보세요(3번문제랑 동일함)
		else
		{
			m -= 45;
			if (m < 0)
			{
				m += 60; //m = m+60
				h -= 1; // h=h-1
				if (h < 0)
					h += 24;
			}
			printf("알람이 울리는 시간 : %d시 %d분\n", h, m);
		}
	
		//2. 1번 문제(사분면)에서 x나 y가 0이 나오면 다시 입력하게 해보기


		int x, y;
		START2:
		printf("x y는?");
		scanf_s("%d %d", &x, &y);
		if (x == 0 || y == 0)
			goto START2;
		else
			printf("x=%d, y=%d\n", x, y);

	}
	//3. 2번 문제에서 타노스가 탄생하는 경우에는 나이를 다시 입력하게 하기
	int m; //변수 선언 중복 안 된다고 했는 데 되네?
START3:
	printf("나이 입력");
	scanf_s("%d", &m);
	if (m < 0 || m>200)
	{
		printf("\n인피니티 스톤 타노스\n");
		goto START3;
	}
	printf("나이 : %d\n", m);

	return 0;
}