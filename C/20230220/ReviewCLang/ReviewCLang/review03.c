#include<stdio.h>
int main()
{
	//�ݺ���
	//3��
	//for
	//for(�����;���Ǻ�;������)
	//for(;;) // <- ���ѷ���
	for (int i = 0; i < 10; i++)
	{
		printf("�ȳ��ϼ��� %d��° ����Դϴ�.\n", i + 1);
	}
	//while
	int count = 0;
	while (count < 10)
	{
		printf("%d\n", count + 1);
		count++;
	}
	//do-while
	do
	{
		printf("count���� 10 �̻��̾ �� ���� ����� ���� count=%d\n", count);
	} while (count<10);

	//while�� �̿��ؼ� ������ �ϳ� �ۼ��غ���
	int i = 2;
	int j = 1;
	while (i < 10)
	{
		while (j < 10)
		{
			printf("%d x %d = %d\n", i, j, i * j);
			j++;
		}
		j = 1;
		i++;
	}

	return 0;
}