#include <stdio.h>                                 
#include <Windows.h>                             
#include <conio.h>             
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


int Rule_Explain();											// 오목의 룰을 설명하는 함수
int Check_3X3(int x, int y);
int Check_4X4(int x, int y);									// 흑의 착수규칙 (3 x 3)을 체크하는 함수
int Omok_Board[20][20] = { 0,0 };								// 게임 시작전 오목판을 초기화하는 전역변수 
int Color = 2;												// 돌의 시작 색깔을 정하는 전역변수 ( 1 == 백돌 , 2 == 흑돌 ), 흑돌이 먼저 시작
int Winner_Checking(int Board[][20]);						// 승자를 체크하는 함수 (오목판의 주소를 인자로보내서 5개의 숫자를 체크)
int Check_6(int x, int y);

void Gotoxy(int x, int y);									// X,Y 좌표로 명령프롬포트를 보내는 함수  
void Game_Start();											// 게임을 시작하는 함수
void Draw_Omok_Board();										// 19 x 19 오목판을 그리는 함수
void Moving_Key(int Board[][20], char key, int* x, int* y);	// 키를 입력받아 움직이는 함수
void Erase_Stone(int x, int y);								// 커서를 옮기면 판을 다시 그리는 함수 
void Draw_Stone();											// 돌을 그리는 함수 (1이면 ○ , 2이면 ●)을 출력 (누적시켜서 게임을 진행)
void Put_Stone(int Board[][20], int x, int y);              // 0으로 초기화된 2차원 배열에 1또는 2의 값을 대입
void Draw_Put_Stone(int Board[][20]);						// 프롬포트가 있는 위치에 (1이면 ○ , 2이면 ●)을 출력
void Re_Game();												// 게임이 끝난 후, 게임을 다시 실행하는 함수

#define LEFT 75// ←의 ASCII코드 값: 75
#define RIGHT 77// →의 ASCII코드 값: 77
#define UP 72// ↑의 ASCII코드 값: 72
#define DOWN 80// ↓의 ASCII코드 값: 80
#define Spacebar 32// 스페이스바의 ASCII코드 값: 32
#define End 27// esc의 ASCII코드 값: 27

