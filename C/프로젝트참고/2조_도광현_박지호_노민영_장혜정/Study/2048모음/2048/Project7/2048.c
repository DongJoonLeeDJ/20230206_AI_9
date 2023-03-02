#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<memory.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define MAP_ADJ_X 0
#define MAP_ADJ_Y 8
int board[4][4] = 
{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
};
int score = 0;
int max = 0;
int temp_max = 0;
int move = 0;
int over = 0;
int win = 0;
int newnum = 0;
#define UP 72
#define UNDER 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
void setcolor(int text, int back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back * 16));
}
void SetConsoleView()
{
    system("mode con:cols=110 lines=32");
    system("title 2048");
}

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void new_num() 
{
    int i, j;
    int num = 0;
    int* boards[16] = { 0 };
    srand(time(NULL));
    for (i = 0, num = 0; i < 4; i++) 
    {
        for (j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                boards[num] = &board[i][j];
                num++;
            }
        }
    }
    *boards[rand() % num] = (rand() % 100 < 85) ? 2 : 4;
}

void draw() {
    int i, j;

    system("cls");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
    printf("         iBB          □□□  □□□  □  □  □□□          iBM         		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
    printf("        PgBs              □  □  □  □  □  □  □           BBQi       		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
    printf("       Bv g           □□□  □  □  □□□  □□□           iq Bi      		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 1);
    printf("      Bb Z            □      □  □      □  □  □           Q  Bi     		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y);
    printf("     QR  B            □□□  □□□      □  □□□           qv iB     		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 1);
    printf("    dBi  B              ■■■■■■■■■■■■■           gr  BDi   		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 2);
    printf("   D  B  Pv             ■                      ■          B  SZ gi  		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 3);
    printf("   B  Q   B             ■                      ■          Xu  uv vU  		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 4);
    printf("   Bi BJ  iB            ■                      ■         vB   Bi Bi  		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 5);
    printf("  iBi iB   vB           ■                      ■        UB   RB  BR  		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 6);
    printf(" kr Zk  BB    Ps        ■                      ■     iZi   KBi  B  B 		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 7);
    printf(" UB  Zr  BBU  irRv      ■                      ■   iDIi  iBBi  dv iB 		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 8);
    printf("SdR  iBv  PBq Bv vPY    ■                      ■   iKI  BiiBQv  Bd vBj		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 9);
    printf("B iB  rBX  BQ iBr  iU   ■                      ■  r  BK iBr rBP  sQ Pp		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 10);
    printf("B iB  rBX  BQ iBr  iUKv ■                      ■ r   BK iBr rBP  sQ Pp		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 11);
    printf("sv vB  iBQ jUi  Lj    i ■■■■■■■■■■■■■ r Sv  iI  iiQ vBI  Ss		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 12);
    printf(" iu kQL  EBvQBv  iQUi    YPi                 uXi    vDK   DBugBv iZM  Q 		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 13);
    printf("  M  iQS  g   Sv  LXEBII   dv               Mr  vuQQqki iXv  jU rBu  Ei 		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 14);
    printf("   BJ  vMivDi  iXuiibR      Qi             Mi     vBiivqv   sD IP  igb  		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 15);
    printf("   LiBi iSPBBk   JkkBQi     Ki             R      sBKkUi  iBBEKL  dbii  		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 16);
    printf("   ri sBi iBiiirvLrKR     iVv               VU     vBrvvrri Mu  MQ  U   		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 17);
    printf("    gQ  KQuBri   irvgii    Bi               Bi  iiXXrr   iiQddgr   iB    		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 18);
    printf("     qKi  iUBBBDLvsJPBv    Pkr             ePv    BBJjvvIBBBDr   vMi    		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 19);
    printf("       LRi  vBBLi  iVBJir    vb          iD    viQMv   iqBZi  Pqi      		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 20);
    printf("         VB    irjqBB  i     Qi          Ri     qBQuLii       iB            		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 21);
    printf("          iBvsgi   YXQBBr    Pi          bi    BBBDui  iUbrPZ            		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22);
    printf("            Ur   s  UBBqIi   ur   iji    uUBBdi rv   Eqwea               		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 23);
    printf("                 iMPRV  ri XBPPviiiUvIi irjZdBi I  iBKDS               		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 24);
    printf("                    vIUvB  Q u             u iJ uQrUK                  		\n");
    gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 25);
    printf("                     iiivYvii              YiIrviii                   \n");
    gotoxy(MAP_ADJ_X + 80, MAP_ADJ_Y-1);
    printf(" ← , → , ↑ , ↓ : move");

    for (i = 0; i < 4; i++) 
    {
        for (j = 0; j < 4; j++) 
        {
            if (board[i][j] == 0)
            {
                gotoxy(MAP_ADJ_X +j*5+25, MAP_ADJ_Y +i*2-1);
                printf("    .");
            }
            else 
                if (board[i][j] > 10000)
                {
                    gotoxy(MAP_ADJ_X + j*5+25, MAP_ADJ_Y + i*2-1);
                    printf("%5d", board[i][j] - 10000);
                }
                else
                {
                    gotoxy(MAP_ADJ_X + j*5+25, MAP_ADJ_Y + i*2-1);
                    printf("%5d", board[i][j]);
                }
        }
        printf("\n");
    }
    printf("\n");
    gotoxy(MAP_ADJ_X + 80, MAP_ADJ_Y );
    printf("Score = %d\n", score);
    gotoxy(MAP_ADJ_X + 80, MAP_ADJ_Y+1 );
    printf("Max Score = %d", max);
}

void leftbutton()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            for (int r = j; r > 0; r--)
            {
                if (board[i][r] == 0 )
                    break;
                if (board[i][r - 1] != 0 && board[i][r - 1] != board[i][r])
                    break;
                if (board[i][r - 1] == 0)
                {
                    board[i][r - 1] = board[i][r];
                    board[i][r] = 0;
                    move++;
                }
                else if (board[i][r - 1] == board[i][r] && board[i][r] < 10000)
                {
                    board[i][r - 1] *= 2;
                    board[i][r] = 0;
                    score += board[i][r - 1];
                    board[i][r - 1] += 10000;
                    move++;
                }
                //if (move != 0)
                //{
                //    draw();
                //    _sleep(50);
                //}
            }
        }
    }
}

void rightbutton()
{
    for (int i = 0 ; i < 4; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            for (int r = j; r < 3; r++)
            {
                if (board[i][r] == 0)
                {
                    break;
                }
                if (board[i][r + 1] != 0 && board[i][r] != board[i][r + 1])
                {
                    continue;
                }
                if (board[i][r + 1] == 0)
                {
                    board[i][r + 1] = board[i][r];
                    board[i][r] = 0;
                    move++;
                }
                else if (board[i][r + 1] == board[i][r] && board[i][r] <10000)
                {
                    board[i][r + 1] = board[i][r] * 2;
                    score += board[i][r]*2;
                    board[i][r + 1] += 10000;
                    board[i][r] = 0;
                    move++;
                }
            //if (move != 0)
            //{
            //    draw();
            //    _sleep(20);
            //}
            }
        }
    }
}

void upbutton()
{
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j <4; j++)
        {
            for (int r = i; r >0; r--)
            {
                if (board[r][j] == 0)
                {
                    continue;
                }
                if (board[r - 1][j] != 0 && board[r][j] != board[r - 1][j]) //
                {
                    continue;
                }
                if (board[r-1][j] == 0)
                {
                    board[r-1][j] = board[r][j];
                    board[r][j] = 0;
                    move++;
                  
                }
                else if (board[r-1][j] == board[r][j] && board[r][j] < 10000)
                {
                    board[r-1][j] = board[r][j] * 2;
                    score += board[r][j]*2;
                    board[r-1][j] += 10000;
                    board[r][j] = 0;
                    move++;
                }
                //if (move != 0)
                //{
                //    draw();
                //    _sleep(20);
                //}
            }
        }
    }
}

void underbutton()
{
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int r = i; r < 3; r++)
            {
                if (board[r][j] == 0)
                {
                    continue;
                }
                if (board[r + 1][j] != 0 && board[r][j] != board[r + 1][j]) //
                {
                    continue;
                }
                if (board[r + 1][j] == 0)
                {
                    board[r + 1][j] = board[r][j];
                    board[r][j] = 0;
                    move++;

                }
                else if (board[r + 1][j] == board[r][j] && board[r][j] < 10000)
                {
                    board[r + 1][j] = board[r][j] * 2;
                    score += board[r][j]*2;
                    board[r + 1][j] += 10000;
                    board[r][j] = 0;
                    move++;
                }
            }
                //if (move != 0)
                //{
                //    draw();
                //    _sleep(20);
                //}
        }
    }

}

void checkgameover()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
                return;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == board[i][j + 1])
                return;
            if (board[i][j] == board[i + 1][j])
                return;
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (board[3][j] == board[3][j + 1])
            return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[i][3] == board[i+1][3])
            return;
    }
    gotoxy(MAP_ADJ_X + 80, MAP_ADJ_Y + 2);
    printf("Game Over\n");
    over++;
}

void checkwin()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 2048)
                win++;

        }
    }

}
void curserdelete()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.bVisible = 0;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main()
{
    //system("color F0");
    curserdelete();
    SetConsoleView();


    FILE* fp;
    fp = fopen("score.txt", "r");
    fscanf(fp, "%d", &temp_max);
    if (temp_max > max)
        max = temp_max;
    fclose(fp);

    score = 0;
    int key;
    A:
    PlaySound(TEXT("ojing.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = 0;

        }
    }

    new_num();
    new_num();
    draw();

    while(1)
    {
        key = _getch();
        if (key == 0 || key == 0xE0)
        {
            key = _getch();
        }
        switch (key)
        {
        case LEFT:
            leftbutton();
            break;
        case RIGHT:
            rightbutton();
            break;
        case UP:
            upbutton();
            break;
        case UNDER:
            underbutton();
            break;
        case ESC:
            system("cls");
            exit(0);
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
             {
                if (board[i][j] > 10000)
                    board[i][j] -= 10000;
             }
         }
        if (move > 0)
        {
            new_num();
            draw();
            checkgameover();
            checkwin();
        }
        move = 0;

        if (win == 1)
        {
            gotoxy(MAP_ADJ_X + 80, MAP_ADJ_Y + 2);
            printf("Clear");
            break;
        }
        if (over == 1)
        {
            PlaySound(NULL, 0, 0);
            PlaySound(TEXT("debuff.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
            char re;
            if(max < score)
                  max = score;

            if (max > temp_max)
            {
                fp = fopen("score.txt", "w");
                fprintf(fp, "%d", max);
                fclose(fp);
            }
            over = 0;
            score = 0;
            gotoxy(MAP_ADJ_X + 80, MAP_ADJ_Y + 3);
            printf("다시 하시겠습니까? Y/N\n");
            B:
            re = _getch();
            if (re == 'y')
            {
                PlaySound(NULL, 0, 0);
                goto A;
            }
            else if (re == 'n')
                break;
            else
                goto B;
                
        }
    }
    
  
	return 0;
}