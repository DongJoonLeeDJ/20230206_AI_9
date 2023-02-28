//function ���
//function = ���
//���п����� �Լ� => Ư�� input�� ���� Ư�� output�� ������ ��
//y=f(x)
//f(x) = x+9
//f(11) = 20
//f(x) = 9
//f(x) = x*0 + 9
//f(x) = 0
//Ư���� ���� �޾ƿͼ� �� �Ϳ� ���� ������ �ٸ��� �ϴ� �� 
//=> �ڵ������� ���� �޴� �� ���ų�, ���� �޾Ƶ� �׻� ���� ������ �ϴ� �Լ��鵵 �ִ�.
//�ڵ������� �Լ� : �ڵ� ��ġ, ��� ��ġ, �ڵ� ���, �̸� ���ǵ� ��� ������ �� �� �ִ�.
#include<stdio.h>
//��Ÿ ����� ����
int pita(int a, int b) //�̷������� ���� �� "�Լ�"
{
	return (a * a) + (b * b);
}
int calculator(int a, int b, char c) //����
{
	int result = 0;
	switch (c)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
	case 'x':
	case 'X':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	case '%':
		result = a % b;
		break;
	default:
		printf("%c�� �߸��� �����Դϴ�.\n", c);
		break;
	}
	return result;
}

//���Ϸ��� ��� ������ ����
//F+V-E=2
//F ���� ����
//V �������� ����
//E �𼭸��� ����
//�տ� ���� int�� "��ȯ�� Ȥ�� ������"�̶�� �θ��ϴ�.
//��ȣ �ȿ� �ִ� �͵��� �Ű����� Ȥ�� �Ķ����(parameter) Ȥ�� �ƱԸ�Ʈ(arg)��� �θ��⵵ �մϴ�.
//return�� ��ȯ�� Ȥ�� �������̶�� �θ���.
int isEuler(int F, int V, int E) //���� 3���� ���Ϸ��� ��� ������ �����ϴ� �� ���� üũ
{
	int result = F + V - E;
	if (result == 2)
		return 1;
	else
		return 0;
}

int main() //main = �Լ�
{
	printf("%d\n", pita(3, 4));
	int c = pita(3, 4);
	printf("%d\n", c);
	int a = 3;
	int b = 4;
	c = pita(3, 4);
	printf("%d\n", c);

	int d = calculator(10, 20, '+');
	printf("%d %d\n", d, calculator(20, 10, '-'));
	int n = printf("�ȳ��ϼ���\n");
	printf("%d\n", n);
	printf("%d\n", printf("�ȳ��ϼ���"));


	int result = isEuler(10, 20, 30);//10+20-30 = 0
	if (result)
		printf("���Ϸ����� ����!\n"); //�������� �� ��
	if (isEuler(2, 4, 4))
		printf("Euler ���� �����ؿ�\n"); //�����ϹǷ� ����� �Ѵ�.



	return 0;
}