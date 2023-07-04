#include<stdio.h>
int main()
{
	int a = 3;

	switch (a)
	{
	case 1:
	case 2:
		printf("¤¾¤·");
		break;
	case 3:
		printf("»ï»ï");
	case 4:
		printf("»ç»ç»ç");
		break;
	default:
		break;
	}
	return 0;
}