#include<stdio.h>
int main()
{
	int list[5] = { 9,6,7,3,5 };

	for (int i = 0; i < 5 - 1; i++)
	{
		int indexMin = i; //indeMin => �ּڰ��� �ִ� ��ġ
		//i�� 0�̶��, 0��°�� ���� ���� ������ '����'

		//i+1��°����, ���� �ִ� ������ �� ���غ��� ��
		for (int j = i + 1; j < 5; j++)
		{
			//i��°���� �� ���� ���� ������ �� ���� ��ġ�� ����
			if (list[j] < list[indexMin])
				indexMin = j;
		}
		int temp = list[indexMin]; //�ּڰ��� ��ġ
		list[indexMin] = list[i];
		list[i] = temp; //i��°�� �ּڰ��� �ְ�, �ּڰ� ���� ��ġ�� i��°�� ����
	}

	for (int i = 0; i < 5; i++)
		printf("%d\t", list[i]);
	printf("\n");
	
	return 0;
}