#include<stdio.h>
//���� ���� ��
#define GAWI 0
#define BAWI 1
#define BO 2

//���
#define WIN 'W'
#define DRAW 'D'
#define LOOSE 'L'

int main()
{
	char result = DRAW; //����� �����ϴ� ����
	for (; result != WIN; )//�����, �����θ� ����
	{
		int first, second;
		printf("���� ���� ��! 1p�� 2p ���ÿ� ������!\n");
		scanf_s("%d %d", &first, &second);
		//4. 2�� ������ Ǯ��, 3�� ������ �ϵ� 1p�� 2p�� ���� ������ ���ѵ��� �� ��
		first %= 3; //3���� ���� �������� �̿��� ����, ����, ��
		second %= 3; 
		//���� 100���� �� ����־ 100�� 1�� ���� �� ������ ����.
		if (
			(first != GAWI && first != BAWI && first != BO) ||
			(second != GAWI && second != BAWI && second != BO)
			)
		{
			continue; //�ٽ� ���ư��� ��
		}
		else
		{
			switch (first)
			{
				case GAWI:
					printf("1P : ����\n");
					if (second == BO)
					{
						printf("2P : ��\n");
						result = WIN;
						printf("1P �¸�!!!\n");
					}
					else
					{
						if(second==BAWI)
						{
							printf("2P : ����\n");
							result = LOOSE;
							printf("1P �й�!!!\n");
						}
						else
						{
							printf("2P : ����\n");
							result = DRAW;
							printf("���º�\n");
						}
					}
					break; //for���� ���������� break�� �ƴϰ� switch���� break
				case BAWI:
					printf("1P : ����\n");
					if (second == GAWI)
					{
						printf("2P : ����\n");
						result = WIN;
						printf("1P �¸�!!!\n");
					}
					else
					{
						if (second == BO)
						{
							printf("2P : ��\n");
							result = LOOSE;
							printf("1P �й�!!!\n");
						}
						else
						{
							printf("2P : ����\n");
							result = DRAW;
							printf("���º�\n");
						}
					}
					break;//for���� ���������� break�� �ƴϰ� switch���� break
				case BO:
					printf("1P : ��\n");
					if (second == BAWI)
					{
						printf("2P : ����\n");
						result = WIN;
						printf("1P �¸�!!!\n");
					}
					else
					{
						if (second == GAWI)
						{
							printf("2P : ����\n");
							result = LOOSE;
							printf("1P �й�!!!\n");
						}
						else
						{
							printf("2P : ��\n");
							result = DRAW;
							printf("���º�\n");
						}
					}
					break;//for���� ���������� break�� �ƴϰ� switch���� break
				default:
					break;//for���� ���������� break�� �ƴϰ� switch���� break
			}
		}

	}
	return 0;
}