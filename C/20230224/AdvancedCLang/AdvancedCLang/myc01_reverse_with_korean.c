#include<stdio.h>
int main()
{
	//char a[1024] = "������";
	//char b[1024] = { NULL };
	//b[5] = a[0];
	//b[4] = a[1];
	//b[3] = a[2];
	//b[2] = a[3];
	//b[1] = a[4];
	//b[0] = a[5];
	/*
		�����������K���ȳ�Hello
		�����������K���ȳ�Helloo
		�����������K���ȳ�Hello�H
		�����������K���ȳ�Hello�Ho
		sentense1 = "����������"
		sentense1 = "�����������K���ȳ�Hello�Ho" (Ȥ�� �� �� ���ڿ�)
		"�ȳ��ϼ���? Hello World! �̰��� �׽�Ʈ�Դϴ�."
	*/
	
	char sentense1[1024] = { NULL }; //1024ĭ �迭�� 0�� �� ���� ��
	char sentense2[1024] = { NULL };
	printf("���ڿ�1 �Է��ϼ���.\n");
	gets(sentense1);
	int count = 0;
	for (count = 0; sentense1[count] != NULL; count++);//���ڼ� ����
	int i = 0; //���ʺ��� ���� ����
	int len = count - 1; //���ʺ��� �� ����
	for (i = 0; sentense1[i] != NULL; i++, len--)//i�� ���� len�� ����
	{
		if (sentense1[i] >= 0 && sentense1[i] <= 127) //�ƽ�Ű�ڵ忡 ���Ե� ���
			sentense2[len] = sentense1[i];
		else //�ƽ�Ű�ڵ忡 �ش���� �ʴ� ���, �� 2byte �ϼ��� �ִ� ���
		{
			if (len <= 0) //�̷� ��� �߻��ϱ� ���� �ݺ����� ����Ǳ��ϳ� Ȥ�ó��;� ����ó����
				break;
			sentense2[len - 1] = sentense1[i];
			sentense2[len] = sentense1[i+1];
			i++;
			len--;
		}
	}
	printf("\n%s %s\n", sentense1, sentense2);

	return 0;
}