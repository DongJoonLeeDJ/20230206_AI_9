#include<stdio.h>
int main()
{
	//while : ~ �ϴ� ���ȿ�
	//for���� ���� �ݺ� Ƚ���� ������ ���� �� ���� ����
	//while���� �ݺ� Ƚ���� ������ ���� ���� �� ���� ����
	while (1) //��ȣ �ȿ� �ִ� ���� ���̸� ��� �����Ѵ�.
	{
		int num;
		printf("���ڸ� �Է��ϼ���.\n");
		scanf_s("%d", &num);
		if (num < 0) //���� �Է��ϸ� �ݺ����� �����ϰ�, �װ� �ƴϸ� �ݺ��� ��� ����
			break;
		printf("%d\n", num * num);

	}
	//printf("num=%d\n", num); //while�� �ۿ��� num�� �� ��. num�� while�� �ȿ��� �����ؼ� �׷���.
	// �� Ư¡�� for, if�� �����ϴ�.
	
	//1���� 100������ �� ���ϱ�
	int sum = 0;
	int i = 0;
	while (i <= 100)
	{
		sum += i;
		i++;
	}
	printf("sum=%d\n", sum);
	return 0;
}