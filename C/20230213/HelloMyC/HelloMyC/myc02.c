#include<stdio.h>
int main()
{




	//#region ġ�� tabŰ 2�� ������
	//XCode(�ƺ��� C �����ϴ� ���α׷�)���� �� ��
#pragma region first question


	//if(x=0) �̷� �ڵ�� ���� �������� �ʴ� �ڵ�
	//if(x==0) x�� 0�� �� �����ϴ� �ڵ�
	if (0) //���� ������� �ʴ� �ڵ�
	{
		int x, y;
		printf("�� ���� ���ڸ� �Է��ϼ���.\n");
		scanf_s("%d %d", &x, &y);//�� ���� ���ڸ� �Է��� �� �ִ�.
		if (x > 0 && y > 0) //���ǻ���! if, else if, else ���� ; ������ ������.
			printf("1\n");
		else if (x < 0 && y>0)
			printf("2\n");
		else if (x < 0 && y < 0)
			printf("3\n");
		else if (x > 0 && y < 0)
			printf("4\n");
		else
			printf("0\n");

		//�Ȱ��� ����� �ٸ� �ڵ�
		if (x > 0)
		{
			if (y > 0)
				printf("1\n");
			else if (y == 0)
				printf("0\n");
			else
				printf("4\n");
		}
		else if (x == 0)
		{
			printf("0");
		}
		else
		{
			if (y > 0)
				printf("2\n");
			else if (y == 0)
				printf("0\n");
			else
				printf("3\n");
		}
	}


#pragma endregion
	

	if (0)
	{


	printf("���̸� �Է��ϼ���.\n");
	int age;
	scanf_s("%d", &age);
	if (age < 0 || age>200)
		printf("Ÿ�뽺\n");
	else if (age < 20) //age ���� 0���� 19����
		printf("�̼�����\n");
	else if (age < 51) //age���� 20���� 50����
		printf("��ȸ�� �� ������\n");
	else if (age < 71)//age���� 51���� 70����
		printf("������\n");
	else //70���� 200������ 
		printf("������ ������\n");

#pragma region �ι�°����


	printf("���� �Է�");
	//int age;
	scanf_s("%d", &age);
	if (age < 0 || age>200)
		printf("\nŸ�뽺\n");
	else
	{
		if (age < 20)//age�� 0�̻��̶�� �� ������
			printf("\n�̼�����\n");
		else if (age >= 20 && age <= 50)
			printf("\n��ȸ�� �� ������\n");
		else if (age <= 70)//51~70������
			printf("������");
		else if (age >= 71)//else�� ������ �Ǳ� ��
			printf("������ ������");
		//else if�� ������ �ȴ�. ������ else �� �ᵵ ��
	}

#pragma endregion

	}

	int h, m;
	printf("�ð���?\n");
	scanf_s("%d", &h);
	
	//���� �ð��� 24 �̻��� ���� �Է��Ѵٸ�?
	//1. if else
	//2. 24�� ���� �������� ���ϴ� ���
	h = h % 24;
	printf("�� �Է�\n");
	scanf_s("%d", &m);
	if (m >= 60)
	{
		printf("�߸��� ��\n");
	}
	else
	{
		m = m - 45;
		if (m < 0)
		{
			m += 60; //m = m + 60�̶� ������ �ڵ�
			h -= 1; //h = h-1�̶� ������ �ڵ�
			if (h < 0)
				h += 24; // h= h+24�� ������ �ڵ�
		}
		printf("�˶� �ð� : %d�� %d��\n", h, m);
	}
	


	return 0;
}