#include<stdio.h>
//#include<string.h> //c99 Ȥ�� �ƺϻ���ڴ� �� ��� ���� �߰��ؾ� ��
// ���� ����ڴ� �̰� �߰��ϸ� sdl �˻� ���ų� strcpy_s�� ����� �Ф�

//������ ������ ������ �ƴϰ�, ����ڰ� ���� ������ �ڷ����� ����� �� �ִ�.
//����, ����, �Ǽ������� �����͸� �����ϱ� ��ư�, �ϳ��� �ڷ����� �������� ���� ����
//�ϰ� ���� �� ����ϴ� ���� �ٷ� ����ü�Դϴ�.
//(struct, java���� class�� �ְ� c++�� c#���� ����ü, Ŭ���� �� �� ����)
struct Student {
	char name[100];
	int age;
};
int main()
{
	struct Student sslee;
	strcpy(sslee.name,"�̼���" ); //���� �ϰ� ���ڿ� ������� �� strcpy�̿��ؾ� ��
	sslee.age = 20;
	printf("%s %d\n", sslee.name, sslee.age);
	struct Student djlee = { "�̵���", 35 }; //����� ���ÿ� ���ڿ� �ֱ� ����
	struct Student dhshin = { .age = 20, .name = "�ŵ���" }; //�Ӽ� ���� ����
	struct Student bsSo;
	printf("�̸��� ����?");
	gets(bsSo.name); //�������� �Է¹ް� �ϴ� �͵� ����
	printf("���̴�?");
	scanf_s("%d", &bsSo.age);
	printf("%s %d\n", sslee.name, sslee.age);
	printf("%s %d\n", djlee.name, djlee.age);
	printf("%s %d\n", dhshin.name, dhshin.age);
	printf("%s %d\n", bsSo.name, bsSo.age);

	return 0;
}