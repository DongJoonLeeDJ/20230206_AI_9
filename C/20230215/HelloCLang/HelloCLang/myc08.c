#include<stdio.h>
int main()
{
	//1���� 100���� ���ϵ� 3�� ����� ���ؼ� ����� ��
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0) //3�� ���
			sum += i; //sum = sum + i;
	}
	printf("3�� ����� ���� ��(1~100) : %d\n", sum);

	 
 
	//1���� n���� ���ϵ� m�� ����� �����ϰ� ���ؼ� ����ϴ� ��
	printf("n,m �Է��ϼ���.\n");
	int n, m;
	scanf_s("%d %d", &n, &m);
	if (n >= 1 && m >= 1) //n�̳� m�� �� �� 1 �̻��� �� �ۿ� ����.
	{
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i % m != 0)
				sum += i;
		}
		printf("��� : %d\n", sum);
	}

	 
	//���� 3. ���ڸ� �Է¹ް� �ش� ���ڿ� ���� ������ ���� ����� 
	//�ϴ� ���α׷��� �ۼ��غ�����.
	//ex) 3 �Է½�
	//*
	//**
	//***
	//5�� �Է�
	//*
	//**
	//***
	//****
	//*****

	printf("�� ���� �װڴ���?\n");
	int floor;
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");

		printf("\n");
	}
	//3�� ������ �ݴ�� ��µǰ� �غ�����.
	//ex) 3 �Է½�
	//  *
	// **
	//***

	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < floor - i - 1; j++)
			printf(" ");
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}