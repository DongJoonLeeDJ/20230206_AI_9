//������ Ǯ���� �ʵ�� �ø��ǾƵ� ������ ���ڿ��� �̿��ؼ� Ǯ�����
//472x385 = 472x5, 472x8, 472x3, 472x385�� ��� ���ߴ� ������
//ù��° �� x �ι�° ���� ���� �ڸ� = ���� �ڸ� = �� ��° �ڸ� = [2]
//ù��° �� x �ι�° ���� ���� �ڸ� = ���� �ڸ� = �� ��° �ڸ� = [1]
//ù��° �� x �ι�° ���� ���� �ڸ� = ���� �ڸ� = ù ��° �ڸ� = [0]

#include<stdio.h>
#include<stdlib.h>  //atoi ��� �Լ��� ���� ����, �̰� �� �ᵵ �Ǳ� ��

int main()
{
	printf("ù ��° ���� �Է�\n");
	char num1[4];
	scanf_s("%s", num1, 4); //�� �Ͱ� gets�� ���̴� �����մϴ�. ����(space bar)ó���� �ٸ�
	printf("�� ��° ���� �Է�\n");
	char num2[4];
	scanf_s("%s", num2, 4);
	//'0'�� 48�̴�.
	printf("ù��° �� : %s, �ι�° ��:%s\n", num1, num2);
	printf("%d %d %d %d\n",  
		atoi(num1) * (num2[2]-'0'),
		atoi(num1) * (num2[1] - '0'),
		atoi(num1) * (num2[0] - '0'),
		atoi(num1) * atoi(num2));

	int mynum1 = (100 * num1[0]) + (10 * num1[1]) + (num1[2]);//Ʋ�� �ڵ�
	printf("%d\n", mynum1);
	mynum1 = (100 * (num1[0]-'0')) + (10 * (num1[1]-'0')) + ((num1[2]-'0')); //�´� �ڵ�
	printf("%d\n", mynum1);
	int mynum2 = (100 * (num2[0] - '0')) + (10 * (num2[1] - '0')) + ((num2[2] - '0'));

	printf("\n%d %d %d %d\n", 
		mynum1*(num2[0]-'0'), mynum1 * (num2[1] - '0'), mynum1 * (num2[2] - '0'),
		mynum1*mynum2);

	//����
	//���� �Է��� ���ڿ��� �ϳ��ϳ� � �� �� �ִ� ���
	for (int i = 0; num1[i] != NULL; i++)
		printf("%c %d\n", num1[i], num1[i]);

	//scanf�� �̿��ؼ� ���ڿ� �Է��ϴ� �Ŷ� gets�̿��ϴ� ����� ����
	//���� ó���� �ٸ���.

	rewind(stdin);
	char ex[100];
	gets(ex); //fgets�� �������̱� �ϳ� gets�ε� ���ư���.
	printf("%s", ex);
	rewind(stdin);
	scanf_s("%s", &ex, sizeof(ex));
	printf("%s", ex); //scanf_s ���� space bar�� \n�� �������� �ڸ���.
	//�� ���� ���Ե� ���ڿ� �Է� �� ��½ÿ��� scanf_s�� ���� �ʴ� �� ����.

	return 0;
}

