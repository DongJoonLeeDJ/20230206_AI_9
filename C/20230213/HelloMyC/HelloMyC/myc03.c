#include<stdio.h>
int main()
{
	if (0)
	{
		printf("���� ����");
		START: //������ �����̴� �ߺ��� �����϶�
		printf("�ð��� ���� �Է��ϼ���.\n");
		int h, m;
		scanf_s("%d %d", &h, &m);
		if (h < 0 || h>23 || m < 0 || m>60)
		{
			printf("�ٽ� �Է��ϼ���.\n");
			goto START;
		}//1. ������ �κ� �� �������(3�������� ������)
		else
		{
			m -= 45;
			if (m < 0)
			{
				m += 60; //m = m+60
				h -= 1; // h=h-1
				if (h < 0)
					h += 24;
			}
			printf("�˶��� �︮�� �ð� : %d�� %d��\n", h, m);
		}
	
		//2. 1�� ����(��и�)���� x�� y�� 0�� ������ �ٽ� �Է��ϰ� �غ���


		int x, y;
		START2:
		printf("x y��?");
		scanf_s("%d %d", &x, &y);
		if (x == 0 || y == 0)
			goto START2;
		else
			printf("x=%d, y=%d\n", x, y);

	}
	//3. 2�� �������� Ÿ�뽺�� ź���ϴ� ��쿡�� ���̸� �ٽ� �Է��ϰ� �ϱ�
	int m; //���� ���� �ߺ� �� �ȴٰ� �ߴ� �� �ǳ�?
START3:
	printf("���� �Է�");
	scanf_s("%d", &m);
	if (m < 0 || m>200)
	{
		printf("\n���Ǵ�Ƽ ���� Ÿ�뽺\n");
		goto START3;
	}
	printf("���� : %d\n", m);

	return 0;
}