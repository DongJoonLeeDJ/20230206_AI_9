#include<stdio.h>
int main()
{
	char name[100];//�̸�
	int age;//����
	char bType[100]; //������
	printf("�̸���?\n");
	gets(name);
	printf("���̴�?\n");
	scanf_s("%d", &age);//visual studio�� �Լ�, _s�� �޸� �����÷ο� ����
	rewind(stdin);//����ó���ϴ� ����. ������ ���ڳ� ����(1����)�� �Է��� ���
	//����Ű�� ���ۿ� ���� �ִ�. �� �Ͷ����� �� ������ �Է��� ���ڿ� \n�� �������Ƿ�
	//�̸� �����ϱ� ���� ���
	printf("��������?\n");
	gets(bType);
	printf("%s %d %s\n", name, age, bType);

	
	//�̰� �� ��
	//�����Ҵ� ����� ��
	//�����ð��� �� �� ���̰�, ������ �����Ͻðų�
	//���߿� java�� c#�� �� ����ص帱 ��
	//int size = 100;
	//int mynum[size]; 

	return 0;
}