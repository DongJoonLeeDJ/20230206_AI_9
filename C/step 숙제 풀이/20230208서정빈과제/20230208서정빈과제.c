#include<stdio.h>
int main() {
	//1��
	int a;
	int b;

	printf("�ΰ��� ���ڸ� �Է��ϼ���.");
	scanf_s("%d %d", &a, &b);
	printf("\nù��° �� * �ι�° ���� 1�� �ڸ� ���� = %d\n", a * (b % 100 % 10));
	printf("ù��° �� * �ι�° ���� 10�� �ڸ� ���� = %d\n", a * (b  % 100 / 10));
	printf("ù��° �� * �ι�° ���� 100�� �ڸ� ���� = %d\n", a * (b / 100));
	printf("ù��° �� * �ι�° �� = %d", a * b);

	//2��
	int num;
	printf("�ݺ��Ǵ� ��ȯ ���� 5 4 6 2 3 1 \n");
	printf("5 4 6 2 3 1 �� �ϳ��� �Է��ϼ���.");
	scanf_s("%d", &num);
	printf("%d ", num);
	num = ((7-num)*2)%7;
	printf("%d ", num);
	printf("%d ", num = ((7-num)*2)%7);
	printf("%d ", num = ((7-num)*2)%7);
	printf("%d ", num = ((7-num)*2)%7);
	printf("%d ", num = ((7-num)*2)%7);
}
