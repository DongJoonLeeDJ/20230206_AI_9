//������ ���� ��
//myc06�� �и��� ��
#include<stdio.h>
#define GAWI 0
#define BAWI 1
#define BO 2
int main()
{
	//0=����, 1=����, 2=��
	//����� �̿��ؼ� �������� ������Ų��.
	//��� 3��
	//ù��° const
	//const�� ���� ����� �´� ��
	//const int�� ��Ȯ�� �ǹ� : ���� ������ �ʴ� ����. ó�� ����ÿ��� ����
	//���ǵǰ� �� ���Ŀ� ���� ��ȭ���� �ʴ� ������� ���� �ȴ�.
	//�׷��� case �ڿ��� �� �� ����.
	const int ���� = 0; //����� �ѱۺ����� �������� �ʴ´�. ���� GAWI��� �� ��
	const int ���� = 1;
	const int �� = 2;

	int first, second; //1p, 2p
	printf("���� ���� ��!(1p)\n");
	scanf_s("%d", &first);
	if (first != ���� && first != ���� && first != ��) //0,1,2���� �������� ����
		printf("�߸��� ��!\n");
	else
	{
		printf("���� ���� ��!(2p)\n");
		scanf_s("%d", &second);
		//second ���� 0, 1, 2 �� �ϳ��� ���
		if (second == ���� || second == ���� || second == ��)
		{
			//enum RCP a = ����;
			switch (first)
			{
				//const�� �̿��ؼ� ���� ����� �� ��
			case GAWI: //#define�� �ų� enum�� �͸� ��.       //1P�� ������ �� ���
				printf("1P : ����\n");
				switch (second) //2�� �� �͵�
				{
				case GAWI: //2P ����
					printf("2P : ����\n");
					printf("���º�\n");
					break;
				case BAWI: //2P ����
					printf("2P : ����\n");
					printf("1P ��\n");
					break;
				case BO: //2P ��
					printf("2P : ��\n");
					printf("1P ��\n");
					break;
				default:
					break;
				}
				break;
			case BAWI: //1P�� ������ �� ���
				printf("1p: ����!\n");
				switch (second)
				{
				case GAWI: //��ũ�� ��� �̿��� ��
					printf("2P ����\n");
					printf("1P ��!\n");
					break;
				case BAWI:
					printf("2P ����\n");
					printf("���º�!\n");
					break;
				case BO:
					printf("2P ��\n");
					printf("1P ��!\n");
					break;
				default:
					break;
				}
				break;
			case BO: //1P�� ���� �� ���
				printf("1P : ��\n");
				switch (second)
				{
				case GAWI: //��ũ�� ��� �̿��� ��
					printf("2P ����\n");
					printf("1P ��!\n");
					break;
				case BAWI:
					printf("2P ����\n");
					printf("1P �¸�!\n");
					break;
				case BO:
					printf("2P ��\n");
					printf("���º�!\n");
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
		else
		{
			printf("������ �� �� �����ϴ�.\n");
		}
	}

	return 0;
}