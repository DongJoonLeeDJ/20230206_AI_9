#include<stdio.h>
int main()
{
	int floor;
	printf("����?\n");
	scanf_s("%d", &floor);
	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < floor - i - 1; j++)
			printf(" "); //���� ����
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*"); //���� ���� 2j+1 (n�� 0���� ����)
		printf("\n");
	}
	for (int i = 0; i < floor - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
			printf(" ");//���� ������ ����
		for (int j = 0; j < (2 * (floor - i - 1)) - 1; j++)
			printf("*"); //���� ���� 2j-1�������� ����
		printf("\n");
	}
	return 0;
}