#include<stdio.h>
#define MAXSIZE 1024
int main()
{
	char input[MAXSIZE] = { NULL, }; //input�� ���� 0�� �������
	//�̰� �� �ϸ� ������ ��(=������ ��)�� ��
	printf("������ �Է��ϼ���.\n");
	gets(input);
	//a~z���� 26���̹Ƿ� 26ĭ¥�� ���� �迭�� Ȱ���� ��
	int checkAlphabet[26] = { 0 }; //�� �迭�� ���� 0�� ��
	for (int i = 0; input[i] != NULL; i++)
	{
		if (input[i] >= 'A' && input[i] <='Z')
			input[i] += ('a' - 'A');
		if (input[i] < 'a' || input[i] > 'z')
			return 0; //���α׷� ����
		checkAlphabet[input[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (checkAlphabet[i] != 0)
			printf("%s���� %c�� %d���ڳ��ɴϴ�.\n", input, 'a' + i, checkAlphabet[i]);
	}
	return 0;//���α׷� ����
}