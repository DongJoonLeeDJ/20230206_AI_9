//1. ���ڿ��� ������ ��������
//2. ���ڿ��� ������ ��������(�ѱ۵� ���� �� ��)
#include<stdio.h>
int main()
{
	//�������
	//�׳� ����Ʈ���� �״�� ���� �ȴ�.
	char sentense[1024];
	printf("������ �Է��ϼ���. �ϴ� ��� �սô�.\n");
	gets(sentense);
	int count = 0;
	//�� ���� for���� ���� �Ȱ��� ����...
	//for (count = 0; sentense[count] != NULL; count++);
	for (count = 0; sentense[count] != NULL;  count++)
	{
	}
	printf("%d\n", count);

	return 0;
}
