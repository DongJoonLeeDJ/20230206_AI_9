#include<stdio.h>
int main()
{
	//4. ���ĺ� A���� Z���� ������ ����ϰ� �Ͻÿ�.(�빮��)
	//hint) ascii�̿�, char�� ���ڷ� �ٷ� ������ �ȴ�
	for (char c = 'A'; c <= 'Z'; c++)
		printf("%c", c);
	printf("\n");
	//5. ���ĺ� a���� a���� ������ ����ϰ� �Ͻÿ�.(�ҹ���)
	for (char c = 'a'; c <= 'z'; c++)
		printf("%c", c);
	printf("\n");
	//6. ���ĺ� A���� z���� ������ ����ϰ� �Ͻÿ�.(��ҹ��� ���)
	for (char c = 'A'; c <= 'z'; c++)
	{
		if(c<='Z' || c>='a')
			printf("%c", c);
	}
	//7. ���� �Է¿� ���� ����� �غ�����.
	printf("\n�� ���� �Է��ϼ���\n");
	int floor;
	scanf_s("%d", &floor);

	//2�Է½� 4��, 3�Է½� 6��, 4�Է½� 8��
	for (int i = 0; i < 2 * floor; i++)
	{
		int onOffSwitch = i;
		for (int j = 0; j < floor; j++)
		{
			if (onOffSwitch % 2 == 0)
				printf("*");
			else
				printf(" ");
			onOffSwitch++;
		}
		printf("\n");
	}

	return 0;
}