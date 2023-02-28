//같은 문제를 배열 선언할 때 빼곤 포인터로 해보기
//numbers[i]=getchar 대신 * 문법을 써서 글자 집어넣기


#include<stdio.h>
#define MAXSIZE 100
#include<stdbool.h>
int main()
{
	char numbers[MAXSIZE];
	int i = 0;
	int isnum = true;
	while (true) //무한루프 반복문
	{
		char c = getchar();
		rewind(stdin); //버퍼에 남은 \n을 제거(=파일포인터를 첫부분으로 이동)
		if (c == '-')
			break;
		if (c < '0' || c>'9')
		{
			isnum = false;
			printf("again!\n");
			continue;
		}
		//numbers[i] = c;
		*(numbers + i) = c;
		i++;
	}
	isnum = true;
	//numbers[i] = NULL; //끝 마무리 짓기
	*(numbers + i) = NULL;
	if (isnum == true) // if(isnum)
	{
		printf("%s\n", numbers);
	}
	return 0;
}