#include<stdio.h>
//1. ��ȯ�� ���� �Ű������� s �ϳ��� �Լ��� �ۼ� �� main���� ȣ��
//���� : s = 123 = > 2�� 3�ʶ�� �޽����� ����Ʈ��
void mytime(int s)
{
	if (s <= 0)
	{
		printf("%d�� �߸��� ���Դϴ�.\n", s);
		return; //��� �Լ� �����. �ؿ� �ڵ� ���� �� ��.
	}
	if (s % 60 == 0)
	{
		printf("%d��\n", s / 60);
		return;
	}
	printf("%d�� %d��\n", s / 60, s % 60);
}
int main()
{
	int s = 123;
	mytime(s);
	return 0;
}