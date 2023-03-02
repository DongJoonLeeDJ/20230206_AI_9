#include<stdio.h>
int main()
{

	int arr[5] = { 10,5,1,20,7 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 5; i++)
		printf("%d\n", arr[i]);

	return 0;
}