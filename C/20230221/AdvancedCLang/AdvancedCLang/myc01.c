#include<stdio.h>
int main()
{
	//������ = �ּ�
	int a = 100;
	int* pt_a = &a;
	printf("%d\n", *pt_a);
	(*pt_a)++;
	printf("%d\n", pt_a);
	printf("%d\n", a);
	printf("%d\n", *pt_a);






	pt_a++;
	printf("%d\n", pt_a);//???
	printf("%d\n", *pt_a);//???
	//�迭
	int n[5] = { 10,20,30,40,50 };
	int* p = n;
	printf("%d %d\n", p, n);
	for (int i = 0; i < 5; i++)
	{
		printf("%d %d\n", n[i], p[i]);
		printf("%d %d\n", *(n+i), *(p+i));
		printf("-----\n");
	}








	int n2[10];
	for (int i = 0; i < 10; i++)
	{
		n2[i] = i * i * 10;
		printf("%d\n", n2[i]);
	}
	printf("���� 5�� �Է��غ�����.\n");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &n[i]);
	}
	int size = sizeof(n) / sizeof(n[0]); //�迭 ����
	printf("%d\n", size);
	for (int i = 0; i < size; i++)
		printf("%d\n", n[i]);

	//���ڿ�
	char* name1 = "����";
	printf("%s\n", name1);
	//gets(name1); //�Է¹��� �� char*�� �ƴ϶� char name[100] �̷������� ũ�� ������ �迭�� �� ��
	//printf("%s", name1);

	//���ڳ� ���ڸ� �Է¹��� �� ���ۿ� �����ִ� \n�� �����ϱ� ����
	//����� gets�ϰ� ���� gets �� �� �� rewind�� �ʿ����.
	
	rewind(stdin);
	char name[100];
	printf("�̸��� ������?\n");
	gets(name);
	printf("�̸� : %s\n", name);
	char mbti[5];
	printf("mbti?\n");
	gets(mbti);
	printf("%s\n", mbti);

	//���ڿ��� �Է¹޴´�. 
	//1. �̰� �״�� ����Ѵ�.
	//2.���⼭ ��� ���ؼ��� �빮�ڸ� �ҹ��ڷ�, �ҹ��ڸ� �빮�ڷ� �ٲ㼭 ����Ѵ�.

	//���ڿ��� �Է��� �� ��й�ȣ�� �Է��Ѵٰ� �����ϰ� �غ�����.
	//1. ���ڸ� �Է¹ް� �� ��.  ex) 123a �̷��� �Է¹����� ������ ���, 1234 �̷��� �Է½� ���
	//2. ���ڿ� ��� ���յǾ�� �ϰ� 8���� �̻��̾������ ���
	//3. ����, ����, Ư������ �����̾�� �ϰ� 8���� �̻��̾������ ����ϸ� Ư�����ڴ� !�� _�� ���
	//4. ����� �� ���ڼ��� ���� *�� �ٲ㼭 ��� ex) 1234abcd! => *********

	//������ Ǯ���� �ʵ�� �ø��ǾƵ� ������ ���ڿ��� �̿��ؼ� Ǯ�����
	//472x385 = 472x5, 472x8, 472x3, 472x385�� ��� ���ߴ� ������

	return 0;
}