//���� ������ �迭 ������ �� ���� �����ͷ� �غ���
//numbers[i]=getchar ��� * ������ �Ἥ ���� ����ֱ�


#include<stdio.h>
#define MAXSIZE 100
#include<stdbool.h>
int main()
{
	char numbers[MAXSIZE];
	int i = 0;
	int isnum = true;
	while (true) //���ѷ��� �ݺ���
	{
		char c = getchar();
		rewind(stdin); //���ۿ� ���� \n�� ����(=���������͸� ù�κ����� �̵�)
		if (c == '-')
			break;
		if (c < '0' || c>'9')
		{
			isnum = false;
			printf("again!\n");
			continue;
		}
		//numbers[i] = c;
		*(numbers + i) = c;
		i++;
	}
	isnum = true;
	//numbers[i] = NULL; //�� ������ ����
	*(numbers + i) = NULL;
	if (isnum == true) // if(isnum)
	{
		printf("%s\n", numbers);
	}
	return 0;
}