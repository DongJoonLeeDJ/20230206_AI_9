//1. ��� 5���� ���̸� �Է��ϼ���.
//2. 5���� ���̸� ����ϼ���.
//3. 5���� ���� �� ���� ū ���� ã�Ƽ� ����ϼ���.
#include<stdio.h>
#define MAXSIZE 5
int main()
{
	//1. ��� 5���� ���̸� �Է��ϼ���.
	//���� 5���� �� ���� ������, �ϳ��� ������ 5���� ���� ������ �� �ִ�.
	int ages[5]; //ũ�⸦ ���� ���ؾ� �� //Ȥ�� #define(��ũ�λ��)�� ��� �Ѵ�.
	int a[MAXSIZE]; //�̰� �ȴ�.
	

	//int size=5;
	//int ages[size];
	//�̷��Դ� �� �ȴ�. ������ �̿��ؼ� ũ�� �Ҵ��Ϸ���
	//�����Ҵ��ؾ� ��
	//malloc �̶�� ���� �˻��ϰų� chat gpt���� �������.

	//for (int i = 0; i < 5; i++)
	for (int i = 0; i < sizeof(ages) / sizeof(ages[0]); i++)
	{
		printf("���ڸ� �Է��ϼ���\n");
		scanf_s("%d", &ages[i]);
	}
	//2. 5���� ���̸� ����ϼ���.
	for (int i = 0; i < 5; i++)
		printf("%d\n", ages[i]);


	//�� ���� �Է��ϱ�
	printf("���ڸ� �Է��ϼ��� ex) 10 20 30 40 50 �̷��� �Է�\n");
	for (int i = 0; i < sizeof(ages) / sizeof(ages[0]); i++)
	{
	scanf_s("%d", &ages[i]);
	}

	for (int i = 0; i < 5; i++)
		printf("%d\n", ages[i]);


	//3. 5���� ���� �� ���� ū ���� ã�Ƽ� ����ϼ���.
	int max = ages[0];
	for (int i = 1; i < 5; i++)
	{
		if (max < ages[i])
			max = ages[i];
	}
	printf("���� ����� %d���Դϴ�.\n", max);


	return 0;
}