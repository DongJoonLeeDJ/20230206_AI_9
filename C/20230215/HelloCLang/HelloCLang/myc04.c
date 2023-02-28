#include<stdio.h>
int main()
{
	int num=1;
	//초기화 하는 부분이랑 증감부분이 생략됨
	//왜냐면 필요없으니까 생략됐다.
	//가운데 조건부 부분만 썼다.
	//num값이 0이 아니면 scanf, printf를 사용하며, 0이면 반복문이 종료가 됨
	for (; num != 0; )
	{
		printf("수를 입력하세요.\n");
		scanf_s("%d", &num);
		printf("%d\n", num * num);

	}

	//break문이라는 게 뭘까?
	//break문은 즉시 종료시키는 것
	//ex) 숫자 입력해서 0이 아니면 제곱 출력, 0이면 즉시 종료
	for (num = 1; /*num != 0*/;)
	{
		printf("수 입력\n");
		scanf_s("%d", &num);
		//for문과 같은 반복문 안쪽에 조건문을 추가할 수 있다.
		if (num == 0)
			break; //break의 용도는 switch의 break와 같다. "빠져나가는 것"
		printf("%d\n", num * num);
	}

	return 0;
}