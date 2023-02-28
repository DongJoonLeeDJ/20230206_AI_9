#include<stdio.h>
int main() {
	//1번
	int a;
	int b;

	printf("두개의 숫자를 입력하세요.");
	scanf_s("%d %d", &a, &b);
	printf("\n첫번째 수 * 두번째 수의 1의 자리 숫자 = %d\n", a * (b % 100 % 10));
	printf("첫번째 수 * 두번째 수의 10의 자리 숫자 = %d\n", a * (b  % 100 / 10));
	printf("첫번째 수 * 두번째 수의 100의 자리 숫자 = %d\n", a * (b / 100));
	printf("첫번째 수 * 두번째 수 = %d", a * b);

	//2번
	int num;
	printf("반복되는 순환 수열 5 4 6 2 3 1 \n");
	printf("5 4 6 2 3 1 중 하나를 입력하세요.");
	scanf_s("%d", &num);
	printf("%d ", num);
	num = ((7-num)*2)%7;
	printf("%d ", num);
	printf("%d ", num = ((7-num)*2)%7);
	printf("%d ", num = ((7-num)*2)%7);
	printf("%d ", num = ((7-num)*2)%7);
	printf("%d ", num = ((7-num)*2)%7);
}
