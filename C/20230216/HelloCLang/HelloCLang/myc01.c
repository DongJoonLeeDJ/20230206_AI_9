#include<stdio.h>
int main()
{
	//1. ���� a�� b�� c�� ���� �Է¹ް�, 
	//a���� b������ ���� ���ϵ�, c�� ��� �κ���
	//�����ϰ� ���� ���� ��.
	int a, b, c;
	printf("���� 3���� �Է��ϼ���.\n");
	scanf_s("%d %d %d", &a, &b, &c);
	int s = 0;
	if (a <= b)
	{
		for (int i = a; i <= b; i++)
		{
			if (i % c != 0)
				s += i;
		}
		printf("%d���� %d������ ��(%d ��� ����) : %d\n",a,b,c,s);
	}
	else //a�� b���� �� ũ�ٸ� ��� �ؾ� �ұ��?
	{
		//1. �ܼ��� �߸��ƴٴ� �޽����� ��� ���� �ִ�.
		printf("a(%d)�� b(%d)���� Ů�ϴ�. ���� �ٲٰڽ��ϴ�.\n",a,b);
		//2. a�� b�� ���� ���� �ٲ� ������ ������ ������ �� �ִ�.
		int temp = a;
		a = b;
		b = temp;

		for (int i = a; i <= b; i++)
		{
			if (i % c != 0)
				s += i;
		}
		printf("%d���� %d������ ��(%d ��� ����) : %d\n", a, b, c, s);
	}


	return 0;
}