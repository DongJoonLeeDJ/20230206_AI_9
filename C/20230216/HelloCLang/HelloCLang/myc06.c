#include<stdio.h>
int main()
{
	//�Ƕ�̵�
	//���� ������ 1 3 5 7 9 �̷� ����
	int floor;
	printf("�� ��?\n");
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < floor - i - 1; j++) //���� ���� ������ �پ��
			printf(" ");
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*");//2j+1 j�� 0���� �����ϴ� ���� ����
		printf("\n");
	}

	return 0;
}