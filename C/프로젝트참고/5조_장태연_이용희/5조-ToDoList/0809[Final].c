#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdbool.h>

#define FILENAME ("Todo.dat")
#define MAX 1024

// �ܼ� Ŀ���̵�
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// �ܼ�â����
void control_Console()
{
	system("mode con:cols=51 lines=80");
}

// ���� ��
void textColor(int color_Number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_Number);
}


struct ToDo {
	char* str;      // ������ ���� ���ڿ�
	bool completed;  // ��,����
};
typedef struct ToDo* ToDoRef;

struct ToDoSize {
	int number;     // ���� ����
	int maximum;    // ���� �ִ� ���뷮
	ToDoRef* list;   // struct Todo�� ���� ����
};
typedef struct ToDoSize* ToDoSizeRef;

// ToDoSize ����ü �ʱ�ȭ
ToDoSizeRef ToDoSizeInit()
{
	ToDoSizeRef list = (ToDoSizeRef)malloc(sizeof(struct ToDoSize));
	list->number = 0;
	list->maximum = 100;
	list->list = (ToDoRef*)malloc(sizeof(ToDoRef) * list->maximum);
	return list;
}

// ���� �о �����ִ� �Լ�
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

// ���� ����ϱ�
ToDoRef ToDoCreate(char* name)
{
	ToDoRef newTodo = (ToDoRef)malloc(sizeof(struct ToDo));
	newTodo->str = (char*)calloc(sizeof(char), strlen(name) + 1);
	strcpy(newTodo->str, name);
	newTodo->completed = false;
	return newTodo;
}

// ������ ������ ������ �߰�
ToDoRef ToDoListAdd(ToDoSizeRef list, char* name)
{
	if (list->number == list->maximum)
		return NULL;
	ToDoRef newTodo = ToDoCreate(name);
	(list->list)[list->number] = newTodo;
	list->number += 1;
	return newTodo;
}

// �� �� �߰��ϴ� �Լ�
void add_List(ToDoSizeRef list)
{
	rewind(stdin);
	char name[MAX];
	memset(name, 0, MAX);
	textColor(15);
	printf("\n�� �� �� ��\n�� ");
	gets(name);
	ToDoListAdd(list, name);
}

// ���� �ҷ�����
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

// ���� �����ϱ�
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

// �����ϰ� ���� ����
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

// Ư������ ���� ����
void del_List(ToDoSizeRef list)
{
	int i;
	bool selected = false;
	while (!selected)
	{
		textColor(15);
		printf("\n������ ��ȣ �� ");
		scanf_s("%d", &i);
		if (i <= list->number)
			selected = true;
		ToDoListRemoveIndex(list, i-1);
	}
}

//������ ���� �ٲٱ�
void ToDoRename(ToDoRef toRename, char* str)
{
	if (strlen(toRename->str) < strlen(str))
		toRename->str = (char*)realloc(toRename->str, sizeof(char) * (strlen(str) + 1));
	memset(toRename->str, 0, strlen(toRename->str) + 1);
	strcpy(toRename->str, str);

}

// Ư������ ���� ����
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
		printf("\n������ ��ȣ �� ");
		scanf_s("%d", &i);
		if ((list->list)[i - 1]->completed == true)
		{
			printf("\n\t  ��ȣ �ٽ� �Է��ϼ���.\n");
			continue;
		}
		if (i <= list->number)
			selected = true;
		toRename = (list->list)[i-1];
		rewind(stdin);
		printf("\n���ο� ���� �Է�\n����");
		gets(str);
		ToDoRename(toRename, str);
	}
}

// ���� �Ϸ��Ǵ�
void done_List(ToDoSizeRef list)
{
	ToDoRef toDone;
	int i;
	bool selected = false;
	while (!selected)
	{
		textColor(15);
		printf("\n�Ϸ��� ��ȣ ���� �� ");
		scanf_s("%d", &i);
		if (i <= list->number)
			selected = true;
		toDone = (list->list)[i-1];
		toDone->completed = true;
	}
}

//���α׷� ����
void exit_Program()
{
	gotoxy(10, 28);
	printf(" ����� ���α׷��� �����մϴ�.\n");
	Sleep(1000);
}

//ȯ���λ�
void welcome_Todo()
{
	textColor(15);
	gotoxy(17, 28);
	printf("�� ó");
	Sleep(300);
	gotoxy(17, 28);
	printf("�� ó��");
	Sleep(300);
	gotoxy(17, 28);
	printf("�� ó����");
	Sleep(300);
	gotoxy(17, 28);
	printf("�� ó���̳�");
	Sleep(300);
	gotoxy(17, 28);
	printf("�� ó���̳׿�");
	Sleep(600);
	gotoxy(17, 28);
	printf("�� ó���̳׿�! ��");
	Sleep(300);
	gotoxy(17, 30);
	printf("�� ȯ");
	Sleep(300);
	gotoxy(17, 30);
	printf("�� ȯ��");
	Sleep(300);
	gotoxy(17, 30);
	printf("�� ȯ����");
	Sleep(300);
	gotoxy(17, 30);
	printf("�� ȯ���մ�");
	Sleep(300);
	gotoxy(17, 30);
	printf("�� ȯ���մϴ�");
	Sleep(300);
	gotoxy(17, 30);
	printf("�� ȯ���մϴ�! ��");
	Sleep(1000);
}

//���α׷� ����
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
		printf("\n	              �� ��  \n\n");
		printf(" �� �� �� ");
		printf(" �� �� �� ");
		printf(" �� �� �� ");
		printf(" �� �� �� ");
		printf(" �� �� �� \n\n");
		printf("	            To Do List\n\n");
		show_File(list);
		printf("\n\n������������ ");
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