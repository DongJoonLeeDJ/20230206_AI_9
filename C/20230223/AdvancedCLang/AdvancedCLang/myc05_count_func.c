#include<stdio.h>
//#include<string.h> //strlen �� �� �ʿ��ϳ� ��� �� ���� ����
#include<mbstring.h> //_mbslen ������ �ݵ�� �ʿ�
int main()
{
	char sentense[1024] = { 0 };
	printf("���� �Է��ϼ���\n");
	gets(sentense);
	printf("%d %d\n", strlen(sentense), _mbslen(sentense));
	//strlen ����Ʈ �� ���
	//_mbslen : ���ڼ��� ���
}