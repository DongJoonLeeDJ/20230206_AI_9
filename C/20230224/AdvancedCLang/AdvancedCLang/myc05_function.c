//a���� b������ ���� ���ϴ� �Լ��� ���弼��.(�Ű����� a,b)
//a���� b������ �� Ȥ�� ���� ���ϴ� �Լ��� ���弼��.(�Ű����� a,b,c)
//���� c�� + Ȥ�� x Ȥ�� X Ȥ�� *�� ���� �� ���� ���� ���� 0�� �����ϰ� �Ѵ�.
#include<stdio.h>
int sum_a_to_b(int a, int b) //����ó���� �ʿ��ϳ� �׳� �Ѿ
{
	int sum = 0;
	for (int i = a; i <= b; i++)
		sum += i;
	return sum;
}
int calc_a_to_b(int a, int b, char c)
{
	int sum = 0;
	switch (c)
	{
	case '+':
		//for (int i = a; i <= b; i++)
		//	sum += i;
		//sum_a_to_b�� ���� ����������� �Ʒ������� �� �� �ִ�!
		sum = sum_a_to_b(a, b); //�Լ����� �� �ٸ� �Լ� ȣ�� ������!
		break;
	case '*':
	case 'x':
	case 'X':
		sum = 1; //���̹Ƿ� sum�� 1�� �ʱ�ȭ
		for (int i = a; i <= b; i++)
			sum *= i;
		break;
	default:
		sum = 0;
		printf("�߸��� ���� %c\n", c);
		break;
	}

	return sum;

}

int main()
{
	int result = sum_a_to_b(2, 5); //14
	printf("�� : %d\n", result);
	result = calc_a_to_b(2, 5,'x'); //120
	printf("�� : %d\n", result);
	return 0;
}