#include<stdio.h>
int main()
{
	// ���� ���� �Է¹ޱ�
	int year; //������ �����ϹǷ� �Ҽ����� ���� ����
	printf("���ش� ��⵵�ΰ���?"); //���
	scanf_s("%d", &year); //�Է�, year ������ �� �Է��ϰ� ��
	printf("\n���ش� %d�⵵�Դϴ�.\n", year);

	int age;
	printf("�� ���̴�?");
	scanf_s("%d", &age);
	printf("\n���� %d����Դϴ�.\n", year - age + 1);

	//�� ���� ���� ���� ���ڸ� �Է��� �� �ִ�.
	printf("�¾ ������ ���̸� �Է��ϼ���.\n");
	int birth;
	scanf_s("%d %d", &birth, &age);//1989 35 �̷��� �Է�
	printf("������ %d�⵵�Դϴ�.\n", birth + age - 1);

	scanf_s("%d,%d", &birth, &age); //1989,35 �̷��� �Է��ؾ� ��
	printf("birth:%d, age:%d\n", birth, age);
	return 0;
}