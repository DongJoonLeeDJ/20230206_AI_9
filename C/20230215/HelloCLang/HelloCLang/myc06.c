#include<stdio.h>
//��ũ�� ���(�� ��° ���)
#define GAWI 0
#define BAWI 1
#define BO 2
//�� ��° ��� = ������ = Enumeration
enum RCP //Rock Scissor Paper 
{
	//RCP�� �̱����̹Ƿ� �ѱ������� ��迭�Ѵ�.
	//���� ���� ��
	SCISSOR, ROCK,PAPPER
};
//enum�� Ư¡
enum MyRCP
{
	ROCK2=1,SCISSOR2,PAPPER2,GUN=5,WOLF,AIR
};
int main()
{
	//0=����, 1=����, 2=��
	//����� �̿��ؼ� �������� ������Ų��.
	//��� 3��
	//ù��° const
	const int ���� = 0;
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
		if (second == GAWI || second == BAWI || second == BO)
		{
			//enum RCP a = ROCK;
			switch (first)
			{
				case SCISSOR: //1P�� ������ �� ���
					printf("1P : ����\n");
					switch (second) //2�� �� �͵�
					{
						case SCISSOR: //2P ����
							printf("2P : ����\n");
							printf("���º�\n");
							break;
						case ROCK: //2P ����
							printf("2P : ����\n");
							printf("1P ��\n");
							break;
						case PAPPER: //2P ��
							printf("2P : ��\n");
							printf("1P ��\n");
							break;
						default:
							break;
					}
					break;
				case ROCK: //1P�� ������ �� ���
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
				case PAPPER: //1P�� ���� �� ���
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