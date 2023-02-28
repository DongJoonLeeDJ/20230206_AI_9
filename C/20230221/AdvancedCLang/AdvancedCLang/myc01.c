#include<stdio.h>
int main()
{
	//포인터 = 주소
	int a = 100;
	int* pt_a = &a;
	printf("%d\n", *pt_a);
	(*pt_a)++;
	printf("%d\n", pt_a);
	printf("%d\n", a);
	printf("%d\n", *pt_a);






	pt_a++;
	printf("%d\n", pt_a);//???
	printf("%d\n", *pt_a);//???
	//배열
	int n[5] = { 10,20,30,40,50 };
	int* p = n;
	printf("%d %d\n", p, n);
	for (int i = 0; i < 5; i++)
	{
		printf("%d %d\n", n[i], p[i]);
		printf("%d %d\n", *(n+i), *(p+i));
		printf("-----\n");
	}








	int n2[10];
	for (int i = 0; i < 10; i++)
	{
		n2[i] = i * i * 10;
		printf("%d\n", n2[i]);
	}
	printf("숫자 5개 입력해보세요.\n");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &n[i]);
	}
	int size = sizeof(n) / sizeof(n[0]); //배열 길이
	printf("%d\n", size);
	for (int i = 0; i < size; i++)
		printf("%d\n", n[i]);

	//문자열
	char* name1 = "장대건";
	printf("%s\n", name1);
	//gets(name1); //입력받을 땐 char*가 아니라 char name[100] 이런식으로 크기 정해진 배열로 할 것
	//printf("%s", name1);

	//숫자나 문자를 입력받을 때 버퍼에 남아있는 \n을 제거하기 위함
	//참고로 gets하고 나서 gets 또 할 땐 rewind가 필요없다.
	
	rewind(stdin);
	char name[100];
	printf("이름이 뭐에요?\n");
	gets(name);
	printf("이름 : %s\n", name);
	char mbti[5];
	printf("mbti?\n");
	gets(mbti);
	printf("%s\n", mbti);

	//문자열을 입력받는다. 
	//1. 이걸 그대로 출력한다.
	//2.여기서 영어에 대해서는 대문자를 소문자로, 소문자를 대문자로 바꿔서 출력한다.

	//문자열을 입력할 때 비밀번호를 입력한다고 생각하고 해보세요.
	//1. 숫자만 입력받게 할 것.  ex) 123a 이렇게 입력받으면 오류를 출력, 1234 이렇게 입력시 통과
	//2. 숫자와 영어가 조합되어야 하고 8글자 이상이어야지만 통과
	//3. 숫자, 영어, 특수문자 조합이어야 하고 8글자 이상이어야지만 통과하며 특수문자는 !와 _만 허용
	//4. 출력할 땐 글자수에 따라서 *로 바꿔서 출력 ex) 1234abcd! => *********

	//저번에 풀었던 초등부 올림피아드 문제를 문자열을 이용해서 풀어보세요
	//472x385 = 472x5, 472x8, 472x3, 472x385의 결과 구했던 문제임

	return 0;
}