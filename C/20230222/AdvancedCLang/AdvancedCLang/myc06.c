//���ڿ��̶� ������... ���� 5�� �Է��ϰ� �� �߿� �ִ�, �ּڰ� ã��
//�� ����  �� �͵��� ���� ���° �ִ��� ã�Ƽ� ����ϼ���
//�� ���� �� Ǯ�� �� �͵鵵 ������ ���� �̿��ϱ�(ó�� �迭 ����ÿ��� ���ȣ����)
#include<stdio.h>
int main()
{
	int num[5];
	//for (int i = 0; i < 5; i++)
	printf("���� 5�� �Է���\n");
	for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++)
	{
		scanf("%d", &num[i]);
	}
	printf("%d %d %d %d %d\n", num[0], num[1], num[2], num[3], num[4]);


	int maxth, minth, max, min;
	maxth = 0;
	minth = 0;
	max = num[0];
	min = num[0];
	for (int i = 0; i < 5; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
			maxth = i;
		}
		if (num[i] < min)
		{
			min = num[i];
			minth = i;
		}
	}
	printf("ū �� : %d, ū ���� �ε��� : [%d], ���� �� : %d, ���� �� �ε��� : [%d]\n",
		max,maxth,min,minth);
	return 0;
}
