#include<stdio.h>
int main()
{
	if (0) //0�� �ǹ� = ����, 0�� �ƴ� ������ �ǹ� = ��
	{		//�� �ڵ��� �ǹ� = �� �߰�ȣ �ȿ� �ִ� �ڵ带 ����� �������� �ʴ´�.

	



	//������ Ǯ���� ���� ���� (�ݺ��Ǵ� ��ȯ ���� 5 4 6 2 3 1)  ���� ���ǹ����� Ǯ�����.
	// 5�� �Է��ϸ� 5 4 6 2 3 1
	// 4�� �Է��ϸ� 4 6 2 3 1 5
	// 1�� �Է��ϸ� 1 5 4 6 2 3


	int input;
	printf("���ڸ� �Է��ϼ���.");

	//scanf�� scanf_s ���� : _s = safe�� �ǹ�, �ֽ� ����, �޸𸮻� ������ �߻��ϴ� �� ������
	//&input �� �� �߸��� ������ ����־ ������ �ּ����� ���� �߸��ٲٸ� ���α׷��� �����ų�
	//ġ������ ������ �߻��� �� �ִ�. �װ� ������ִ� ���� _s�̴�.
	scanf_s("%d", &input);

	//if������ �Է�
	//|| = OR(~�̰ų�) , shift Ű + escape ���� ���� ������ ����
	if (input < 1 || input > 6)
		printf("�߸��� ��\n");
	else //if�� �ִ� ������ �ƴϸ�...
	{
		if (input == 1) //if�� ���� �����ݷ� ������ ����!!!!!! ex) if(input==1); 
			printf("1 5 4 6 2 3\n");
		else if (input == 2)
			printf("2 3 1 5 4 6\n");
		else if (input == 3)
			printf("3 1 5 4 6 2\n");
		else if (input == 4)
			printf("4 6 2 3 1 5\n");
		else if (input == 5)
			printf("5 4 6 2 3 1\n");
		else //����� ���� 6�� ����
			printf("6 2 3 1 5 4\n");
	}

	//switch��
	//case by case�� ����� ���� �� �ٷ� ���ϰ� ������ �� ����.
	//if������ ������ �������� �����ϴ�.
	//� �κп��� ������ ���ڴٰ� �� ���� �����غ��� hint) 3.1�� 3.2 ������ ���� ������?

	switch (input)
	{
	case 1:
		printf("1 5 4 6 2 3\n");
		break;
	case 2:
		printf("2 3 1 5 4 6\n");
		break;
	case 3:
		printf("3 1 5 4 6 2\n");
		break;
	case 4:
		printf("4 6 2 3 1 5\n");
		break;
	case 5:
		printf("5 4 6 2 3 1\n");
		break;
	case 6:
		printf("6 2 3 1 5 4\n");
		break;
	default:
		printf("�߸��� ���Դϴ�.\n");
		break;
	}


	}

	if (0) 
	{
#pragma region study birth season



	//�ּ� : �̷� �������, ��ǻ�Ͱ� �ƴ� ����� �д� ����
	//ctrl k c = �ּ�
	//ctrl k u = �ּ� ����
	//4. ���� �¾ ���� �Է��ϰ�, �� ���� ������ ����ϼ���,
	/*12, 1, 2�� �ܿ��̸� 3, 4, 5�� ��, 6, 7, 8�� ����, 9, 10, 11�� �����̸� �� ���� ���� ���ؼ� ����ó���ϱ�

	(��, if���̶� switch���� ��� ����ؼ� Ǯ�����.)*/

	//if��
	int month;
	printf("�� ���� �¾�̾��?\n");
	scanf_s("%d", &month);
	if (month == 12 || month == 1 || month == 2)
		printf("�ܿ�\n");
	else if (month == 3 || month == 4 || month == 5)
		printf("��\n");
	else if (month >= 6 && month <= 8)
		printf("����\n");
	else if (month >= 9 && month <= 11)
		printf("����\n");
	else
		printf("�߸��� ���Դϴ�.\n");

	switch (month)
	{
	case 12:
	case 1:
	case 2:
		printf("winter is comming\n");
		break;
	case 3:	case 4:	case 5: printf("spring\n"); //�̷��� �� �ٷ� ���� ������. �������� ������
		break;
	case 6:
	case 7:
	case 8:
		printf("summer\n");
		break;
	case 9:
	case 10:
	case 11:
		printf("autumn\n");
		break;
	default:
		printf("wrong month\n");
		break;
	}
#pragma endregion


	}

	if (0)
	{

	printf("�غ� A�� ���� B�� ���̸� �Է��Ͻÿ�.\n");
	int A, B, C; //�̷������� ���� ���� �� �����ϴ� �� �����ؿ�.
	scanf_s("%d %d", &A, &B); //�� ���� 2�� �� �Է�
	C = (A * A) + (B * B);
	printf("%d^2 + %d^2 = %d\n", A, B, C);

	printf("A B�� �Է��ϰ� �׿� �´� �ظ� ���纸����.(C^2 ���� ���߱�)\n");
	//ex) 2 3 13 => 2^2 + 3^2 = 13 => O 2 3 14 => X
	scanf_s("%d %d %d", &A, &B, &C); //�� ���� ���� 3�� �Է��ϴ� ��
	if (((A * A) + (B * B)) == C)
		printf("O\n");
	else
		printf("X\n");

	//��ũ�� + 
	//�� ������ -�� ���
	if (((A * A) + (B * B)) == C)
		printf("O\n");
	else 
	{
		if (((A * A) + (B * B)) < C)
			printf("+\n");
		else
			printf("-\n");
	}

	}

	//6. �丣���� ������ ������ ������ ���Ŀ��� Z^n�� ���� ���Ͻÿ�.
	//('n> 2 �� ��, x�� +y�� =z�� �������� �����ϴ� ���� ���� x, y, z�� �������� �ʴ´�')
	//n�� 3�̶�� �����ϰ� ����
	int x, y;
	printf("x�� y�� ���� �Է��ϼ���.\n");
	scanf_s("%d %d", &x, &y);
	printf("n=3, x=%d, y=%d �� ���, z^3=%d\n", x, y, (x* x* x) + (y * y * y));


	return 0;
}