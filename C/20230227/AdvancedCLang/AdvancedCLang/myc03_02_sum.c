/*
2. ��ȯ���� �ְ� �Ű������� ���� �Լ��� �ۼ� �� main���� ȣ��
���� : 1���� 100������ ���� ���ϵ� 3�� ����� ������ ���� ��ȯ�ϴ� �Լ��� �����
�̸� ���ο��� ȣ���Ͽ� �� Ȯ��
*/
#include<stdio.h>
int sum_3baesu()
{
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			sum += i;
	}
	return sum;
}
int main()
{
	printf("%d\n", sum_3baesu());
	int a = sum_3baesu();
	printf("%d\n", a);
	return 0;
}