/************ 메인 함수 **************/
int main(void) {
	int end;
	PlaySound(TEXT("gung.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	end = Rule_Explain();
	if (end == 0)return 0; //Rule_Explain함수를 통해 반환되는 값은 0또는 1이다.
						   //Rule_Explain가 0이면 종료 1이면 system("cls")실행
	Game_Start();
	Gotoxy(20, 20);
	return 0;
}

/********** 오목의 룰을 설명 ************/

int Rule_Explain()
{
	
	int x = 30, y = 5;
	char press;
	Gotoxy(x, y);
	printf("*****  오목 룰 설명   *****\n");
	x = 20;
	y = 7;
	Gotoxy(x, y);
	printf("* 흑돌이 먼저 수를 두게 됩니다 *\n");
	y = 9;
	Gotoxy(x, y);
	printf("* 흑돌은 3x3, 4x4, 6목 이상의 수를 둘 수 없습니다 *\n");
	y = 11;
	Gotoxy(x, y);
	printf("* 돌이 5개 이상 연결되면 승리합니다 *\n");
	y = 13;
	Gotoxy(x, y);
	printf("* 게임을 시작하시려면 Space Bar를 눌러주세요 *\n");
	y = 15;
	Gotoxy(x, y);
	printf("* 게임을 종료하시려면 Esc를 눌러주세요 *\n");
	Gotoxy(20, 19);
	for (; 1;) {
		press = _getch();
		if (press == End) return 0; //아스키 코드 27 = esc
		if (press == Spacebar) {         //아스키 코드 32 = 스페이스바
			Gotoxy(x, y);
			system("cls");
			return 1; //for문 종료
		}
	}
}


/********* 게임 진행 함수 *********/

void Game_Start() {
	PlaySound(TEXT("bogum.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int x = 18, y = 9, i, j;
	char Key;                                    // 키가 입력되었을 때 그 ASCII 코드를 받을 변수
	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++) {
			Omok_Board[i][j] = 0;
		}
	Gotoxy(0, 0);
	Draw_Omok_Board();
	Gotoxy(x, y);
	Draw_Stone();
	do {                                            // do while문. 일단 한번 수행하고 조건에 맞으면 계속 루프
		Key = _getch();                              // 키 하나를 입력받아 그것의 ASCII 코드를 Key 변수에 저장
		Erase_Stone(x, y);
		Moving_Key(Omok_Board, Key, &x, &y);           // 키가 눌려졌을 때 처리하는 함수 호출
		Draw_Put_Stone(Omok_Board);                  // 놓여진 돌을 그리는 함수 호출
		if (Winner_Checking(Omok_Board))             // 승자를 체크하는 함수 호출
			
			return;
		Gotoxy(x, y);
		Draw_Stone();                                // 돌 출력 함수, 커서를 이동시켰으면 그다음은 돌 출력
	} while (Key != End);                            // Key값이 27이 아닐경우 계속함 27번은 ESC키
}
//--------------------------------------------

//---------돌 지우는 함수---------------------
void Erase_Stone(int x, int y) {                   // x,y의 좌표값을 매개변수로 전달
	Gotoxy(x, y);                                   // 현재 돌이 위치한 곳으로 이동 
	if (x == 0 && y == 0)                           // 그곳이 만약 0,0 (왼쪽 위 모서리)인 경우
		printf("┌");
	else if (x == 36 && y == 0)                     // 그곳이 만약 36,0 (오른쪽 위 모서리)인 경우
		printf("┐");
	else if (x == 0 && y == 18)                     // 그곳이 만약 0,18 (왼쪽 아래 모서리)인 경우
		printf("└");
	else if (x == 36 && y == 18)                    // 그곳이 만약 36,18 (오른쪽 아래 모서리)인 경우
		printf("┘");
	else if (x == 0)                                // 그곳이 만약 0,* (왼쪽줄)인 경우                 
		printf("├");
	else if (y == 0)                                // 그곳이 만약 *,0 (윗줄)인 경우
		printf("┬");
	else if (x == 36)                               // 그곳이 만약 36,* (오른쪽줄)인 경우
		printf("┤");
	else if (y == 18)                               // 그곳이 만약 *,18 (아랫줄)인 경우
		printf("┴");
	else                                           // 그 외의 경우
		printf("┼");
}

//-------------돌 그리는 함수--------------------
void Draw_Stone() {
	if (Color == 1) printf("●");
	else
		printf("○");
}
//-----------------------------------------------

//----------키가 눌렸을 때 처리하는 함수-------------
void Moving_Key(int Board[][20], char key, int* x, int* y) {
	int checking3x3, checking4x4;
	int checking6;
	int a, b;
	switch (key)
	{
	case UP:                  //UP과 DOWN을 할 때 조심해야한다!!!
		if (*y - 1 < 0)         //UP을 N번하면 Y의 위치는 N만큼 작아짐
			break;
		else
			*y -= 1;
		break;
	case DOWN:
		if (*y + 1 > 18)
			break;
		else
			*y += 1;
		break;
	case LEFT:
		if (*x - 2 < 0)
			break;
		else
			*x -= 2;
		break;
	case RIGHT:
		if (*x + 2 > 36)
			break;
		else
			*x += 2;
		break;

	case Spacebar: {
		a = *x;
		b = *y;
		checking3x3 = Check_3X3(a, b);
		checking4x4 = Check_4X4(a, b);
		checking6 = Check_6(a, b);

		if (Color == 1)
		{
			Put_Stone(Board, *x, *y);
			break;
		}
		else {
			Put_Stone(Board, *x, *y);
			if (checking3x3 != 1 && checking4x4 != 1 && checking6 != 1)
			{
				Gotoxy(50, 11);
				printf("-----------돌을 두세요------------");
				break;

			}

			if (checking3x3 == 1)
			{
				Gotoxy(50, 11);
				printf("3x3의 위치에는 착수할 수 없습니다!");
				key = _getch();
				Moving_Key(Omok_Board, key, &a, &b);
				Gotoxy(50, 11);
			}
			if (checking3x3 == 1)
			{
				Omok_Board[*y][*x / 2] = 0;
				Color = 2;
			}

			if (checking4x4 == 1)
			{
				Gotoxy(50, 11);
				printf("4x4의 위치에는 착수할 수 없습니다!");
				key = _getch();
				Moving_Key(Omok_Board, key, &a, &b);
			}

			if (checking4x4 == 1)
			{
				Omok_Board[*y][*x / 2] = 0;
				Color = 2;
			}
			if (checking6 == 1)
			{
				Gotoxy(50, 11);
				printf("흑색돌은 6목이상이 불가능합니다 :(");
				key = _getch();
				Moving_Key(Omok_Board, key, &a, &b);
			}
			if (checking6 == 1)
			{
				Omok_Board[*y][*x / 2] = 0;
				Color = 2;
			}
		}
	}
				 break;
	default:                                           //그 외의 경우, 처리 안함
		break;
	}
}
//-------------------------------------------------

//-----------------돌 놓는 함수--------------------
void Put_Stone(int Board[][20], int x, int y) {
	if (Board[y][x / 2] == 0) {
		if (Color == 1) {
			Board[y][x / 2] = 1;                        // Board[y][x/2] 에 1을 넣고  Color에 2를 대입  
			Color = 2;
		}
		else {									    // Board[y][x/2] 에 2을 넣고  Color에 1를 대입
			Board[y][x / 2] = 2;
			Color = 1;
		}
	}
}

void Draw_Put_Stone(int Board[][20]) {
	int i;
	int j;
	for (i = 0; i < 20; i++) {                        // 바둑판에 1 또는 2의 숫자가 있는지 확인
		for (j = 0; j < 20; j++) {
			if (Board[j][i] == 1) {
				Gotoxy(i * 2, j);                        // 커서를 i*2,j 에 보내서 ● 를 출력
				printf("●");
			}
			else if (Board[j][i] == 2) {
				Gotoxy(i * 2, j);                        // 커서를 i*2,j 에 보내서 ○ 를 출력
				printf("○");
			}
		}
	}
}
//----------------------------------------------------

//-------------승리 체크 함수-------------------------
int Winner_Checking(int Board[][20]) {
	int i;
	int j;
	int count = 0;
	char Over;
	for (i = 2; i < 18; i++) {
		for (j = 0; j < 20; j++) {
			if (Board[j][i - 2] == 1 && Board[j][i - 1] == 1 && Board[j][i] == 1 && Board[j][i + 1] == 1 && Board[j][i + 2] == 1) {
				PlaySound(TEXT("maple.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Gotoxy(50, 10);                                          // 2차 배열에 5개의 연속된 숫자가 있는지 확인 
				printf("*** ●님이 승리하셨습니다 ***");				 // 승자를 출력
				Gotoxy(50, 12);
				printf("*** 게임을 계속 하시겠습니까 ? [ Y / N ] ***");
				for (; 1;) {                                             // 게임 종료 후 이어서 게임을 진행할 수 있는 내용 출력
					Gotoxy(50, 14);
					Over = _getch();
					if (Over == 89 || Over == 121) {
						Color = 2;
						Re_Game();
					}
					if (Over == 78 || Over == 110) return 1;
				}
			}
			else if (Board[j][i - 2] == 2 && Board[j][i - 1] == 2 && Board[j][i] == 2 && Board[j][i + 1] == 2 && Board[j][i + 2] == 2)
			{
				PlaySound(TEXT("maple.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Gotoxy(50, 10);
				printf("*** ○님이 승리하셨습니다 ***");
				Gotoxy(50, 12);
				printf("*** 게임을 계속 하시겠습니까 ? [ Y / N ] ***");
				for (; 1;) {
					Gotoxy(50, 14);
					Over = _getch();
					if (Over == 89 || Over == 121) {
						Color = 2;
						Re_Game();
					}
					if (Over == 78 || Over == 110) return 1;
				}
			}
			else if (Board[i - 2][j] == 1 && Board[i - 1][j] == 1 && Board[i][j] == 1 && Board[i + 1][j] == 1 && Board[i + 2][j] == 1) {
				PlaySound(TEXT("maple.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Gotoxy(50, 10);
				printf("*** ●님이 승리하셨습니다 ***");
				Gotoxy(50, 12);
				printf("*** 게임을 계속 하시겠습니까 ? [ Y / N ] ***");
				for (; 1;) {
					Gotoxy(50, 14);
					Over = _getch();
					if (Over == 89 || Over == 121) {
						Color = 2;
						Re_Game();
					}
					if (Over == 78 || Over == 110) return 1;
				}
			}
			else if (Board[i - 2][j] == 2 && Board[i - 1][j] == 2 && Board[i][j] == 2 && Board[i + 1][j] == 2 && Board[i + 2][j] == 2) {
				PlaySound(TEXT("maple.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Gotoxy(50, 10);
				printf("*** ○님이 승리하셨습니다 ***");
				Gotoxy(50, 12);
				printf("*** 게임을 계속 하시겠습니까 ? [ Y / N ] ***");
				for (; 1;) {
					Gotoxy(50, 14);
					Over = _getch();
					if (Over == 89 || Over == 121) {
						Color = 2;
						Re_Game();
					}
					if (Over == 78 || Over == 110) return 1;
				}
			}
		}
	}
	for (i = 2; i < 18; i++) {
		for (j = 2; j < 18; j++) {
			if (Board[j - 2][i - 2] == 1 && Board[j - 1][i - 1] == 1 && Board[j][i] == 1 && Board[j + 1][i + 1] == 1 && Board[j + 2][i + 2] == 1) {
				PlaySound(TEXT("maple.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Gotoxy(50, 10);
				printf("*** ●님이 승리하셨습니다 ***");
				Gotoxy(50, 12);
				printf("*** 게임을 계속 하시겠습니까 ? [ Y / N ] ***");
				for (; 1;) {
					Gotoxy(50, 14);
					Over = _getch();
					if (Over == 89 || Over == 121) {
						Color = 2;
						Re_Game();
					}
					if (Over == 78 || Over == 110) return 1;
				}
			}
			else if (Board[j - 2][i - 2] == 2 && Board[j - 1][i - 1] == 2 && Board[j][i] == 2 && Board[j + 1][i + 1] == 2 && Board[j + 2][i + 2] == 2) {
				PlaySound(TEXT("maple.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Gotoxy(50, 10);
				printf("*** ○님이 승리하셨습니다 ***");
				Gotoxy(50, 12);
				printf("*** 게임을 계속 하시겠습니까 ? [ Y / N ] ***");
				for (; 1;) {
					Gotoxy(50, 14);
					Over = _getch();
					if (Over == 89 || Over == 121) {
						Color = 2;
						Re_Game();
					}
					if (Over == 78 || Over == 110) return 1;
				}
			}

			else if (Board[j + 2][i - 2] == 1 && Board[j + 1][i - 1] == 1 && Board[j][i] == 1 && Board[j - 1][i + 1] == 1 && Board[j - 2][i + 2] == 1) {
				PlaySound(TEXT("maple.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Gotoxy(50, 10);
				printf("*** ●님이 승리하셨습니다 ***");
				Gotoxy(50, 12);
				printf("*** 게임을 계속 하시겠습니까 ? [ Y / N ] ***");
				for (; 1;) {
					Gotoxy(50, 14);
					Over = _getch();
					if (Over == 89 || Over == 121) {
						Color = 2;
						Re_Game();
					}
					if (Over == 78 || Over == 110) return 1;
				}
			}
			else if (Board[j + 2][i - 2] == 2 && Board[j + 1][i - 1] == 2 && Board[j][i] == 2 && Board[j - 1][i + 1] == 2 && Board[j - 2][i + 2] == 2) {
				{
					PlaySound(TEXT("maple.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
					Gotoxy(50, 10);
					printf("*** ○님이 승리하셨습니다 ***");

					Gotoxy(50, 12);
					printf("*** 게임을 계속 하시겠습니까 ? [ Y / N ] ***");
					for (; 1;) {
						Gotoxy(50, 14);
						Over = _getch();
						if (Over == 89 || Over == 121) {
							Color = 2;
							Re_Game();
						}
						if (Over == 78 || Over == 110) return 1;
					}
				}
			}
		}
	}
	return 0;
}  //s
void Draw_Omok_Board()
{
	int i, j;
	printf("┌ ");
	for (i = 0; i < 17; i++) printf("┬ ");
	printf("┐\n");

	for (i = 0; i < 17; i++) {
		printf("├ ");
		for (j = 0; j < 17; j++)
			printf("┼ ");
		printf("┤\n");
	}
	printf("└ ");
	for (i = 0; i < 17; i++)printf("┴ ");
	printf("┘");
}
//----------------------------------------------------

//----------커서 이동함수-----------------------
void Gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
//------------------------------------------------
void Re_Game()
{
	system("cls");
	Game_Start();
}

int Check_3X3(int x, int y)
{
	int count = 0;
	// 가로체크. 
	if ((Omok_Board[y][x / 2 - 3] == 0 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 0) ||
		(Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 0) ||
		(Omok_Board[y][x / 2 - 1] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 3] == 0) ||
		(Omok_Board[y][x / 2 - 4] == 0 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 0 && Omok_Board[y][x / 2 + 1] == 0) ||
		(Omok_Board[y][x / 2 - 4] == 0 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 0) ||
		(Omok_Board[y][x / 2 + 4] == 0 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 0 && Omok_Board[y][x / 2 - 1] == 0) ||
		(Omok_Board[y][x / 2 + 4] == 0 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] == 0) ||
		(Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 0 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 3] == 0) ||
		(Omok_Board[y][x / 2 + 2] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] == 0 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 3] == 0))
		count++;
	// 세로체크. 
	if ((Omok_Board[y - 3][x / 2] == 0 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0) ||
		(Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0) ||
		(Omok_Board[y - 1][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 0) ||
		(Omok_Board[y - 4][x / 2] == 0 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 0) ||
		(Omok_Board[y - 4][x / 2] == 0 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0) ||
		(Omok_Board[y + 4][x / 2] == 0 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 0) ||
		(Omok_Board[y + 4][x / 2] == 0 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0) ||
		(Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 0) ||
		(Omok_Board[y + 2][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 0))
		count++;
	// 대각선체크. 
	if ((Omok_Board[y - 3][x / 2 - 3] == 0 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0) ||
		(Omok_Board[y - 2][x / 2 - 2] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0) ||
		(Omok_Board[y - 1][x / 2 - 1] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 3][x / 2 + 3] == 0) ||
		(Omok_Board[y - 3][x / 2 - 3] == 0 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0) ||
		(Omok_Board[y + 3][x / 2 + 3] == 0 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0) ||
		(Omok_Board[y - 4][x / 2 - 4] == 0 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0 && Omok_Board[y + 1][x / 2 + 1] == 0) ||
		(Omok_Board[y - 4][x / 2 - 4] == 0 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0) ||
		(Omok_Board[y + 4][x / 2 + 4] == 0 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0) ||
		(Omok_Board[y + 4][x / 2 + 4] == 0 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0 && Omok_Board[y - 1][x / 2 - 1] == 0))
		count++;
	// 반대 대각선체크. 
	if ((Omok_Board[y - 3][x / 2 + 3] == 0 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0) ||
		(Omok_Board[y - 2][x / 2 + 2] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0) ||
		(Omok_Board[y - 1][x / 2 + 1] == 0 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 3][x / 2 - 3] == 0) ||
		(Omok_Board[y - 3][x / 2 + 3] == 0 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0) ||
		(Omok_Board[y + 3][x / 2 - 3] == 0 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0) ||
		(Omok_Board[y - 4][x / 2 + 4] == 0 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0 && Omok_Board[y + 1][x / 2 - 1] == 0) ||
		(Omok_Board[y - 4][x / 2 + 4] == 0 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0) ||
		(Omok_Board[y + 4][x / 2 - 4] == 0 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0 && Omok_Board[y - 1][x / 2 + 1] == 0) ||
		(Omok_Board[y + 4][x / 2 - 4] == 0 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0))
		count++;
	if (count > 1) return 1;
	else return 0;
}

int Check_4X4(int x, int y)
{
	int count = 0;
	// 가로체크. 
	if ((Omok_Board[y][x / 2 - 4] != 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 0) ||
		(Omok_Board[y][x / 2 + 4] != 2 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] == 0) ||
		(Omok_Board[y][x / 2 - 5] != 2 && Omok_Board[y][x / 2 - 4] == 2 && Omok_Board[y][x / 2 - 3] == 0 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 0) ||
		(Omok_Board[y][x / 2 + 5] != 2 && Omok_Board[y][x / 2 + 4] == 2 && Omok_Board[y][x / 2 + 3] == 0 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] == 0) ||
		(Omok_Board[y][x / 2 - 5] != 2 && Omok_Board[y][x / 2 - 4] == 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 0) ||
		(Omok_Board[y][x / 2 + 5] != 2 && Omok_Board[y][x / 2 + 4] == 2 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] == 0) ||
		(Omok_Board[y][x / 2 - 5] != 2 && Omok_Board[y][x / 2 - 4] == 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 0 && Omok_Board[y][x / 2 + 1] == 0) ||
		(Omok_Board[y][x / 2 + 5] != 2 && Omok_Board[y][x / 2 + 4] == 2 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 0 && Omok_Board[y][x / 2 - 1] == 0) ||
		(Omok_Board[y][x / 2 - 3] != 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 0) ||
		(Omok_Board[y][x / 2 + 3] != 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 - 2] == 0) ||
		(Omok_Board[y][x / 2 - 4] != 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 0) ||
		(Omok_Board[y][x / 2 + 4] != 2 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 - 2] == 0) ||
		(Omok_Board[y][x / 2 - 4] != 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 0) ||
		(Omok_Board[y][x / 2 + 4] != 2 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 - 2] == 0) ||

		(Omok_Board[y][x / 2 - 4] == 0 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] != 2) ||
		(Omok_Board[y][x / 2 + 4] == 0 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] != 2) ||
		(Omok_Board[y][x / 2 - 5] == 0 && Omok_Board[y][x / 2 - 4] == 2 && Omok_Board[y][x / 2 - 3] == 0 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] != 2) ||
		(Omok_Board[y][x / 2 + 5] == 0 && Omok_Board[y][x / 2 + 4] == 2 && Omok_Board[y][x / 2 + 3] == 0 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] != 2) ||
		(Omok_Board[y][x / 2 - 5] == 0 && Omok_Board[y][x / 2 - 4] == 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] != 2) ||
		(Omok_Board[y][x / 2 + 5] == 0 && Omok_Board[y][x / 2 + 4] == 2 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] != 2) ||
		(Omok_Board[y][x / 2 - 5] == 0 && Omok_Board[y][x / 2 - 4] == 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 0 && Omok_Board[y][x / 2 + 1] != 2) ||
		(Omok_Board[y][x / 2 + 5] == 0 && Omok_Board[y][x / 2 + 4] == 2 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 0 && Omok_Board[y][x / 2 - 1] != 2) ||
		(Omok_Board[y][x / 2 - 3] == 0 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] != 2) ||
		(Omok_Board[y][x / 2 + 3] == 0 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 - 2] != 2) ||
		(Omok_Board[y][x / 2 - 4] == 0 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] != 2) ||
		(Omok_Board[y][x / 2 + 4] == 0 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 1] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 - 2] != 2) ||
		(Omok_Board[y][x / 2 - 4] == 0 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] != 2) ||
		(Omok_Board[y][x / 2 + 4] == 0 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 2] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 - 2] != 2))


		count++;

	// 세로체크. 
	if ((Omok_Board[y - 4][x / 2] != 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0) ||
		(Omok_Board[y + 4][x / 2] != 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0) ||
		(Omok_Board[y - 5][x / 2] != 2 && Omok_Board[y - 4][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 0 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0) ||
		(Omok_Board[y + 5][x / 2] != 2 && Omok_Board[y + 4][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 0 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0) ||
		(Omok_Board[y - 5][x / 2] != 2 && Omok_Board[y - 4][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0) ||
		(Omok_Board[y + 5][x / 2] != 2 && Omok_Board[y + 4][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0) ||
		(Omok_Board[y - 5][x / 2] != 2 && Omok_Board[y - 4][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 0) ||
		(Omok_Board[y + 5][x / 2] != 2 && Omok_Board[y + 4][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 0) ||
		(Omok_Board[y - 3][x / 2] != 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0) ||
		(Omok_Board[y + 3][x / 2] != 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0) ||
		(Omok_Board[y - 4][x / 2] != 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0) ||
		(Omok_Board[y + 4][x / 2] != 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0) ||
		(Omok_Board[y - 4][x / 2] != 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0) ||
		(Omok_Board[y + 4][x / 2] != 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0) ||

		(Omok_Board[y - 4][x / 2] != 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] != 2) ||
		(Omok_Board[y + 4][x / 2] != 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] != 2) ||
		(Omok_Board[y - 5][x / 2] != 2 && Omok_Board[y - 4][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 0 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] != 2) ||
		(Omok_Board[y + 5][x / 2] != 2 && Omok_Board[y + 4][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 0 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] != 2) ||
		(Omok_Board[y - 5][x / 2] != 2 && Omok_Board[y - 4][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] != 2) ||
		(Omok_Board[y + 5][x / 2] != 2 && Omok_Board[y + 4][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] != 2) ||
		(Omok_Board[y - 5][x / 2] != 2 && Omok_Board[y - 4][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0 && Omok_Board[y + 1][x / 2] != 2) ||
		(Omok_Board[y + 5][x / 2] != 2 && Omok_Board[y + 4][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0 && Omok_Board[y - 1][x / 2] != 2) ||
		(Omok_Board[y - 3][x / 2] != 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] != 2) ||
		(Omok_Board[y + 3][x / 2] != 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y - 2][x / 2] != 2) ||
		(Omok_Board[y - 4][x / 2] != 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] != 2) ||
		(Omok_Board[y + 4][x / 2] != 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y - 2][x / 2] != 2) ||
		(Omok_Board[y - 4][x / 2] != 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] != 2) ||
		(Omok_Board[y + 4][x / 2] != 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y - 2][x / 2] != 2))

		count++;
	// 대각선
	if ((Omok_Board[y - 4][x / 2 - 4] != 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0) ||
		(Omok_Board[y + 4][x / 2 + 4] != 2 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0) ||
		(Omok_Board[y - 5][x / 2 - 5] != 2 && Omok_Board[y - 4][x / 2 - 4] == 2 && Omok_Board[y - 3][x / 2 - 3] == 0 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0) ||
		(Omok_Board[y + 5][x / 2 + 5] != 2 && Omok_Board[y + 4][x / 2 + 4] == 2 && Omok_Board[y + 3][x / 2 + 3] == 0 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0) ||
		(Omok_Board[y - 5][x / 2 - 5] != 2 && Omok_Board[y - 4][x / 2 - 4] == 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0) ||
		(Omok_Board[y + 5][x / 2 + 5] != 2 && Omok_Board[y + 4][x / 2 + 4] == 2 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0) ||
		(Omok_Board[y - 5][x / 2 - 5] != 2 && Omok_Board[y - 4][x / 2 - 4] == 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0 && Omok_Board[y + 1][x / 2 + 1] == 0) ||
		(Omok_Board[y + 5][x / 2 + 5] != 2 && Omok_Board[y + 4][x / 2 + 4] == 2 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0 && Omok_Board[y - 1][x / 2 - 1] == 0) ||
		(Omok_Board[y - 3][x / 2 - 3] != 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0) ||
		(Omok_Board[y + 3][x / 2 + 3] != 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0) ||
		(Omok_Board[y - 4][x / 2 - 4] != 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0) ||
		(Omok_Board[y + 4][x / 2 + 4] != 2 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0) ||
		(Omok_Board[y - 4][x / 2 - 4] != 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0) ||
		(Omok_Board[y + 4][x / 2 + 4] != 2 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0) ||

		(Omok_Board[y - 4][x / 2 - 4] == 0 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] != 2) ||
		(Omok_Board[y + 4][x / 2 + 4] == 0 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] != 2) ||
		(Omok_Board[y - 5][x / 2 - 5] == 0 && Omok_Board[y - 4][x / 2 - 4] == 2 && Omok_Board[y - 3][x / 2 - 3] == 0 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] != 2) ||
		(Omok_Board[y + 5][x / 2 + 5] == 0 && Omok_Board[y + 4][x / 2 + 4] == 2 && Omok_Board[y + 3][x / 2 + 3] == 0 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] != 2) ||
		(Omok_Board[y - 5][x / 2 - 5] == 0 && Omok_Board[y - 4][x / 2 - 4] == 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] != 2) ||
		(Omok_Board[y + 5][x / 2 + 5] == 0 && Omok_Board[y + 4][x / 2 + 4] == 2 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] != 2) ||
		(Omok_Board[y - 5][x / 2 - 5] == 0 && Omok_Board[y - 4][x / 2 - 4] == 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0 && Omok_Board[y + 1][x / 2 + 1] != 2) ||
		(Omok_Board[y + 5][x / 2 + 5] == 0 && Omok_Board[y + 4][x / 2 + 4] == 2 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0 && Omok_Board[y - 1][x / 2 - 1] != 2) ||
		(Omok_Board[y - 3][x / 2 - 3] == 0 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] != 2) ||
		(Omok_Board[y + 3][x / 2 + 3] == 0 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y - 2][x / 2 - 2] != 2) ||
		(Omok_Board[y - 4][x / 2 - 4] == 0 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] != 2) ||
		(Omok_Board[y + 4][x / 2 + 4] == 0 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y - 2][x / 2 - 2] != 2) ||
		(Omok_Board[y - 4][x / 2 - 4] == 0 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] != 2) ||
		(Omok_Board[y + 4][x / 2 + 4] == 0 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y - 2][x / 2 - 2] != 2))

		count++;
	// 반대 대각선체크
	if ((Omok_Board[y - 4][x / 2 + 4] != 2 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0) ||
		(Omok_Board[y + 4][x / 2 - 4] != 2 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0) ||
		(Omok_Board[y - 5][x / 2 + 5] != 2 && Omok_Board[y - 4][x / 2 + 4] == 2 && Omok_Board[y - 3][x / 2 + 3] == 0 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0) ||
		(Omok_Board[y + 5][x / 2 - 5] != 2 && Omok_Board[y + 4][x / 2 - 4] == 2 && Omok_Board[y + 3][x / 2 - 3] == 0 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0) ||
		(Omok_Board[y - 5][x / 2 + 5] != 2 && Omok_Board[y - 4][x / 2 + 4] == 2 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0) ||
		(Omok_Board[y + 5][x / 2 - 5] != 2 && Omok_Board[y + 4][x / 2 - 4] == 2 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0) ||
		(Omok_Board[y - 5][x / 2 - 5] != 2 && Omok_Board[y - 4][x / 2 + 4] == 2 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0 && Omok_Board[y + 1][x / 2 - 1] == 0) ||
		(Omok_Board[y + 5][x / 2 + 5] != 2 && Omok_Board[y + 4][x / 2 - 4] == 2 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0 && Omok_Board[y - 1][x / 2 + 1] == 0) ||
		(Omok_Board[y - 3][x / 2 + 3] != 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0) ||
		(Omok_Board[y + 3][x / 2 - 3] != 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0) ||
		(Omok_Board[y - 4][x / 2 + 4] != 2 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0) ||
		(Omok_Board[y + 4][x / 2 - 4] != 2 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0) ||
		(Omok_Board[y - 4][x / 2 + 4] != 2 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0) ||
		(Omok_Board[y + 4][x / 2 - 4] != 2 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0) ||

		(Omok_Board[y - 4][x / 2 + 4] == 0 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] != 2) ||
		(Omok_Board[y + 4][x / 2 - 4] == 0 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] != 2) ||
		(Omok_Board[y - 5][x / 2 + 5] == 0 && Omok_Board[y - 4][x / 2 + 4] == 2 && Omok_Board[y - 3][x / 2 + 3] == 0 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] != 2) ||
		(Omok_Board[y + 5][x / 2 - 5] == 0 && Omok_Board[y + 4][x / 2 - 4] == 2 && Omok_Board[y + 3][x / 2 - 3] == 0 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] != 2) ||
		(Omok_Board[y - 5][x / 2 + 5] == 0 && Omok_Board[y - 4][x / 2 + 4] == 2 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] != 2) ||
		(Omok_Board[y + 5][x / 2 - 5] == 0 && Omok_Board[y + 4][x / 2 - 4] == 2 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] != 2) ||
		(Omok_Board[y - 5][x / 2 - 5] == 0 && Omok_Board[y - 4][x / 2 + 4] == 2 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0 && Omok_Board[y + 1][x / 2 - 1] != 2) ||
		(Omok_Board[y + 5][x / 2 + 5] == 0 && Omok_Board[y + 4][x / 2 - 4] == 2 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0 && Omok_Board[y - 1][x / 2 + 1] != 2) ||
		(Omok_Board[y - 3][x / 2 + 3] == 0 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] != 2) ||
		(Omok_Board[y + 3][x / 2 - 3] == 0 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y - 2][x / 2 + 2] != 2) ||
		(Omok_Board[y - 4][x / 2 + 4] == 0 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 0 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] != 2) ||
		(Omok_Board[y + 4][x / 2 - 4] == 0 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 1][x / 2 - 1] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y - 2][x / 2 + 2] != 2) ||
		(Omok_Board[y - 4][x / 2 + 4] == 0 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] != 2) ||
		(Omok_Board[y + 4][x / 2 - 4] == 0 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y - 2][x / 2 + 2] != 2))
		count++;

	//가로끼리 44, 세로끼리 44
	if ((Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 0 && Omok_Board[y][x / 2 + 3] == 2) ||
		(Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 3][x / 2] == 2) ||
		(Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0 && Omok_Board[y - 3][x / 2 - 3] == 2) ||
		(Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0 && Omok_Board[y + 3][x / 2 - 3] == 2)
		)
		count += 2;
	//2 2 2 (4목)
	if ((Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 0 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 0 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 4] == 2) ||
		(Omok_Board[y][x / 2 - 4] == 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 0 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 3] == 2) ||
		(Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 4][x / 2] == 2) ||
		(Omok_Board[y - 4][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 0 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 2) ||
		(Omok_Board[y - 4][x / 2 - 4] == 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 0 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 3][x / 2 + 3] == 2) ||
		(Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 4][x / 2 + 4] == 2)
		)
		count += 2;

	if (count > 1) return 1;
	else return 0;
}

int Check_6(int x, int y)
{
	int count = 0;

	// 가로체크.
	if ((Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 4] == 2) ||
		(Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 3] == 2) ||
		(Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 2) ||
		(Omok_Board[y][x / 2 - 4] == 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2)
		)
		count++;

	// 세로체크.
	if ((Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 4][x / 2] == 2) ||
		(Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 2) ||
		(Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2) ||
		(Omok_Board[y - 4][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2)
		)
		count++;

	//대각선 체크
	if ((Omok_Board[y - 4][x / 2 - 4] == 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2) ||
		(Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2) ||
		(Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 3][x / 2 + 3] == 2) ||
		(Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 4][x / 2 + 4] == 2)
		)
		count++;

	// 반대 대각선체크. 
	if ((Omok_Board[y - 4][x / 2 + 4] == 2 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2) ||
		(Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2) ||
		(Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 3][x / 2 - 3] == 2) ||
		(Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 4][x / 2 - 4] == 2)
		)
		count++;

	if (count > 0) return 1;
	else return 0;
}
