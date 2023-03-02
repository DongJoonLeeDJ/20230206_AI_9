#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define HOLEMAN_BOTTOM_Y 12
#define TREE_BOTTOM_Y 23
#define TREE_BOTTOM_X 45
#define ESC 27
boolean isJumping = 0;
boolean isBottom = 1;
int a = 1;
int stage = 1;


void SetConsoleView()
{
	system("mode con:cols=100 lines=40");
	system("title Hole man");
}

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void GetKeyDown()
{
	if (_kbhit() != 0)
	{
		int nkey;
		nkey = _getch();
		if (nkey == 'z' && isBottom)
		{
			isJumping = 1;
			isBottom = 0;
		}
		else if (nkey == ESC)
		{
			system("cls");
			exit(0);
		}
	}

}

void DrawHoleman(int holemanY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	GotoXY(0, holemanY);
	static boolean legFlag = 1;
	printf("          ■■■■■■\n");
	printf("        ■■□□□□■■\n");
	printf("      ■■□□□□□□■■\n");
	printf("    ■■□□□□□□□□■■\n");
	printf("    ■■□□□□□□□□■■\n");
	printf("    ■■□□□□□□□□■■\n");
	printf("      ■■□□□□□□■■\n");
	printf("        ■■□□□□■■\n");
	printf("         ■■■■■■■\n");
	printf("        ■■■■■■■■\n");
	printf("       ■■■■■■■■■\n");
	printf("      ■ ■■■■■■■ ■  \n");
	printf("     ■  ■■■■■■■  ■\n");

	if (legFlag)
	{
		printf("         ■■      ■■\n");
		printf("         ■■      ■■■\n");
		printf("         ■■■          \n");
		legFlag = 0;
	}
	else
	{
		printf("         ■■      ■■\n");
		printf("         ■■■    ■■\n");
		printf("                   ■■■\n");
		legFlag = 1;
	}
}

void JumpDraw(int holemanY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	GotoXY(0, holemanY);
	static int Frame1 = 1;

	if (Frame1 == 1)
	{
		printf("          ■■■■■■\n");
		printf("        ■■□□□□■■\n");
		printf("      ■■□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("      ■■□□□□□□■■\n");
		printf("        ■■□□□□■■\n");
		printf("         ■■■■■■■\n");
		printf("        ■■■■■■■■\n");
		printf("       ■■■■■■■■■\n");
		printf("      ■ ■■■■■■■ ■  \n");
		printf("     ■  ■■■■■■■  ■\n");
		printf("         ■■      ■■\n");
		printf("         ■■■    ■■■ \n");
		if (a == 1)
			Frame1++;
		a = 1;
	}
	else if (Frame1 == 2)
	{
		printf("          ■■■■■■\n");
		printf("        ■■□□□□■■\n");
		printf("      ■■□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("      ■■□□□□□□■■\n");
		printf("        ■■□□□□■■\n");
		printf("         ■■■■■■■\n");
		printf("        ■■■■■■■■\n");
		printf("      ■ ■■■■■■■ ■\n");
		printf("    ■   ■■■■■■■   ■  \n");
		printf("  ■     ■■■■■■■     ■\n");
		printf("         ■■      ■■\n");
		printf("         ■■■    ■■■ \n");
		if (a == 1)
			Frame1++;
		else
			Frame1--;
	}
	else if (Frame1 == 3)
	{
		printf("          ■■■■■■\n");
		printf("        ■■□□□□■■\n");
		printf("      ■■□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("      ■■□□□□□□■■\n");
		printf("        ■■□□□□■■\n");
		printf("         ■■■■■■■\n");
		printf("  ■■■■■■■■■■■■■■\n");
		printf("         ■■■■■■■\n");
		printf("         ■■■■■■■\n");
		printf("         ■■■■■■■\n");
		printf("         ■■      ■■\n");
		printf("         ■■■    ■■■ \n");
		if (a == 1)
			Frame1++;
		else
			Frame1--;
	}
	else if (Frame1 == 4)
	{
		printf("          ■■■■■■\n");
		printf("        ■■□□□□■■\n");
		printf("      ■■□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf("    ■■□□□□□□□□■■\n");
		printf(" ■   ■■□□□□□□■■   ■\n");
		printf("   ■   ■■□□□□■■   ■\n");
		printf("      ■ ■■■■■■■ ■\n");
		printf("        ■■■■■■■■\n");
		printf("         ■■■■■■■\n");
		printf("         ■■■■■■■\n");
		printf("         ■■■■■■■\n");
		printf("         ■■      ■■\n");
		printf("         ■■■    ■■■ \n");
		Frame1--;
		a = 0;
	}
}

void DrawTree(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("■■■");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf(" ■■ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf(" ■■ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" ■■ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" ■■ ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void DrawGameOver()
{
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	printf("===========================");
	GotoXY(x, y + 1);
	printf("======G A M E O V E R======");
	GotoXY(x, y + 2);
	printf("===========================");
	GotoXY(x, y + 5);

	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");
}

void DrawWin()
{
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	printf("===========================");
	GotoXY(x, y + 1);
	printf("=======C  L  E  A  R=======");
	GotoXY(x, y + 2);
	printf("===========================");
	GotoXY(x, y + 5);
	
	system("pause");
}

boolean Crush(const int treeX, const int holemanY)
{

	GotoXY(0, 0);

	if (treeX <=10 && treeX >= 6 &&	holemanY > 8)
	{
		return 1;
	}
	return 0;
}


int main()
{
	SetConsoleView();

	while (1)		
	{

		const int gravity = 3;
		int speed = 60;
		int holemanY = HOLEMAN_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;

		int score = 0;

		while (1)	
		{
			
			if (Crush(treeX, holemanY))
				break;

			GetKeyDown();

			if (isJumping)
			{
				holemanY -= gravity;
			}
			else
			{
				holemanY += gravity;
			}
			
			if (holemanY >= HOLEMAN_BOTTOM_Y)
			{
				holemanY = HOLEMAN_BOTTOM_Y;
				isBottom = 1;
			}

			treeX -= 2;
			if (treeX <= 0)
			{
				score++;
				treeX = TREE_BOTTOM_X;
			}
	
			if (holemanY <= 2)
			{
				isJumping = 0;
			}
			if (holemanY < HOLEMAN_BOTTOM_Y)
				JumpDraw(holemanY);
			else
				DrawHoleman(holemanY);		
			DrawTree(treeX);		
	
		
			Sleep(speed - (stage - 1) * 10);
			system("cls");	
			stage = score / 10+1;
		
			if (stage == 7)
				DrawWin(score);

			GotoXY(22, 0);
			printf("Score : %d \n", score);	
			GotoXY(23, 1);
			printf("%d 단계", stage);

		}

		DrawGameOver();
	}
	return 0;
}