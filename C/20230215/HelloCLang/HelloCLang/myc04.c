#include<stdio.h>
int main()
{
	int num=1;
	//�ʱ�ȭ �ϴ� �κ��̶� �����κ��� ������
	//�ֳĸ� �ʿ�����ϱ� �����ƴ�.
	//��� ���Ǻ� �κи� ���.
	//num���� 0�� �ƴϸ� scanf, printf�� ����ϸ�, 0�̸� �ݺ����� ���ᰡ ��
	for (; num != 0; )
	{
		printf("���� �Է��ϼ���.\n");
		scanf_s("%d", &num);
		printf("%d\n", num * num);

	}

	//break���̶�� �� ����?
	//break���� ��� �����Ű�� ��
	//ex) ���� �Է��ؼ� 0�� �ƴϸ� ���� ���, 0�̸� ��� ����
	for (num = 1; /*num != 0*/;)
	{
		printf("�� �Է�\n");
		scanf_s("%d", &num);
		//for���� ���� �ݺ��� ���ʿ� ���ǹ��� �߰��� �� �ִ�.
		if (num == 0)
			break; //break�� �뵵�� switch�� break�� ����. "���������� ��"
		printf("%d\n", num * num);
	}

	return 0;
}