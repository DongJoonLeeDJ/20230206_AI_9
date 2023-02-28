#include<stdio.h>
#define TRUE 1
#define FALSE 0
int main()
{
	char n[3]; //2글자(영문자,숫자,특수문자)만 입력 가능
	n[0] = '0';
	n[1] = 'a';
	n[2] = NULL; //\0
	printf("%s\n", n);
	char n2[3];
	n2[0] = '0';
	n2[1] = 'a';
	n2[2] = '1'; //NULL로 마무리를 못하면 어디서 끝내야 할지 몰라서 쓰레기값 출력
	printf("%s\n", n2);
	char n3[6] = "장대건"; //한글은 1글자당 2byte이므로 3글자 이름 입력시 최소 7byte할당
	printf("%s\n", n3);
	char n4[3];
	scanf_s("%s", n4, sizeof(n4)); //scanf로 입력할 때 글자수가 3글자 이상이면 튕김
	printf("%s\n", n4);
	rewind(stdin);
	char n5[3];
	gets(n5); //글자수가 많아도 튕기진 않지만
	printf("%s\n", n5); //n5에 실질적으로 저장되는 건 저 칸 수 만큼이다.
	//결론 : NULL(=\0)가 있을 만큼의 공간은 확보해야 함(1칸 더 있어야 함)


	//숫자만 입력하게 하기
	char numbers[100];
	printf("숫자입력해\n");
	gets(numbers);
	int flag = TRUE; //numbers에 있는 값들이 수인지 여부 판별
	for (int i = 0; numbers[i] != NULL; i++)
	{
		if (numbers[i] != '\n' && (numbers[i] < '0' || numbers[i] > '9'))
		{
			flag = FALSE;
			printf("숫자만 입력하라구~\n");
			break;
		}
	}
	//1. 숫자만 입력한 경우에만 최종 결과가 출력되게 해보세요.
	if (flag)
		printf("%s\n", numbers);
	return 0;
}