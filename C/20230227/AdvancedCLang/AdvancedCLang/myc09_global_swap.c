#include<stdio.h>
//��������(�۷ι� ����)�� main�̶� �ٸ� �Լ����� ���������� �а� �� �� �ִ�.
int a = 3, b = 5; 
void swap()
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	//int a = 1000; //�۷ι� ������ ������, ���̵�, a=1000�� ��µǹ���
	printf("a=%d, b=%d\n", a, b);
	swap();
	printf("a=%d, b=%d\n", a, b);
	return 0;
}