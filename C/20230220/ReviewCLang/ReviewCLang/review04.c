#include<stdio.h>
int main()
{
	int input;
	printf("���� ��ȣ �Է��ϼ���\n");
	scanf_s("%d", &input);
	int max = 1; //�� ������ �ִ�
	int count = 0; //������ ī��Ʈ ����. ��� 6�� ����� �� ���´�.
	while (1)
	{
		max = max + (6 * count); //ó���� 1, �״����� 7, �� ������ 19(7+6*2)
		if (max < input)
		{
			count++;
			continue;
		}
		printf("%d ��/�� %d��° ������ ����\n", input, count + 1);
		break;
	}
	return 0;
}