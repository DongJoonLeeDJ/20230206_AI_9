//1. �̰� �״�� ����Ѵ�.
//2.���⼭ ��� ���ؼ��� �빮�ڸ� �ҹ��ڷ�, �ҹ��ڸ� �빮�ڷ� �ٲ㼭 ����Ѵ�.
//���ڿ��� �Է��� �� ��й�ȣ�� �Է��Ѵٰ� �����ϰ� �غ�����.
//1. ���ڸ� �Է¹ް� �� ��.  ex) 123a �̷��� �Է¹����� ������ ���, 1234 �̷��� �Է½� ���
//2. ���ڿ� ��� ���յǾ�� �ϰ� 8���� �̻��̾������ ���
//3. ����, ����, Ư������ �����̾�� �ϰ� 8���� �̻��̾������ ����ϸ� Ư�����ڴ� !�� _�� ���
//4. ����� �� ���ڼ��� ���� *�� �ٲ㼭 ��� ex) 1234abcd! => *********
#include<stdio.h>
int main()
{
	char sentense[100];
	printf("���� �Է����ּ���.\n");
	fgets(sentense, sizeof(sentense), stdin); //stdin ����� Ű���� �Է�
	printf("%s\n", sentense);

	for (int i = 0; sentense[i] != NULL; i++)
	{
		char temp = sentense[i];
		if (sentense[i] >= 'A' && sentense[i] <= 'Z')
			printf("%c", temp + ('a' - 'A'));
		else if (sentense[i] >= 'a' && sentense[i] <= 'z')
			printf("%c", temp - ('a' - 'A'));
		else
			printf("%c", temp);
	}
	printf("\n");

	printf("���� �ٽ� �Է���~\n");
	fgets(sentense, sizeof(sentense), stdin);
	printf("%s\n", sentense);
	for (int i = 0; sentense[i] != NULL; i++)
	{
		if ( (sentense[i] >= '0' && sentense[i] <= '9') || sentense[i] == '\n')
		{
		}
		else 
		{
			printf("���ڸ� �Է��϶�!\n");
			break;
		}
	}
	/////////////// �迭 ���� ���� ������ �������ε� �غ� �� *(ptr+i) �̷��� ����
	

	return 0;
}