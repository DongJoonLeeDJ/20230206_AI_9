//2. ����(0~9���� ��)�� �ƴ� �� �Է��ϸ� �ٽ� �Է��ϰ� �ؼ� ��Ե� ���� ����� ���ڸ� ������ �ϱ�
//���� ������ ���� �� ����. �ϴ� ���� '-'��� ���ڸ� ������������ �ߴ�.
#include<stdio.h>
#define MAXSIZE 100
#include<stdbool.h> //true, false�� c������ �� �� �ְ� ��. �׳� #define�� �Ŷ� �Ȱ���...
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
		numbers[i] = c;
		i++;
	}


	//�׳� ����Ű�� ���� �� ����ó���Ͻð� �ñ������� ���ڸ� �ִ� ��� �� ��µǰ� �غ���
	isnum = true;
	numbers[i] = NULL; //�� ������ ����
	if (isnum == true) // if(isnum)
	{
		printf("%s\n", numbers);
	}



	return 0;
}