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
	int i = 0;
	//�ѱ��� ������ 2ĭ�� �ǳʶٱ� ���� i�� ���
	//count�� ���ڼ����
	for (i = 0; sentense[i] != NULL; i++,count++) 
	{
		if (sentense[i] < 0) //�ƽ�Ű�� �ƴ� ���
		{
			i++;
			continue;
		}
	}
	printf("%d\n", count);

	return 0;
}
