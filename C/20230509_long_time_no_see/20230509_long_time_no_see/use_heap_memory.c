#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("배열의 크기는?");
	int size;
	scanf_s("%d", &size);
	int* myheapArr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		scanf_s("%d", &myheapArr[i]);
		//scanf_s("%d", myheapArr + i);
	for (int i = 0; i < size; i++)
		printf("%d\n", (myheapArr[i]));
		//printf("%d\n", *(myheapArr+i));
	return 0;
}