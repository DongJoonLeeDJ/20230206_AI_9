#include<stdio.h>
int main()
{
	char sentense1[1024] = { NULL };
	char sentense2[1024] = { NULL };
	printf("�Է��ϼ���\n");
	gets(sentense1);
	int count = 0;
	for (count = 0; sentense1[count] != NULL; count++);//���� ���ϱ�(strlen �����, byte����)
	int i = 0; //sentense2�� �ε���
	int len = count; //����(sentense1�� �ε���)
	for (i = 0; i <= count; i++, len--) //i�� ����, len�� �����ذ��� ���� �ϳ��� �߰�
	{
		if (len == 0)
		{
			sentense2[i] = NULL; //�� ���� ���� ���κп� NULL�� �ְ� ����
			break;
		}
		sentense2[i] = sentense1[len - 1];
	}
	printf("%s %s\n", sentense1, sentense2);
	return 0;
}