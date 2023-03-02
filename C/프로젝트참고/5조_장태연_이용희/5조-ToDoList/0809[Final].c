#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>

#define FILENAME ("Todo.dat")
#define MAX 1024

// 콘솔 커서이동
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 콘솔창제어
void control_Console()
{
	system("mode con:cols=51 lines=80");
}

// 글자 색
void textColor(int color_Number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Number);
}


struct ToDo {
	char* str;      // 할일을 적는 문자열
	bool completed;  // 참,거짓
};
typedef struct ToDo* ToDoRef;

struct ToDoSize {
	int number;     // 할일 순번
	int maximum;    // 할일 최대 수용량
	ToDoRef* list;   // struct Todo의 값을 참조
};
typedef struct ToDoSize* ToDoSizeRef;

// ToDoSize 구조체 초기화
ToDoSizeRef ToDoSizeInit()
{
	ToDoSizeRef list = (ToDoSizeRef)malloc(sizeof(struct ToDoSize));
	list->number = 0;
	list->maximum = 100;
	list->list = (ToDoRef*)malloc(sizeof(ToDoRef) * list->maximum);
	return list;
}

// 파일 읽어서 보여주는 함수
void show_File(ToDoSizeRef list)
{
	int i = 0;
	ToDoRef current;
	while (i < list->number)
	{	
		textColor(15);
		current = list->list[i];
		if (current->completed) {
			textColor(8);
		}
		printf("\t%d : %s \n", i+1, current->str);
		i++;
		textColor(15);
	}
}

// 할일 기록하기
ToDoRef ToDoCreate(char* name)
{
	ToDoRef newTodo = (ToDoRef)malloc(sizeof(struct ToDo));
	newTodo->str = (char*)calloc(sizeof(char), strlen(name) + 1);
	strcpy(newTodo->str, name);
	newTodo->completed = false;
	return newTodo;
}

// 할일의 순번과 내용을 추가
ToDoRef ToDoListAdd(ToDoSizeRef list, char* name)
{
	if (list->number == list->maximum)
		return NULL;
	ToDoRef newTodo = ToDoCreate(name);
	(list->list)[list->number] = newTodo;
	list->number += 1;
	return newTodo;
}

// 할 일 추가하는 함수
void add_List(ToDoSizeRef list)
{
	rewind(stdin);
	char name[MAX];
	memset(name, 0, MAX);
	textColor(15);
	printf("\n추 가 내 용\n▶ ");
	gets(name);
	ToDoListAdd(list, name);
}

// 파일 불러오기
void ToDoListLoadFromFile(ToDoSizeRef list, FILE* open_file)
{
	list->number = 0;
	int num_List;
	int i = 0;
	ToDoRef newToDo;
	int length_Str;
	bool completed;
	char* str1;
	fread(&(list->maximum), sizeof(int), 1, open_file);
	fread(&num_List, sizeof(int), 1, open_file);
	while (i < num_List)
	{
		fread(&length_Str, sizeof(int), 1, open_file);
		str1 = (char*)calloc(sizeof(char), length_Str + 1);
		fread(str1, sizeof(char), length_Str, open_file);
		fread(&completed, sizeof(bool), 1, open_file);
		newToDo = ToDoCreate(str1);
		newToDo->completed = completed;
		free(str1);
		if (list->number != list->maximum)
		{
			(list->list)[list->number] = newToDo;
			list->number += 1;
		}
		i++;
	}
}

// 파일 저장하기
void ToDoListSave(ToDoSizeRef list, FILE* open_file)
{
	int num_List = list->number;
	int length_List;
	int maximum_List = list->maximum;
	ToDoRef current;
	fwrite(&maximum_List, sizeof(int), 1, open_file);
	fwrite(&num_List, sizeof(int), 1, open_file);
	int i = 0;
	while (i < num_List)
	{
		current = (list->list)[i];
		length_List = strlen(current->str);
		fwrite(&length_List, sizeof(int), 1, open_file);
		fwrite(current->str, sizeof(char), length_List, open_file);
		fwrite(&(current->completed), sizeof(bool), 1, open_file);
		i++;
	}
}

// 삭제하고 순번 정리
void ToDoListRemoveIndex(ToDoSizeRef list, int index)
{
	if (index >= list->number || list->number == 0)
		return;
	ToDoRef toDel = (list->list)[index];
	int i = index;
	while (i < (list->number) - 1)
	{
		(list->list)[i] = (list->list)[i + 1];
		i++;
	}
	list->number -= 1;
}

