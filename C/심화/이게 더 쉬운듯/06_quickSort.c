#include<stdio.h>

//�迭�� a��°�� b��° �� ���� �ٲٴ� �Լ�
void swap(int arr[], int a, int b) 
{
	int temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}
//�ǹ� ���ϴ� �Լ�(�ٽ�)
int partition(int arr[], int left, int right)
{
	int pivot = arr[left]; //�ϴ� left��°�� pivot���� ��´�.
	int i = left;
	int j = right;
	while (i < j)
	{
		while (pivot < arr[j])  //pivot���� ���� ���� ���� �� ���� j�� ��´�.(right�κ�)
			j--;
		while (i < j && pivot >= arr[i]) //pivot���� ū ���� ���� ������ i�� �ø���, i�� j���� ���ų� Ŀ��������
			i++;                         //i�� ������Ŵ
		swap(arr, i, j);
	}
	arr[left] = arr[j];
	arr[j] = pivot;
	return j; //�̷��� ��ȯ�� �� �� ���� ���� ���� pivot ��ġ
}
void quickSort(int arr[], int left, int right)
{
	//left�� right�κк��� �۰ų� �������� ���̻� ���� �� ��
	if (left >= right)
		return;
	int pi = partition(arr, left, right); //pivot��ġ����

	quickSort(arr, left, pi - 1);  //��ġ ������ �� ������ �ٽ� quick��Ʈ ȣ��
	quickSort(arr, pi + 1, right); //�׷��ٰ� left�� ���̻� right���� ���� ���� �� �� ��� left�� right�� ��������
}								   //quickSort�� ����Ǿ�� ��

int main()
{
	int list[6] = { 30,70,40,20,10,50 };
	int left = 0; //�迭 ���� index
	int list_size = (sizeof(list) / sizeof(int));
	int right = list_size - 1; //�迭 �� �� index

	quickSort(list, left, right); //�̰� ���� ����Լ��� ��� ȣ��Ǹ鼭 ���ĵ���

	for (int i = 0; i < list_size; i++)
		printf("%d\t", list[i]);
	printf("\n");
}