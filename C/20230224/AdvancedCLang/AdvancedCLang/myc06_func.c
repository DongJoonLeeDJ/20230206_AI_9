#include<stdio.h> //Legacy of the void = ������ ����
//void : ����, �ƹ� �͵� ���� = ��ȯ���� ����. �ƹ� �͵� ����.
void Introduce() //�Ű������� ��ȯ���� ���� ����
{
	char name[100];
	printf("�̸���?\n");
	gets(name);
	printf("�ȳ��ϼ���\n");
	printf("�� �̸��� %s�Դϴ�.\n", name);
}
//��ȯ���� ���� ��Ÿ��
void printPower(int num)
{
	printf("%d�� ���� : %d\n", num, num * num);
}
//��ȯ���� �ִ� ��Ÿ��(=�Ű������� ���� ��Ÿ��)
int isPlus() //�Ű������� �����Ƿ� int isPlus(void)��� ��� ��
{
	printf("���� 2�� �Է�\n");
	int a, b;
	scanf_s("%d %d", &a, &b);
	if (a > b)
		return 1; //a-b�� �� ���
	else if (a < b)
		return -1; //a-b�� �� ����
	else
		return 0;//a-b�� �� 0
}
int main()
{
	Introduce();
	printPower(10);
	//1. �Լ� ����� -> ��ȯ���� �ִ� �Լ��� ��������.(�Ű���������)
	//�Լ� �ȿ��� �� 2���� �Է¹ް� �� ���� ���� ���ϴ�.
	//�� �� ���� ����� 1, 0�̸� 0, ������ -1�� ��ȯ�մϴ�.
	int result = isPlus();
	printf("��� : %d\n", result);
	printf("��� : %d\n", isPlus());
	if (result == 1)
		printf("���\n");
	else if (result == -1)
		printf("����\n");
	else
		printf("zero\n");


	//2. printPower�� �� ���� �ƹ��ų� ����־ ��� Ȯ���غ�����.
	//��ſ� main�� ���� �����ϰ�, scanf�� �� �Է¹ް� �� ������ �Լ��� �Ű������� ������.
	printPower(3);
	int num;
	printf("������ �� �Է�\n");
	scanf_s("%d", &num);
	printPower(num);

	//int a = 3; int b = 5�� ��, �� ���� ���� ���� �ٲ��ִ� �Լ��� ���弼��.
	//a�� b�� main���� �����ϸ�, �Լ��� ���ؼ� main�� a�� b�� �ٲ��� �մϴ�.

	return 0;
}