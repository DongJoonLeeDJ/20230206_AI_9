#include <stdio.h>                                 
#include <Windows.h>                             
#include <conio.h>             
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


int Rule_Explain();											// ������ ���� �����ϴ� �Լ�
int Check_3X3(int x, int y);
int Check_4X4(int x, int y);									// ���� ������Ģ (3 x 3)�� üũ�ϴ� �Լ�
int Omok_Board[20][20] = { 0,0 };								// ���� ������ �������� �ʱ�ȭ�ϴ� �������� 
int Color = 2;												// ���� ���� ������ ���ϴ� �������� ( 1 == �鵹 , 2 == �浹 ), �浹�� ���� ����
int Winner_Checking(int Board[][20]);						// ���ڸ� üũ�ϴ� �Լ� (�������� �ּҸ� ���ڷκ����� 5���� ���ڸ� üũ)
int Check_6(int x, int y);

void Gotoxy(int x, int y);									// X,Y ��ǥ�� ���������Ʈ�� ������ �Լ�  
void Game_Start();											// ������ �����ϴ� �Լ�
void Draw_Omok_Board();										// 19 x 19 �������� �׸��� �Լ�
void Moving_Key(int Board[][20], char key, int* x, int* y);	// Ű�� �Է¹޾� �����̴� �Լ�
void Erase_Stone(int x, int y);								// Ŀ���� �ű�� ���� �ٽ� �׸��� �Լ� 
void Draw_Stone();											// ���� �׸��� �Լ� (1�̸� �� , 2�̸� ��)�� ��� (�������Ѽ� ������ ����)
void Put_Stone(int Board[][20], int x, int y);              // 0���� �ʱ�ȭ�� 2���� �迭�� 1�Ǵ� 2�� ���� ����
void Draw_Put_Stone(int Board[][20]);						// ������Ʈ�� �ִ� ��ġ�� (1�̸� �� , 2�̸� ��)�� ���
void Re_Game();												// ������ ���� ��, ������ �ٽ� �����ϴ� �Լ�

#define LEFT 75// ���� ASCII�ڵ� ��: 75
#define RIGHT 77// ���� ASCII�ڵ� ��: 77
#define UP 72// ���� ASCII�ڵ� ��: 72
#define DOWN 80// ���� ASCII�ڵ� ��: 80
#define Spacebar 32// �����̽����� ASCII�ڵ� ��: 32
#define End 27// esc�� ASCII�ڵ� ��: 27

