#include<stdio.h>
int main()
{
	//�̸�, ����, ������ �Է¹ް� ����غ���
	char name[100]; //ũ��� �˳��ϰ� ��ų�
	//���� ������ �ϴ� ũ��+1��ŭ ���
	//���� �̸��� ������ 3���ڶ�� name[7]�̶�� ��ƾ� ��
	//�ѱ��� 1���ڴ� 2byte�̰� ���ڿ� ���� �ݵ�� 1����(=NULL)��
	//�ڵ����� ���� �����̴�.
	int age;
	char bType[100];

	printf("�̸��� ������?\n");
	fgets(name, sizeof(name), stdin); //���ڿ� �Է�
	for (int i = 0; name[i] != '\0'; i++)
	{
		if (name[i] == '\n')
		{
			name[i] = NULL;
			break;
		}
	}
	printf("���̰� ����ΰ���?\n");
	scanf("%d", &age); //scanf_s�� visual studio���̰� ǥ���� �ƴϴ�.
	//������Ʈ ���콺 ������ Ŭ�� -> c/c++ -> �Ϲ� -> sdl �˻縦 ����.
	printf("�������� ������?\n");
	//char q = getchar(); 
	//scanf("%c", &q);
	while (getchar() != '\n')
	{

	}
	fgets(bType, sizeof(bType), stdin);
	printf("�̸� : %s, ���� : %d, ������ : %s\n",
		name,age,bType);


	return 0;
}