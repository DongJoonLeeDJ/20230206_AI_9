#include<stdio.h>
int main()
{
	int n, x, y;
	printf("n 입력");
	scanf_s("%d", &n);

	int count = 0;

	printf("x y 입력");
	scanf_s("%d %d", &x, &y);

	int result_x = x;
	int result_y = y;
	A:
	count++;
	if (count < n)
	{
		result_x *= x;
		result_y *= y;
		goto A;
	}
	else
	{
		printf("z^%d = %d\n", n, result_x + result_y);
	}



	return 0;
}