/************ ���� �Լ� **************/
int main(void) {
	int end;
	PlaySound(TEXT("gung.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	end = Rule_Explain();
	if (end == 0)return 0; //Rule_Explain�Լ��� ���� ��ȯ�Ǵ� ���� 0�Ǵ� 1�̴�.
						   //Rule_Explain�� 0�̸� ���� 1�̸� system("cls")����
	Game_Start();
	Gotoxy(20, 20);
	return 0;
}

/********** ������ ���� ���� ************/

int Rule_Explain()
{
	
	int x = 30, y = 5;
	char press;
	Gotoxy(x, y);
	printf("*****  ���� �� ����   *****\n");
	x = 20;
	y = 7;
	Gotoxy(x, y);
	printf("* �浹�� ���� ���� �ΰ� �˴ϴ� *\n");
	y = 9;
	Gotoxy(x, y);
	printf("* �浹�� 3x3, 4x4, 6�� �̻��� ���� �� �� �����ϴ� *\n");
	y = 11;
	Gotoxy(x, y);
	printf("* ���� 5�� �̻� ����Ǹ� �¸��մϴ� *\n");
	y = 13;
	Gotoxy(x, y);
	printf("* ������ �����Ͻ÷��� Space Bar�� �����ּ��� *\n");
	y = 15;
	Gotoxy(x, y);
	printf("* ������ �����Ͻ÷��� Esc�� �����ּ��� *\n");
	Gotoxy(20, 19);
	for (; 1;) {
		press = _getch();
		if (press == End) return 0; //�ƽ�Ű �ڵ� 27 = esc
		if (press == Spacebar) {         //�ƽ�Ű �ڵ� 32 = �����̽���
			Gotoxy(x, y);
			system("cls");
			return 1; //for�� ����
		}
	}
}


/********* ���� ���� �Լ� *********/

void Game_Start() {
	PlaySound(TEXT("bogum.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int x = 18, y = 9, i, j;
	char Key;                                    // Ű�� �ԷµǾ��� �� �� ASCII �ڵ带 ���� ����
	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++) {
			Omok_Board[i][j] = 0;
		}
	Gotoxy(0, 0);
	Draw_Omok_Board();
	Gotoxy(x, y);
	Draw_Stone();
	do {                                            // do while��. �ϴ� �ѹ� �����ϰ� ���ǿ� ������ ��� ����
		Key = _getch();                              // Ű �ϳ��� �Է¹޾� �װ��� ASCII �ڵ带 Key ������ ����
		Erase_Stone(x, y);
		Moving_Key(Omok_Board, Key, &x, &y);           // Ű�� �������� �� ó���ϴ� �Լ� ȣ��
		Draw_Put_Stone(Omok_Board);                  // ������ ���� �׸��� �Լ� ȣ��
		if (Winner_Checking(Omok_Board))             // ���ڸ� üũ�ϴ� �Լ� ȣ��
			
			return;
		Gotoxy(x, y);
		Draw_Stone();                                // �� ��� �Լ�, Ŀ���� �̵��������� �״����� �� ���
	} while (Key != End);                            // Key���� 27�� �ƴҰ�� ����� 27���� ESCŰ
}
//--------------------------------------------

//---------�� ����� �Լ�---------------------
void Erase_Stone(int x, int y) {                   // x,y�� ��ǥ���� �Ű������� ����
	Gotoxy(x, y);                                   // ���� ���� ��ġ�� ������ �̵� 
	if (x == 0 && y == 0)                           // �װ��� ���� 0,0 (���� �� �𼭸�)�� ���
		printf("��");
	else if (x == 36 && y == 0)                     // �װ��� ���� 36,0 (������ �� �𼭸�)�� ���
		printf("��");
	else if (x == 0 && y == 18)                     // �װ��� ���� 0,18 (���� �Ʒ� �𼭸�)�� ���
		printf("��");
	else if (x == 36 && y == 18)                    // �װ��� ���� 36,18 (������ �Ʒ� �𼭸�)�� ���
		printf("��");
	else if (x == 0)                                // �װ��� ���� 0,* (������)�� ���                 
		printf("��");
	else if (y == 0)                                // �װ��� ���� *,0 (����)�� ���
		printf("��");
	else if (x == 36)                               // �װ��� ���� 36,* (��������)�� ���
		printf("��");
	else if (y == 18)                               // �װ��� ���� *,18 (�Ʒ���)�� ���
		printf("��");
	else                                           // �� ���� ���
		printf("��");
}

//-------------�� �׸��� �Լ�--------------------
void Draw_Stone() {
	if (Color == 1) printf("��");
	else
		printf("��");
}
//-----------------------------------------------

//----------Ű�� ������ �� ó���ϴ� �Լ�-------------
void Moving_Key(int Board[][20], char key, int* x, int* y) {
	int checking3x3, checking4x4;
	int checking6;
	int a, b;
	switch (key)
	{
	case UP:                  //UP�� DOWN�� �� �� �����ؾ��Ѵ�!!!
		if (*y - 1 < 0)         //UP�� N���ϸ� Y�� ��ġ�� N��ŭ �۾���
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
				printf("-----------���� �μ���------------");
				break;

			}

			if (checking3x3 == 1)
			{
				Gotoxy(50, 11);
				printf("3x3�� ��ġ���� ������ �� �����ϴ�!");
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
				printf("4x4�� ��ġ���� ������ �� �����ϴ�!");
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
				printf("������� 6���̻��� �Ұ����մϴ� :(");
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
	default:                                           //�� ���� ���, ó�� ����
		break;
	}
}
//-------------------------------------------------

//-----------------�� ���� �Լ�--------------------
void Put_Stone(int Board[][20], int x, int y) {
	if (Board[y][x / 2] == 0) {
		if (Color == 1) {
			Board[y][x / 2] = 1;                        // Board[y][x/2] �� 1�� �ְ�  Color�� 2�� ����  
			Color = 2;
		}
		else {									    // Board[y][x/2] �� 2�� �ְ�  Color�� 1�� ����
			Board[y][x / 2] = 2;
			Color = 1;
		}
	}
}

void Draw_Put_Stone(int Board[][20]) {
	int i;
	int j;
	for (i = 0; i < 20; i++) {                        // �ٵ��ǿ� 1 �Ǵ� 2�� ���ڰ� �ִ��� Ȯ��
		for (j = 0; j < 20; j++) {
			if (Board[j][i] == 1) {
				Gotoxy(i * 2, j);                        // Ŀ���� i*2,j �� ������ �� �� ���
				printf("��");
			}
			else if (Board[j][i] == 2) {
				Gotoxy(i * 2, j);                        // Ŀ���� i*2,j �� ������ �� �� ���
				printf("��");
			}
		}
	}
}
//----------------------------------------------------

//-------------�¸� üũ �Լ�-------------------------
int Winner_Checking(int Board[][20]) {
	int i;
	int j;
	int count = 0;
	char Over;
	for (i = 2; i < 18; i++) {
		for (j = 0; j < 20; j++) {
			if (Board[j][i - 2] == 1 && Board[j][i - 1] == 1 && Board[j][i] == 1 && Board[j][i + 1] == 1 && Board[j][i + 2] == 1) {
				PlaySound(TEXT("maple.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Gotoxy(50, 10);                                          // 2�� �迭�� 5���� ���ӵ� ���ڰ� �ִ��� Ȯ�� 
				printf("*** �ܴ��� �¸��ϼ̽��ϴ� ***");				 // ���ڸ� ���
				Gotoxy(50, 12);
				printf("*** ������ ��� �Ͻðڽ��ϱ� ? [ Y / N ] ***");
				for (; 1;) {                                             // ���� ���� �� �̾ ������ ������ �� �ִ� ���� ���
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
				printf("*** �۴��� �¸��ϼ̽��ϴ� ***");
				Gotoxy(50, 12);
				printf("*** ������ ��� �Ͻðڽ��ϱ� ? [ Y / N ] ***");
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
				printf("*** �ܴ��� �¸��ϼ̽��ϴ� ***");
				Gotoxy(50, 12);
				printf("*** ������ ��� �Ͻðڽ��ϱ� ? [ Y / N ] ***");
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
				printf("*** �۴��� �¸��ϼ̽��ϴ� ***");
				Gotoxy(50, 12);
				printf("*** ������ ��� �Ͻðڽ��ϱ� ? [ Y / N ] ***");
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
				printf("*** �ܴ��� �¸��ϼ̽��ϴ� ***");
				Gotoxy(50, 12);
				printf("*** ������ ��� �Ͻðڽ��ϱ� ? [ Y / N ] ***");
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
				printf("*** �۴��� �¸��ϼ̽��ϴ� ***");
				Gotoxy(50, 12);
				printf("*** ������ ��� �Ͻðڽ��ϱ� ? [ Y / N ] ***");
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
				printf("*** �ܴ��� �¸��ϼ̽��ϴ� ***");
				Gotoxy(50, 12);
				printf("*** ������ ��� �Ͻðڽ��ϱ� ? [ Y / N ] ***");
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
					printf("*** �۴��� �¸��ϼ̽��ϴ� ***");

					Gotoxy(50, 12);
					printf("*** ������ ��� �Ͻðڽ��ϱ� ? [ Y / N ] ***");
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
	printf("�� ");
	for (i = 0; i < 17; i++) printf("�� ");
	printf("��\n");

	for (i = 0; i < 17; i++) {
		printf("�� ");
		for (j = 0; j < 17; j++)
			printf("�� ");
		printf("��\n");
	}
	printf("�� ");
	for (i = 0; i < 17; i++)printf("�� ");
	printf("��");
}
//----------------------------------------------------

//----------Ŀ�� �̵��Լ�-----------------------
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
	// ����üũ. 
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
	// ����üũ. 
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
	// �밢��üũ. 
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
	// �ݴ� �밢��üũ. 
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
	// ����üũ. 
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

	// ����üũ. 
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
	// �밢��
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
	// �ݴ� �밢��üũ
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

	//���γ��� 44, ���γ��� 44
	if ((Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 0 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 0 && Omok_Board[y][x / 2 + 3] == 2) ||
		(Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 0 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 0 && Omok_Board[y - 3][x / 2] == 2) ||
		(Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 2][x / 2 + 2] == 0 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y - 2][x / 2 - 2] == 0 && Omok_Board[y - 3][x / 2 - 3] == 2) ||
		(Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 0 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 0 && Omok_Board[y + 3][x / 2 - 3] == 2)
		)
		count += 2;
	//2 2 2 (4��)
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

	// ����üũ.
	if ((Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 3] == 2 && Omok_Board[y][x / 2 + 4] == 2) ||
		(Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 2 && Omok_Board[y][x / 2 + 3] == 2) ||
		(Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2 && Omok_Board[y][x / 2 + 2] == 2) ||
		(Omok_Board[y][x / 2 - 4] == 2 && Omok_Board[y][x / 2 - 3] == 2 && Omok_Board[y][x / 2 - 2] == 2 && Omok_Board[y][x / 2 - 1] == 2 && Omok_Board[y][x / 2 + 1] == 2)
		)
		count++;

	// ����üũ.
	if ((Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 2 && Omok_Board[y + 4][x / 2] == 2) ||
		(Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2 && Omok_Board[y + 3][x / 2] == 2) ||
		(Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2 && Omok_Board[y + 2][x / 2] == 2) ||
		(Omok_Board[y - 4][x / 2] == 2 && Omok_Board[y - 3][x / 2] == 2 && Omok_Board[y - 2][x / 2] == 2 && Omok_Board[y - 1][x / 2] == 2 && Omok_Board[y + 1][x / 2] == 2)
		)
		count++;

	//�밢�� üũ
	if ((Omok_Board[y - 4][x / 2 - 4] == 2 && Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2) ||
		(Omok_Board[y - 3][x / 2 - 3] == 2 && Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2) ||
		(Omok_Board[y - 2][x / 2 - 2] == 2 && Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 3][x / 2 + 3] == 2) ||
		(Omok_Board[y - 1][x / 2 - 1] == 2 && Omok_Board[y + 1][x / 2 + 1] == 2 && Omok_Board[y + 2][x / 2 + 2] == 2 && Omok_Board[y + 3][x / 2 + 3] == 2 && Omok_Board[y + 4][x / 2 + 4] == 2)
		)
		count++;

	// �ݴ� �밢��üũ. 
	if ((Omok_Board[y - 4][x / 2 + 4] == 2 && Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2) ||
		(Omok_Board[y - 3][x / 2 + 3] == 2 && Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2) ||
		(Omok_Board[y - 2][x / 2 + 2] == 2 && Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 3][x / 2 - 3] == 2) ||
		(Omok_Board[y - 1][x / 2 + 1] == 2 && Omok_Board[y + 1][x / 2 - 1] == 2 && Omok_Board[y + 2][x / 2 - 2] == 2 && Omok_Board[y + 3][x / 2 - 3] == 2 && Omok_Board[y + 4][x / 2 - 4] == 2)
		)
		count++;

	if (count > 0) return 1;
	else return 0;
}
