#include<stdio.h>
int main()
{
	//이름, 나이, 혈액형 입력받고 출력해보기
	char name[100]; //크기는 넉넉하게 잡거나
	//내가 쓰고자 하는 크기+1만큼 잡기
	//만약 이름이 무조건 3글자라면 name[7]이라고 잡아야 함
	//한글은 1글자당 2byte이고 문자열 끝엔 반드시 1글자(=NULL)가
	//자동으로 들어가기 때문이다.
	int age;
	char bType[100];

	printf("이름이 뭐에요?\n");
	fgets(name, sizeof(name), stdin); //문자열 입력
	for (int i = 0; name[i] != '\0'; i++)
	{
		if (name[i] == '\n')
		{
			name[i] = NULL;
			break;
		}
	}
	printf("나이가 몇살인가요?\n");
	scanf("%d", &age); //scanf_s는 visual studio용이고 표준이 아니다.
	//프로젝트 마우스 오른쪽 클릭 -> c/c++ -> 일반 -> sdl 검사를 끈다.
	printf("혈액형이 뭐에요?\n");
	//char q = getchar(); 
	//scanf("%c", &q);
	while (getchar() != '\n')
	{

	}
	fgets(bType, sizeof(bType), stdin);
	printf("이름 : %s, 나이 : %d, 혈액형 : %s\n",
		name,age,bType);


	return 0;
}