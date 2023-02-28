//저번에 풀었던 초등부 올림피아드 문제를 문자열을 이용해서 풀어보세요
//472x385 = 472x5, 472x8, 472x3, 472x385의 결과 구했던 문제임
//첫번째 수 x 두번째 수의 일의 자리 = 일의 자리 = 세 번째 자리 = [2]
//첫번째 수 x 두번째 수의 십의 자리 = 십의 자리 = 두 번째 자리 = [1]
//첫번째 수 x 두번째 수의 백의 자리 = 백의 자리 = 첫 번째 자리 = [0]

#include<stdio.h>
#include<stdlib.h>  //atoi 라는 함수를 쓰기 위함, 이거 안 써도 되긴 함

int main()
{
	printf("첫 번째 숫자 입력\n");
	char num1[4];
	scanf_s("%s", num1, 4); //이 것과 gets의 차이는 존재합니다. 공백(space bar)처리가 다름
	printf("두 번째 숫자 입력\n");
	char num2[4];
	scanf_s("%s", num2, 4);
	//'0'은 48이다.
	printf("첫번째 수 : %s, 두번째 수:%s\n", num1, num2);
	printf("%d %d %d %d\n",  
		atoi(num1) * (num2[2]-'0'),
		atoi(num1) * (num2[1] - '0'),
		atoi(num1) * (num2[0] - '0'),
		atoi(num1) * atoi(num2));

	int mynum1 = (100 * num1[0]) + (10 * num1[1]) + (num1[2]);//틀린 코드
	printf("%d\n", mynum1);
	mynum1 = (100 * (num1[0]-'0')) + (10 * (num1[1]-'0')) + ((num1[2]-'0')); //맞는 코드
	printf("%d\n", mynum1);
	int mynum2 = (100 * (num2[0] - '0')) + (10 * (num2[1] - '0')) + ((num2[2] - '0'));

	printf("\n%d %d %d %d\n", 
		mynum1*(num2[0]-'0'), mynum1 * (num2[1] - '0'), mynum1 * (num2[2] - '0'),
		mynum1*mynum2);

	//번외
	//내가 입력한 문자열을 하나하나 까서 볼 수 있는 방법
	for (int i = 0; num1[i] != NULL; i++)
		printf("%c %d\n", num1[i], num1[i]);

	//scanf를 이용해서 문자열 입력하는 거랑 gets이용하는 방법의 차이
	//공백 처리가 다르다.

	rewind(stdin);
	char ex[100];
	gets(ex); //fgets가 권장사양이긴 하나 gets로도 돌아간다.
	printf("%s", ex);
	rewind(stdin);
	scanf_s("%s", &ex, sizeof(ex));
	printf("%s", ex); //scanf_s 쓰면 space bar랑 \n을 기준으로 자른다.
	//즉 공백 포함된 문자열 입력 및 출력시에는 scanf_s를 쓰지 않는 게 좋다.

	return 0;
}

