#include<stdio.h>
int main()
{
	int list[5] = { 9,6,7,3,5 };

	for (int i = 0; i < 5 - 1; i++)
	{
		int indexMin = i; //indeMin => 최솟값이 있는 위치
		//i가 0이라면, 0번째를 가장 작은 값으로 '가정'

		//i+1번째부터, 끝에 있는 값까지 다 비교해보는 것
		for (int j = i + 1; j < 5; j++)
		{
			//i번째보다 더 작은 값이 있으면 그 값의 위치를 저장
			if (list[j] < list[indexMin])
				indexMin = j;
		}
		int temp = list[indexMin]; //최솟값의 위치
		list[indexMin] = list[i];
		list[i] = temp; //i번째에 최솟값을 넣고, 최솟값 원래 위치에 i번째값 넣음
	}

	for (int i = 0; i < 5; i++)
		printf("%d\t", list[i]);
	printf("\n");
	
	return 0;
}