// 특정순번 할일 삭제
void del_List(ToDoSizeRef list)
{
	int i;
	bool selected = false;
	while (!selected)
	{
		textColor(15);
		printf("\n삭제할 번호 ▶ ");
		scanf_s("%d", &i);
		if (i <= list->number)
			selected = true;
		ToDoListRemoveIndex(list, i-1);
	}
}

//수정한 내용 바꾸기
void ToDoRename(ToDoRef toRename, char* str)
{
	if (strlen(toRename->str) < strlen(str))
		toRename->str = (char*)realloc(toRename->str, sizeof(char) * (strlen(str) + 1));
	memset(toRename->str, 0, strlen(toRename->str) + 1);
	strcpy(toRename->str, str);

}

// 특정순번 내용 수정
void rename_List(ToDoSizeRef list)
{
	int i;
	ToDoRef toRename;
	bool selected = false;
	char str[MAX];
	memset(str, 0, MAX);
	while (!selected)
	{
		textColor(15);
		printf("\n수정할 번호 ▶ ");
		scanf_s("%d", &i);
		if ((list->list)[i - 1]->completed == true)
		{
			printf("\n\t  번호 다시 입력하세요.\n");
			continue;
		}
		if (i <= list->number)
			selected = true;
		toRename = (list->list)[i-1];
		rewind(stdin);
		printf("\n새로운 내용 입력\n▶▷");
		gets(str);
		ToDoRename(toRename, str);
	}
}

// 할일 완료판단
void done_List(ToDoSizeRef list)
{
	ToDoRef toDone;
	int i;
	bool selected = false;
	while (!selected)
	{
		textColor(15);
		printf("\n완료한 번호 선택 ▶ ");
		scanf_s("%d", &i);
		if (i <= list->number)
			selected = true;
		toDone = (list->list)[i-1];
		toDone->completed = true;
	}
}

//프로그램 종료
void exit_Program()
{
	gotoxy(10, 28);
	printf(" 잠시후 프로그램을 종료합니다.\n");
	Sleep(1000);
}

//환영인사
void welcome_Todo()
{
	textColor(15);
	gotoxy(17, 28);
	printf("☆ 처");
	Sleep(300);
	gotoxy(17, 28);
	printf("★ 처음");
	Sleep(300);
	gotoxy(17, 28);
	printf("☆ 처음이");
	Sleep(300);
	gotoxy(17, 28);
	printf("★ 처음이네");
	Sleep(300);
	gotoxy(17, 28);
	printf("☆ 처음이네요");
	Sleep(600);
	gotoxy(17, 28);
	printf("★ 처음이네요! ★");
	Sleep(300);
	gotoxy(17, 30);
	printf("☆ 환");
	Sleep(300);
	gotoxy(17, 30);
	printf("★ 환영");
	Sleep(300);
	gotoxy(17, 30);
	printf("☆ 환영합");
	Sleep(300);
	gotoxy(17, 30);
	printf("★ 환영합니");
	Sleep(300);
	gotoxy(17, 30);
	printf("☆ 환영합니다");
	Sleep(300);
	gotoxy(17, 30);
	printf("★ 환영합니다! ★");
	Sleep(1000);
}

//프로그램 시작
void start()
{
	ToDoSizeRef list = ToDoSizeInit();
	FILE* open_file; 
	fopen_s(&open_file, FILENAME,"rb");
	if (open_file != NULL)
	{
		ToDoListLoadFromFile(list, open_file);
		fclose(open_file);
	}
	else
	{
		welcome_Todo();
	}
	bool finish = true;
	while (finish)
	{
		system("cls");
		textColor(15);
		printf("\n	              메 뉴  \n\n");
		printf(" ① 추 가 ");
		printf(" ② 삭 제 ");
		printf(" ③ 수 정 ");
		printf(" ④ 완 료 ");
		printf(" ⑤ 종 료 \n\n");
		printf("	            To Do List\n\n");
		show_File(list);
		printf("\n\n▶▷▶▷▶▷ ");
		char n;
		scanf_s("%c", &n);
		switch (n)
		{
		case '1':
			add_List(list);
			system("cls");
			break;
		case '2':
			del_List(list);
			system("cls");
			break;
		case '3':
			rename_List(list);
			system("cls");
			break;
		case '4':
			done_List(list);
			system("cls");
			break;
		case '5':
			system("cls");
			exit_Program();
			finish = false;
			break;
		default: break;
		}
		
	}
	fopen_s(&open_file, FILENAME, "wb");
	ToDoListSave(list,open_file);
	fclose(open_file);
}

int main()
{
	control_Console();
	start();
	return 0;
}