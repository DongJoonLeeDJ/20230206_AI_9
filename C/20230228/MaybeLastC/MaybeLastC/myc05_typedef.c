#include<stdio.h>
struct Student {
	char name[100];
	int age;
}typedef Student; //typedef���� �׳� Student�� ���ų� �ٸ� �̸����� �� �ڷ��� ��� ����
int main()
{
	Student sslee;
	strcpy(sslee.name, "�̼���"); 
	sslee.age = 20;
	printf("%s %d\n", sslee.name, sslee.age);
	Student djlee = { "�̵���", 35 }; 
	Student dhshin = { .age = 20, .name = "�ŵ���" }; 
	Student bsSo;
	printf("�̸��� ����?");
	gets(bsSo.name); 
	printf("���̴�?");
	scanf_s("%d", &bsSo.age);
	printf("%s %d\n", sslee.name, sslee.age);
	printf("%s %d\n", djlee.name, djlee.age);
	printf("%s %d\n", dhshin.name, dhshin.age);
	printf("%s %d\n", bsSo.name, bsSo.age);

	return 0;
}