#include<stdio.h>
void mytest1()
{
	int a = 10;
	a++;//�Լ��� ����Ǹ� �ڵ� �Ҹ�
	printf("a=%d\n", a);
}
void mytest2()
{
	//����ƽ ���� = ���� ����
	static int a = 10;//static�� ���� ������ ���� ����
	a++;//������ �޸� ������ ������ �ȴ�. �׷��� ���α׷��� ����� �� �Ҹ��
	printf("static a=%d\n", a);
}
//int aa = 10; //�۷ι����� ��������� ���������� �Ȱ��� �̸� ��� ����
static int cx = 1000; //������������ static�� �ٳ�!?
int main()
{
	//printf("%d\n", aa);
	//int aa = 100;
	//printf("%d\n", aa); //�׷��� ���� ��������(�̷� �� ���̵�(Hiding)�̶�� ��)
	mytest1();//11
	mytest1();//11
	mytest2();//static a = 11
	mytest2();//static a = 12



	return 0;
}