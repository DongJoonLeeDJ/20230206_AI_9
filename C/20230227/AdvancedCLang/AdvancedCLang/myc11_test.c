#include<stdio.h>
extern mya;//test_static.c�� �ִ� �� ������ �о��
//static Ű���� ���� ���������� �ܺο��� �о�� �� �ִ�.
extern myb;//�ϴ� ������� ��
int main()
{
	printf("%d\n", mya); //mya�� ���� 10�־���
	mya = 0;//extern ���ؼ� test_static�� mya�� �����ؼ� �� �ٲ�
	printf("%d\n", mya); //�ٽ� ����� ��
	increase(); //mya�� �ϳ� �����ϰ� myb�� ������
	
	//�׷��� ���⼭ myb�� ������ �ɱ�?
	myb++; //���� : �� ��, ���� : static(����)������ �ܺο��� �� ��

	//static����(���� ����)�� Ư¡
	//1. ������ ������ ����Ǹ� ���α׷� ���۽� �̸� �޸𸮿� �ö� ����
	//�޸𸮿� �ö� �ִ� ������ ����, ������ ������.
	//2. �ٸ� c ���Ͽ��� �ش� Ű���� ���� ���� �� �� ����(ex. myb)

	return 0;
}