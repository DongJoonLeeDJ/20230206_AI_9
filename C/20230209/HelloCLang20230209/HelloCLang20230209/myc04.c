#include<stdio.h>
int main()
{
	//1.���� �Է¹ް�
	//�� ���� 2022�� �ѹݵ�
	//�ƴϸ� ������ ���
	int year;
	printf("�߲��� �Է�");
	scanf_s("%d", &year);
	year == 2022 ? printf("�ѹݵ�") : printf("������");

	//2. ���̸� �Է��Ѵ�.
	//�׸��� 20�� �̸��̸� ����, 20�� �̻��̸� �����̶�� ����Ѵ�.
	int age;
	printf("�� ��?");
	scanf_s("%d", &age);
	age < 20 ? printf("����\n") : printf("����\n");

	//3. 1���� ���ؼ� 0 �̸��� ���� ���� �߸��� ���̶�� 
	//�޽��� ����ó�� �߰��Ѵ�.
	//���� �����ڴ� ��ø�� ������.
	age < 20 ? (age < 0 ? printf("�߸��� ����\n") : printf("����\n")) : printf("����\n");

	//4. ���� �Է��Ѵ�. ��� 0 ���� �� �ϳ� ���
	int number;
	printf("���� �Է����ּ���.\n");
	scanf_s("%d", &number);
	number != 0 ? ( number > 0 ? printf("���\n"): printf("����\n")) : printf("0\n");

	//5. char ���� �����Ѵ�. int ���� �����Ѵ�. int ������ ���� �Է��Ѵ�.
	int mynum;
	printf("���� �Է��� ��\n");
	scanf_s("%d", &mynum);
	char c = mynum > 0 ? '+' : (mynum == 0 ? '0' : '-');
	printf("��� : %c\n", c);
}