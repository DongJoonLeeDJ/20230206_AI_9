#include<stdio.h>
#define MAXSIZE 2048
int main()
{
	char start[MAXSIZE] = "1"; 
	//�а� ���ϱ� ������ 20��°�� ����� ��
	//�� ������ �����ֱ� ���ؼ� 1��°���� �� ����� �� ��
	for (int i = 1; i <= 20; i++)
	{
		printf("%d ��° : %s\n", i, start);
		char end[MAXSIZE] = { NULL }; //�а� ���Կ� �־ �ʿ��� ������ ���� ����
		char num = start[0]; //num : �д� ����
		int count = 0; //���� ���� ������ ����
		int k = 0; //end���� ���ڸ� ä������ �� ��(������)
		for (int j = 0; start[j] != NULL; j++) //�о���̴� �κ�
		{
			if (num != start[j]) // ex 1 2 �� 1 1 2 1 ���� 1���� 2�� �Ѿ�ų� 2���� 1�� �Ѿ �� 
			{//���� �ٲ� ��
				end[k] = num; //num
				k++;
				end[k] = count + '0'; //num ����
				k++;
				num = start[j];
				count = 1; //���ʷ� �ϳ��� ������ �ؼ� �� ���ǹ����� �������� 0�� �ƴ� 1�� �ʱ�ȭ
			}
			else//���� ���� ��
			{
				count++;
			}
		}
		end[k] = num;
		k++;
		end[k] = count + '0';//���ڸ� �ֱ� ����.
		int c = 0;
		//���� ���� �ϱ� strcpy(start, end) ���� ��, ���ڿ����̴� strlen(start)���� ��...
		for (c = 0; end[c] != NULL; c++)
			start[c] = end[c];
		start[c] = NULL; //���κ� NULL�� ��
	}
}