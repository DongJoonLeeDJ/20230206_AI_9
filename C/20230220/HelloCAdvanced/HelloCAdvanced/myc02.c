#include<stdio.h>
int main()
{
	////�迭 = ������

	////�迭 : �ϳ��� ������ ���ؼ� ���� ���� ���ڸ� ������
	////�޸� �󿡼� ���ӵ�(=�پ��ִ�) ��ġ�� �ִ� �������� ����

	//int n[5];
	//printf("%d\n", sizeof(n)); //https://m.blog.naver.com/123gtf/220905979083 // 8
	///*
	//������ ������ 64bit�� ��쿣 �����ͺ������� ũ��� 4����Ʈ�� �ƴϴ�.
	//(64bit�� �����Ϸ����� ������ ������ ũ�Ⱑ 8����Ʈ�̸� , 16bit�� �����Ϸ������� 2����Ʈ�̴�.)
	//C����� ������ ��, �ü���� bit�� �ƴ� �����Ϸ��� bit�� ���� ������ ������ ũ�Ⱑ �޶��� ���� ��ũ :
	//http://stackoverflow.com/questions/16823752/why-size-of-void-pointer-is-4-on-windows-64-bit-platform
	//*/
	//int* p = n;
	//printf("%d\n", sizeof(p));

	//���� ����ִ� ���
	//1. ������ �� ����
	int n2[3] = { 10,1,-1 };
	//2. �ε����� ���� ����
	n2[2] = 100;
	//3. scanf�� �Է�
	//scanf_s("%d", &n2[0]);

	//���
	//sizeof(n2) / sizeof(int) �迭�� ũ���̸�
	//sizeof(n2) / sizeof(n2[0])�̶�� �ص� �Ȱ���
	for (int i = 0; i < sizeof(n2) / sizeof(int); i++)
	{
		printf("%d\n", n2[i]);
	}
	printf("%d", sizeof(n2));







	return 0;
}