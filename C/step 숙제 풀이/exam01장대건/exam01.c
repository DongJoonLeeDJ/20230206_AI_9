#include<stdio.h>
int main()
{
	int num1, num2;
	printf("두 수를 입력하시오\n");
	scanf_s("%d %d", &num1, &num2);
	printf("%d %d %d %d\n", num1 * (num2 % 10), num1 * (num2 % 100 / 10), num1 * (num2 / 100), num1 * num2);

	int num3;
	int pattern1, pattern2, pattern3, pattern4, pattern5, pattern6;

	printf("입력 : ");
	scanf_s("%d", &num3);

	pattern1 = num3;
	pattern2 = pattern1 * 5 % 7;
	pattern3 = pattern2 * 5 % 7;
	pattern4 = pattern3 * 5 % 7;
	pattern5 = pattern4 * 5 % 7;
	pattern6 = pattern5 * 5 % 7;
	printf("[%d %d %d %d %d %d]", pattern1, pattern2, pattern3, pattern4, pattern5, pattern6);
	return 0;
}