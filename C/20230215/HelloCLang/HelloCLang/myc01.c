#include<stdio.h>
int main()
{
	int a = 10;
	a++; //a+=1 �̰Ŷ� �ǹ̰� ����. //a=a+1�̰Ŷ� �ǹ̰� ����.
	++a;
	printf("%d\n", a);
	printf("%d %d\n", a++ , ++a);
	printf("%d\n", a);
	printf("%d %d\n", ++a , a++);
	printf("%d\n", a);
	printf("%d\n", ++a); //���� �켱 1 ���� ������ ȭ�鿡 ���
	printf("%d\n", a++); //�켱 ȭ�鿡 ����ϰ� ���� ����
	printf("%d\n", a);

	int b = 100;
	printf("%d\n", b);
	printf("%d\n", ++b + b++);
	printf("%d\n", b);

	//�������� ���� �׳� 2�ٷ� ���� ��
	//�� �Ƴ����� ++�̳� --�� �տ� ���̱� ���� �� �ٷ� ǥ���� ��
	int c = 100;
	c++;
	printf("%d\n", c + c);
	c++;
	printf("%d\n", c);

	return 0;
}