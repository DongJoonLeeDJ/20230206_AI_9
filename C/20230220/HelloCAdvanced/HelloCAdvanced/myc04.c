#include<stdio.h>
#define MAXSIZE 1024 //���� ��ũ�� ��� �� �ᵵ ��
int main()
{
	//���ڿ� = ������ �迭
	//�˳��� ũ���� ���� �迭�� �����ؾ�
	//���ڿ��� �Է¹޴� ���� ����
	char a = NULL; //���� a�� b�� �Ȱ��� ���̴�. 
	char b = '\0';

	char name[MAXSIZE];
	char bloodType[100];

	printf("�̸���?\n");
	gets(name);

	printf("��������?\n");
	gets(bloodType);

	printf("%s %s", name, bloodType);


	//�̸�, ����, Ű, ������, mbti�� �����
	//�� ������ ����غ�����.
	printf("�̸���?\n");
	gets(name);
	printf("���̴�?\n");
	int age;
	scanf_s("%d", &age);
	printf("Ű��?\n");
	double cm;
	scanf_s("%lf", &cm);
	//���ڸ� �Է¹ް��� gets�� �� �� rewind�� ����.
	rewind(stdin); //���� û��
	printf("��������?\n");
	gets(bloodType);
	char mbti[5]; //mbti�� 4�����̹Ƿ� �ּ� ũ��� 5��.
	gets(mbti);
	printf("���� %d, Ű %lf, �̸� %s, ������ %s mbti %s\n",
		age,cm,name,bloodType,mbti);

	return 0;
}