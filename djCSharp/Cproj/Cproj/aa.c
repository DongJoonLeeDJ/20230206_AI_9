#include<stdio.h>
int main()
{
	int a = 3;

	switch (a)
	{
	case 1:
	case 2:
		printf("����");
		break;
	case 3:
		printf("���");
	case 4:
		printf("����");
		break;
	default:
		break;
	}
	return 0;
}