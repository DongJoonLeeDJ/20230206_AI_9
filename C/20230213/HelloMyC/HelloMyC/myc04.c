#include<stdio.h>
int main()
{
	//����� ���� ���� �� �����ϰ� ���� ��
	//���� ���� �ٷ� switch��
	//if else if else if else if else �̷��� ���°ͺ���
	//����� ���� �� �� ���̰� �� �����غ��δ�.

	int dice;
	printf("�ֻ��� ���� ����������.\n");
	scanf_s("%d", &dice);
	if (dice == 1)
		printf("���� �ϳ� �Դϴ�.\n");
	else if (dice == 2)
		printf("���� �� �Դϴ�.\n");
	else if (dice == 3)
		printf("���� �� �Դϴ�.\n");
	else if (dice == 4 || dice == 5 || dice == 6)
		printf("���� ���̻��� �ƴ�\n");
	else
		printf("�̻��� ��\n");

	switch (dice)
	{
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
	case 5:
	case 6:
		printf("���̻��� �ƴ�");
		break;
	default:
		printf("%d�� �߸��� ��\n", dice);
		break;
	}

	return 0;
}