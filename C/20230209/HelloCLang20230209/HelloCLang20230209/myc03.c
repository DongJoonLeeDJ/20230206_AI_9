#include<stdio.h>
int main()
{
	//���ǹ�
	//������ ���� ���� ������ �޶����� ��

	//���� ������
	//�� : �ڵ�
	//���ڸ� �Է��ϰ�, �� ���ڰ� ����̰ų�
	//�ƴ� ��쿡 ���� �ٸ� ����� �ҰԿ�.

	int num;
	printf("���� �Է�");
	scanf_s("%d", &num);
	num > 0 ? printf("���\n") : printf("����ƴ�\n");
	//(�ڵ�) ? (�ڵ尡 ��) : (�ڵ尡 ����);
	printf("%d\n", num > 0);
	printf("%d\n", num < 0);
	printf("%d\n", num == 0);
	printf("%d\n", num = 0);
	printf("%d\n", num == 0);
	printf("%d\n", num != 0); //�ٸ���
	num = 2002;
	num != 2002 ? printf("�����Ÿ𸣳�") : printf("4����ȭ");
	num = 10;
	char c = num == 0 ? '0' : '!'; //c�� ���� �����ϴ� ��,
									//num�� ���� �ٸ���.
	printf("\n%c\n", c);
	return 0;
}