#include<stdio.h>
#define TRUE 1
#define FALSE 0
int main()
{
	char n[3]; //2����(������,����,Ư������)�� �Է� ����
	n[0] = '0';
	n[1] = 'a';
	n[2] = NULL; //\0
	printf("%s\n", n);
	char n2[3];
	n2[0] = '0';
	n2[1] = 'a';
	n2[2] = '1'; //NULL�� �������� ���ϸ� ��� ������ ���� ���� �����Ⱚ ���
	printf("%s\n", n2);
	char n3[6] = "����"; //�ѱ��� 1���ڴ� 2byte�̹Ƿ� 3���� �̸� �Է½� �ּ� 7byte�Ҵ�
	printf("%s\n", n3);
	char n4[3];
	scanf_s("%s", n4, sizeof(n4)); //scanf�� �Է��� �� ���ڼ��� 3���� �̻��̸� ƨ��
	printf("%s\n", n4);
	rewind(stdin);
	char n5[3];
	gets(n5); //���ڼ��� ���Ƶ� ƨ���� ������
	printf("%s\n", n5); //n5�� ���������� ����Ǵ� �� �� ĭ �� ��ŭ�̴�.
	//��� : NULL(=\0)�� ���� ��ŭ�� ������ Ȯ���ؾ� ��(1ĭ �� �־�� ��)


	//���ڸ� �Է��ϰ� �ϱ�
	char numbers[100];
	printf("�����Է���\n");
	gets(numbers);
	int flag = TRUE; //numbers�� �ִ� ������ ������ ���� �Ǻ�
	for (int i = 0; numbers[i] != NULL; i++)
	{
		if (numbers[i] != '\n' && (numbers[i] < '0' || numbers[i] > '9'))
		{
			flag = FALSE;
			printf("���ڸ� �Է��϶�~\n");
			break;
		}
	}
	//1. ���ڸ� �Է��� ��쿡�� ���� ����� ��µǰ� �غ�����.
	if (flag)
		printf("%s\n", numbers);
	return 0;
}