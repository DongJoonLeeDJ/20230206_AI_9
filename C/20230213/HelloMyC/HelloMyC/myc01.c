#include<stdio.h>
int main()
{
	//���� ����, ���� �¾ ����, ���� ��, ���� �¾ ��
	int thisYear, birthYear, thisMonth, birthMonth;
	printf("���翬��, ���� �¾ ����, ���� ��, ���� �¾ �� �Է�\n");
	scanf_s("%d %d %d %d", &thisYear, &birthYear, &thisMonth, &birthMonth);
	int gapYear = thisYear - birthYear; //2023-1989 = 34
	
	//�ڵ� ǥ���
	//1. ������ũ ǥ��� : �ܾ�� �ܾ� ���̿� ����(underbar, _)�� ����.
	//ex) int this_year
	//2. ī�� ǥ��� : camel(��Ÿ) ��� ǥ���
	//ex) int thisYear �̷��� ����. thisyear �̷��� ���� �������� ��������.

	//���� ǥ���� �߿��� ��Ģ
	//���ڸ� ���� ù��°�� �� �� ����. ex) int 1, int 1Year; �̷��� �� �� ����
	// ��, �ڿ� ���� �� �󸶵��� ���� ex) int Year1, Year2;
	//���鵵 �Ұ����ϸ� ���Ǵ� Ư�����ڴ� _(����)�̴�. 
	//�ǵ����̸� �������� ����� �����. �ѱ��̳� �ٸ� �� �Ǳ� 
	//������ �׷��� ��� ���� �Ϲ���

	if (gapYear < 0)
	{
		printf("�� ���� �߸��ƽ��ϴ�\n");
	}
	else
	{
		int month = gapYear * 12; //34�� ���Դٸ� 34*12 = 408
		int myMonth = month + thisMonth - birthMonth;
		printf("����� ���� %d�����Դϴ�.\n", myMonth);
	}


	return 0;
}