//��Ͷ�? �ڱ� �ڽ��� ȣ���ϴ� �Լ�
#include<stdio.h>
void test()
{
	//printf("�ȳ�\n");
	//test(); //test�� test�� ȣ��.
}

//��� �Լ��� �̿��Ͽ� �� ���ϱ�
int sum(int s) //sum�� sum�� ��� ȣ���Ѵ�.
{
	if (s <= 0) //�׷��� s�� 0���ϰ� �Ǵ� �������� �Լ� ȣ�� �� ��
		return 0;
	return s + sum(s - 1); //�̰� �̿��Ͽ� ���� �ϳ��� ���ҽ��Ѱ���
}							//���ϴ� ��
int main()
{
	//test();
	//main();
	printf("%d\n", sum(3));
	return 0;
}