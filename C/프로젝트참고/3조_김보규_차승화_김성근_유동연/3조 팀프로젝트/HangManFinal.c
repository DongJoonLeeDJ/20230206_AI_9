
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>


#define WORDS 10 
#define WORDLEN 30 
#define CHANCE 6 

bool srand_called = false;

void consolesize()
{
	system("mode con cols=60 lines=20");
}
int i_rnd(int i)
{
	if (!srand_called)
	{
		srand(time(NULL));
		srand_called = true;
	}
	return rand() % i;
}


void printBody(int mistakes, char* body)
{
	printf("\tMistakes :%d\n", mistakes);
	switch (mistakes)
	{
	case 6:
		body[6] = '\\';
		break;
	case 5:
		body[5] = '/';
		break;
	case 4:
		body[4] = '\\';
		break;
	case 3:
		body[3] = '|';
		break;
	case 2:
		body[2] = '/';
		break;
	case 1:
		body[1] = ')', body[0] = '(';
		break;
	default:
		break;
	}

	printf("\t _________\n"
		"\t|         |\n"
		"\t|        %c %c\n"
		"\t|        %c%c%c\n"
		"\t|        %c %c\n"
		"\t|             \n"
		"\t|             ", body[0], body[1], body[2],
		body[3], body[4], body[5], body[6]);
}

void printWord(char* guess, int len)
{
	printf("\t");
	for (int i = 0; i < len; ++i)
	{
		printf("%c ", guess[i]);
	}
	printf("\n\n");
}

int login()
{
	int n;
	printf("\n\t ó�� ���� �ʰ� �����ϼ���!!.");
	printf("\n\n\t ��Ģ : ");
	printf("\n\t - 6�� �̻� Ʋ���� �ȵ˴ϴ�.");
	printf("\n\t - ��� ���ĺ��� �ҹ��ڷ� ����� �մϴ�.");
	printf("\n\t - ī�װ�");
	printf("\n\t\t1. ����Ʈ");
	printf("\n\t\t2. ����");
	printf("\n\t\t3. ���� �̸�");
	printf("\n\n\t �����ϼ���. : ");
	scanf_s("%d", &n);
	return n;
}

void win_pose()
{
	printf("\t _________\n"
		"\t|         |\n"
		"\t|       \t ( )\n"
		"\t|       \t /|\\\n"
		"\t|       \t / \\\n"
		"\t|       \t      \n"
		"\t|       \t      ");
}

int que_answer(char values[][WORDLEN])
{
	char* body = malloc(CHANCE + 1);
	int id = i_rnd(WORDS);
	char* word = values[id];
	int len = strlen(word);
	char* guessed = malloc(len);
	char falseWord[CHANCE];

	memset(body, ' ', CHANCE + 1);
	memset(guessed, '_', len);
	char guess;
	bool found;
	char* win;

	int mistakes = 0;
	do
	{

		found = false;
		printf("\n\n");
		printBody(mistakes, body);
		printf("\n\n");
		printf("\t���� ��� : ");

		if (mistakes == 0)
		{
			printf("\n");
		}

		for (int i = 0; i < mistakes; ++i)
		{
			printf("%c", falseWord[i]);
		}

		printf("\n\n");
		printWord(guessed, len);
		printf("\t�ҹ��� ���ĺ��� �Է��ϼ���. : ");
		do
		{
			scanf_s("%c", &guess);
		} while (getchar() != '\n');

		for (int i = 0; i < len; ++i)
		{
			if (word[i] == guess)
			{
				found = true;
				guessed[i] = guess;
			}
		}
		if (!found)
		{
			bool falsecheck = false;
			
			for (int i = 0; i < mistakes; i++)
			{
				if (falseWord[i]==guess)
				{
					falsecheck = true;
					break;
				}
			}

			if (falsecheck == false)
			{
				falseWord[mistakes]=guess;
				mistakes += 1;
			}
		}
		 
		win = strchr(guessed, '_');
		system("cls");
	} while (mistakes < CHANCE && win != NULL);

	if (win == NULL)
	{
		printf("\n\n\n");
		printf("\tMistakes :%d\n", mistakes);
		win_pose();
		printf("\n\n\t�����մϴ�! �� ����� ���߽��ϴ�! \n\t������ : \t[%s]\n\n", word);
	}

	else
	{
		printf("\n\n\n");
		printBody(mistakes, body);
		printf("\n\n\t���� ��ȸ��! \n\t������ : \[%s]\n\n", word);
	}

	free(body);
	free(guessed);
	return EXIT_SUCCESS;
}
int main()
{
	consolesize();
	switch (login())
	{
	case 1:
		printf("\n");
		char values1[WORDS][WORDLEN] = { "google", "naver", "youtube", "github",
			"facebook","coupang","namuwiki","twitch","daum","instagram" };
		system("cls");
		printf("\n\t - �α��ִ� ����Ʈ �� �ϳ��Դϴ�. ex. Google");
		rewind(stdin);
		que_answer(values1);
		break;
	case 2:
		printf("\n");
		char values2[WORDS][WORDLEN] = { "china","india","unitedstatesofameria","indonesia","brazil","japan",
			"korea","vietnam","turkey","germany" };
		system("cls");
		printf("\n\t - ������ �� �ϳ��Դϴ�. ex. korea");
		rewind(stdin);
		que_answer(values2);
		break;
	case 3:
		printf("\n");
		char values3[WORDS][WORDLEN] = { "orange","mango","watermelon",
			"peach","banana","melon","apple","dragonfruit","grape","strawberry" };
		system("cls");
		printf("\n\t -���� �̸� �� �ϳ��Դϴ�. ex. orange");
		rewind(stdin);
		que_answer(values3);
		break;
	default:
		break;
	}
	return EXIT_SUCCESS;
}
