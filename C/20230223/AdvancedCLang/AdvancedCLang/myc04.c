//���ڿ��� �Է��� �� ��й�ȣ�� �Է��Ѵٰ� �����ϰ� �غ�����.
//- ���ڿ� ��� ���յǾ�� �ϰ� 8���� �̻��̾������ ���
//- ����, ����, Ư������ �����̾�� �ϰ� 8���� �̻��̾������ ����ϸ� Ư�����ڴ� !�� _�� ���
//- ����� �� ���ڼ��� ���� *�� �ٲ㼭 ��� ex) 1234abcd! => *********
#include<stdio.h>
int main()
{
	char password[1024];
	printf("�Է��ϱ�\n");
	gets(password); //��й�ȣ �Է��ϱ�
	int isalpha = -1; //���ĺ� ���� ���� üũ
	int isnum = -1; //���� ���� ���� üũ
	int isgood = -1; //Ư���������� ���� üũ(����ϴ� ���� !�� @)
	int i = 0; //����
	while (1)
	{
		for (i = 0; password[i] != NULL; i++)
		{
			if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z'))
				isalpha = i;
			if (password[i] >= '0' && password[i] <= '9')
				isnum = i;
			if (password[i] == '!' || password[i] == '_')
				isgood = i;
		}
		if (i >= 8 && isalpha != -1 && isnum != -1 && isgood != -1)
			break;
		else
		{
			isalpha = -1;
			isnum = -1;
			isgood = -1;
			printf("�ٽ� �Է�\n");
		}
		gets(password);
	}
	printf("%s\n", password);
	for (i = 0; password[i] != NULL; i++)
		printf("*");
	printf("\n");
	

	return 0;
}