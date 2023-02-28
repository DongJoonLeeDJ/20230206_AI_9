#include<stdio.h>
int main()
{
	//4. 숫자를 입력받고 아래와 같이 출력한다.(단 3600 미만까지 입력한다고 가정한다.)
	//123 = > 2분 3초
	printf("몇 초?");
	int sec;
	scanf_s("%d", &sec);
	printf("%d분%d초\n", sec / 60, sec % 60);
	//5. 자신의 기분 정보(+ - 0 중 하나),  
	//키, 나이 이런 정보들을 입력받고, 출력
	char myfeel;
	int cm, age;
	//문자 입력하기 전... rewind!
	rewind(stdin);
	printf("기분이 어때요?(+ - 0 중 하나)");
	myfeel = getchar();//scanf_s("%c",&myfeel,1);
	printf("키와 나이 말하세요.(동시에)");
	scanf_s("%d %d", &cm, &age); 
	printf("기분 : %c, 나이 : %d, 키 : %d\n", myfeel, age, cm);
	
	printf("기분, 키, 나이 한 번에 입력해보세요.");
	rewind(stdin);
	scanf_s("%c %d %d", &myfeel, 1, &age, &cm); //myfeel에 대해선 1byte할당
	printf("%c %d %d\n", myfeel, age, cm);


	return 0;
}