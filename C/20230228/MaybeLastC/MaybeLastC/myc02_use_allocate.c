#include<stdio.h>
#include<stdlib.h> //���� �޸� �Ҵ��(malloc, calloc ��)
int main()
{
	//�� �ڵ尡 �� �Ǵ� ����
	//�� �� ���� ����(stack, ����)�� �ֱ� ����
	//size���� ���� �ٲ��� �� �� ����, ���� ���ÿ� �޸𸮿� �ö󰡱� ����
	//int size = 10;
	//int nums[size];//�Ŀ� ������� �־�� �մϴ�.

	//heap �޸� ������ Ȱ���ؾ� ��
	//heap������ ���α׷� �����߿� �Ҵ�Ǵ� �޸� ����
	int size;
	printf("�迭 ����?\n");
	scanf_s("%d", &size);
	int* numbers = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		numbers[i] = i + 10;
	for (int i = 0; i < size; i++)
		printf("%d\n", numbers[i]);


	//malloc�� ���������� heap������ �������� �޸𸮸� �Ҵ�
	//������1. ������ �ٸ���.
	int* mynumbers = (int*)calloc(size, sizeof(int)); 
	int* mynumbers2 = (int*)malloc(size* sizeof(int)); 
	//������2. �⺻���� �� �ִ� ���� �ٸ��ϴ�.
	for (int i = 0; i < size; i++)
	{
		printf("calloc[%d] = %d\n", i, mynumbers[i]);
		printf("malloc[%d] = %d\n", i, mynumbers2[i]);
	}


	free(numbers); //����ڰ� ���Ƿ� �Ҵ��� �޸��̹Ƿ� �� �� �Ŀ��� �ݵ�� ����
	//java, c#���� GC(Garbage Collector)��� ���� �ڵ����� �޸� ������

	return 0;
}