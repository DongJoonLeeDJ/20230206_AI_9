#include<stdio.h>
int main()
{
	//���� �Է�
	printf("����� ������?");
	char grade;
	scanf_s("%c", &grade, 1);//1byte�� �ʿ��ϴ� �ǹ̷� 1�� �߰���
	//���� ���
	printf("\n����� ������%c�Դϴ�.\n", grade);

	printf("����� ������?(����)\n");
	double score; //%f�� �Է¹ް� �ʹٸ� float����
	scanf_s("%lf", &score);//lf  =long float = double
	printf("���� : %f\n", score);
	printf("���� : %d\n", (int)score);//���� ����ȯ
	printf("���� : %.2f\n", score);
	
	//���ڿ� ���(�Է��� ���߿�)
	printf("���� MBTI�� %s�Դϴ�.\n", "ISTP");
	return 0;
}