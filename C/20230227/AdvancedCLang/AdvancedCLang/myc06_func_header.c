#include<stdio.h>
void printMyName(char* name); //�Լ��� ���� Ȥ�� �Լ��� ������ ǥ��
int sum(int, int, int); //�Ű������� �̸��� ������ �ʰ� ���¸� �����ص� ��.
int main()
{
	printMyName("�̵���");
	int mysum = sum(0, 100, 3);
	printf("%d\n", mysum);
	return 0;
}
//�̷��� ���� ������ �Լ��� ���ǰ� �ʹ� ��ų� ���� ��
//�����ϰ� �Ϸ��� �׷���. ���� �����鸸 �þ���� �Ʒ��� ���Ǹ� �س��´�.
void printMyName(char* name) //�Լ� ����
{
	printf("�� �̸��� %s �Դϴ�.\n", name);
}
int sum(int a, int b, int c)
{
	int sum = 0;
	for (int i = a; i <= b; i += c)
		sum += i;
	return sum;
}