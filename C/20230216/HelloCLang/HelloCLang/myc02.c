#include<stdio.h>
int main()
{
	//���ڸ� �Է��ؼ� ������ ��, 3�̶� 5�� ������.
	//�׸��� �ǵ����̸� ���� ���� ����� �Ѵ�.
	//�׸��� 3�̶� 5�� �������� ������ -1�� ����Ѵ�.

	int inputSugar;
	printf("���� �� kg?\n");
	scanf_s("%d", &inputSugar);
	int pack = 0; //���� ��
	for (;;) //���ѷ���
	{
		if (inputSugar % 5 == 0)
		{
			pack += inputSugar / 5;
			printf("%d����\n", pack);
			break;
		}
		inputSugar -= 3; //3kg �ָӴ� �ϳ���ŭ�� ���
		pack++; //�ָӴ� ���� �ϳ� ����
		if (inputSugar < 0)
		{
			printf("-1\n");
			break;
		}
	}
	return 0;
}