#include<stdio.h>
int main()
{
	system("color ac"); //��� ��濡 ���� ����
	printf("Hello World\n");

	//���ڿ��� �Է��� �޾Ƽ� �׿� �°� ���� �ٲ�� �غ�����.
	//�� �ڿ� �� ���ڸ� �Է��ϸ� ��
	//ex ) ac �Է��ϸ� ��� ��濡 ���� ���� ������ �ϱ�
	char color[1024] = "color";
	//color �ڿ� �� ���ڸ� gets�� �Է¹ް�
	//system(color);�̷��� �϶�� ��
	//����ó���� �غ� ��

	char input[3];
	//2���ڸ� �Է¹ް� �װ� color �ڿ� ���� ��
	while (1)
	{
		printf("���� �Է���\n");
		gets(input);
		int count = 0;
		for (count = 0; input[count] != NULL; count++); //���ڼ� ����
		if (count != 2) //������ 2���ڷ� ǥ���ȴ�.
		{
			printf("���ڼ��� �������ؿ�.");
			continue;
		}
		//1. ������ �迭�� ���� ������ �ű⿡ ���Ե� ������ ��� ���
		//�迭���� 0123456789ABCDEF �̷��� �ִ´�.
		//2. ������ �����ϴ� ����� �ִ�. => �̰ɷ� �غ��ڽ��ϴ�.
		if ((input[0] >= '0' && input[0] <= '9') || (input[0] >= 'A' && input[0] <= 'F')
			|| (input[0] >= 'a' && input[0] <= 'f'))
		{

			if ((input[1] >= '0' && input[1] <= '9') || (input[1] >= 'A' && input[1] <= 'F')
				|| (input[1] >= 'a' && input[1] <= 'f'))
			{
				break;
			}

		}
	}



	color[5] = ' ';
	color[6] = input[0];
	color[7] = input[1];
	color[8] = NULL;
	system(color);


	return 0;
}