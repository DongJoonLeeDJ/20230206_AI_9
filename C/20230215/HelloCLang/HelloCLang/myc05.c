#include<stdio.h>
int main()
{
	//1���� 100���� ���ϴ� ��, ¦���� ���ؼ� ����� �Ѵ�.
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0) //¦��
			sum += i; //�� ���� ���� ����
	}
	printf("1���� 100������ ¦�� ���� %d�Դϴ�.\n", sum);

	sum = 0;
	//���� 2�� ������Ű�� ���
	for (int i = 2; i <= 100; i += 2)
		sum += i;
	printf("sum=%d\n", sum);

	//continue ����, break�� ���� �򰥷� ��
	//continue�� �ݺ��� ���ᰡ �ƴϰ� ���� �ܰ� ���� �� ���� �ܰ�� �Ѿ�� ��
	sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 != 0)//¦���� �ƴ϶��
			continue; //�ؿ� �ڵ� �����ϰ� i++�� �ٷ� �ǳ� ��
		sum += i; //¦����� i�� ����
	}
	printf("sum=%d\n", sum);


	return 0;
}