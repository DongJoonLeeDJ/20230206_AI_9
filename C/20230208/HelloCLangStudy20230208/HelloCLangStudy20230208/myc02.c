#include<stdio.h>
int main()
{
	//문자 입력
	printf("당신의 학점은?");
	char grade;
	scanf_s("%c", &grade, 1);//1byte가 필요하단 의미로 1을 추가함
	//문자 출력
	printf("\n당신의 학점은%c입니다.\n", grade);

	printf("당신의 학점은?(숫자)\n");
	double score; //%f로 입력받고 싶다면 float쓰기
	scanf_s("%lf", &score);//lf  =long float = double
	printf("학점 : %f\n", score);
	printf("학점 : %d\n", (int)score);//강제 형변환
	printf("학점 : %.2f\n", score);
	
	//문자열 출력(입력은 나중에)
	printf("저의 MBTI는 %s입니다.\n", "ISTP");
	return 0;
}