#include<stdio.h>
int main()
{
	//4. ���ڸ� �Է¹ް� �Ʒ��� ���� ����Ѵ�.(�� 3600 �̸����� �Է��Ѵٰ� �����Ѵ�.)
	//123 = > 2�� 3��
	printf("�� ��?");
	int sec;
	scanf_s("%d", &sec);
	printf("%d��%d��\n", sec / 60, sec % 60);
	//5. �ڽ��� ��� ����(+ - 0 �� �ϳ�),  
	//Ű, ���� �̷� �������� �Է¹ް�, ���
	char myfeel;
	int cm, age;
	//���� �Է��ϱ� ��... rewind!
	rewind(stdin);
	printf("����� ���?(+ - 0 �� �ϳ�)");
	myfeel = getchar();//scanf_s("%c",&myfeel,1);
	printf("Ű�� ���� ���ϼ���.(���ÿ�)");
	scanf_s("%d %d", &cm, &age); 
	printf("��� : %c, ���� : %d, Ű : %d\n", myfeel, age, cm);
	
	printf("���, Ű, ���� �� ���� �Է��غ�����.");
	rewind(stdin);
	scanf_s("%c %d %d", &myfeel, 1, &age, &cm); //myfeel�� ���ؼ� 1byte�Ҵ�
	printf("%c %d %d\n", myfeel, age, cm);


	return 0;
}