/*
3. int a = 3; int b = 5�� ��, �� ���� ���� ���� �ٲ��ִ� �Լ��� ���弼��.
a�� b�� main���� �����ϸ�, �Լ��� ���ؼ� main�� a�� b�� �ٲ��� �մϴ�.
*/
#include<stdio.h>
void swap(int* x, int* y)
{
	int temp = *x; //x�� ����Ű�� �޸��� ���� temp�� ����
	*x = *y; //x�� ����Ű�� �޸��� ���� y�� ����Ű�� �޸��� ������ ����
	*y = temp; //y�� ����Ű�� �޸��� ���� temp�� ����� ������ ����
}
int main()
{
	int a = 3, b = 5;
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);//a=5, b=3���� �����
	return 0;
}