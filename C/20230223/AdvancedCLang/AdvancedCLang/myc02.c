#include<stdio.h>
#define MAXSIZE 1024
int main()
{
	char input[MAXSIZE] = { NULL, };
	int checkAlphabet[26];
	for (int i = 0; i < 26; i++)
		checkAlphabet[i] = -1;//int checkAlphabet[26] = { -1, };�̰� �� �Ǽ� for�� ��
	printf("���ڿ��� �Է��ϼ���\n");
	gets(input);
	for (int i = 0; input[i] != NULL; i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
			input[i] += ('a' - 'A');
		if (input[i] < 'a' || input[i] >'z')
			return 0;
		if (checkAlphabet[input[i] - 'a'] == -1)
			checkAlphabet[input[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
	{
		if (checkAlphabet[i] != -1)
			printf("%c�� [%d]���� ó�� ����\n", 'a' + i, checkAlphabet[i]);
	}

	return 0;
}