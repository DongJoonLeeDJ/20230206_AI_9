#include<stdio.h>
int main()
{
	int input;
	printf("벌집 번호 입력하세요\n");
	scanf_s("%d", &input);
	int max = 1; //각 벌집의 최댓값
	int count = 0; //임의의 카운트 변수. 얘랑 6의 배수를 잘 섞는다.
	while (1)
	{
		max = max + (6 * count); //처음엔 1, 그다음엔 7, 그 다음엔 19(7+6*2)
		if (max < input)
		{
			count++;
			continue;
		}
		printf("%d 은/는 %d번째 벌집에 속함\n", input, count + 1);
		break;
	}
	return 0;
}