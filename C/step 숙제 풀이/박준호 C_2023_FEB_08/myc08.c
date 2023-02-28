
//다음과 같이 숫자 패턴 "5 4 6 2 3 1"이 반복되는 순환 수열이 있다.
//5 4 6 2 3 1 5 4 6 2 3 1 5 ...
// 
//1부터 6까지 정수들 가운데 하나의 정수를 입력하면 주어진 수열에서 그 숫자부터 시작해서
//6개의 숫자를 연속으로 출력하는 프로그램을 작성하시오.
//제한사항 : 지금까지 배운 내용만 사용해야 함(조건문 반복문 배열 쓰면 안 됨)
//입력과 출력 예시
//입력 : 4
//출력[4 6 2 3 1 5]
//
//입력 : 5
//출력[5 4 6 2 3 1]

#include<stdio.h>
int main() {

	int input;
	int case1, case2, case3, case4, case5, case6;

	printf("숫자 입력를 입력하세요.: ");
	scanf_s("%d", &input);

	case5 = 1 / (((input + 2) % 7) + 1);
	case4 = 1 / (((input + 3) % 7) + 1);
	case6 = 1 / (((input + 1) % 7) + 1);
	case2 = 1 / (((input + 5) % 7) + 1);
	case3 = 1 / (((input + 4) % 7) + 1);
	case1 = 1 / (((input + 6) % 7) + 1);

	int answer = 546231 * case5 + 462315 * case4 + 623154 * case6 + 231546 * case2 + 315462 * case3 + 154623 * case1;

	printf("[%d, %d, %d, %d, %d, %d]", answer/100000, answer/10000%10, answer/1000%10, answer/100%10, answer/10%10, answer%10);

	return 0;
}