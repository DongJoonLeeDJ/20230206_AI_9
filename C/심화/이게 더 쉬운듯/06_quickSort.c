#include<stdio.h>

//배열의 a번째와 b번째 값 서로 바꾸는 함수
void swap(int arr[], int a, int b) 
{
	int temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}
//피벗 구하는 함수(핵심)
int partition(int arr[], int left, int right)
{
	int pivot = arr[left]; //일단 left번째를 pivot으로 잡는다.
	int i = left;
	int j = right;
	while (i < j)
	{
		while (pivot < arr[j])  //pivot보다 작은 값이 나올 때 까지 j를 깎는다.(right부분)
			j--;
		while (i < j && pivot >= arr[i]) //pivot보다 큰 값이 나올 때까지 i를 올리고, i가 j보다 같거나 커질때까지
			i++;                         //i를 증가시킴
		swap(arr, i, j);
	}
	arr[left] = arr[j];
	arr[j] = pivot;
	return j; //이렇게 교환을 다 한 뒤의 최종 적인 pivot 위치
}
void quickSort(int arr[], int left, int right)
{
	//left가 right부분보다 작거나 같아지면 더이상 수행 안 함
	if (left >= right)
		return;
	int pi = partition(arr, left, right); //pivot위치선점

	quickSort(arr, left, pi - 1);  //위치 선점한 걸 가지고 다시 quick소트 호출
	quickSort(arr, pi + 1, right); //그러다가 left가 더이상 right보다 작지 않을 때 즉 적어도 left가 right랑 같아지면
}								   //quickSort는 종료되어야 함

int main()
{
	int list[6] = { 30,70,40,20,10,50 };
	int left = 0; //배열 시작 index
	int list_size = (sizeof(list) / sizeof(int));
	int right = list_size - 1; //배열 맨 끝 index

	quickSort(list, left, right); //이걸 계기로 재귀함수가 계속 호출되면서 정렬도미

	for (int i = 0; i < list_size; i++)
		printf("%d\t", list[i]);
	printf("\n");
}