#include<stdio.h>
int main()
{
	int N, X, Y;
	FIRST:
	printf("N �Է�\n");
	scanf_s("%d", &N);

	if (N < 3)
	{
		printf("�߸��� ��\n");
		goto FIRST;
	}

	int count = 0;
	printf("x, y �Է�\n");
	//����� c���� (�ٸ� ���鵵 �׷�����)
	//������ ���� �� ��ҹ��� �����Ѵ�.
	//�׷��� ��ҹ��� ������ �����ϸ� �򰥸��� �����Ѵ�.
	//�����!!! ���... �빮�ڴ� ��������� ���̴� ����
	//ex) PI=3.14ó�� ������ ��������� ��� �빮�ڸ� ����.
	//��κ� ������ �ҹ�����
	scanf_s("%d %d", &X, &Y);
	int resultX = X;
	int resultY = Y;

�̼���:
	count+=1;//count�� �ϳ� ����
	if (count < N)
	{
		resultX *= X;
		resultY *= Y;
		goto �̼���;
	}
	else
		printf("z^%d = %d\n", N, resultX + resultY);
	


	return 0;
}