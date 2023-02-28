#include<stdio.h>
int main()
{
	//숫자를 입력해서 나누는 데, 3이랑 5로 나눈다.
	//그리고 되도록이면 몫의 숫자 적어야 한다.
	//그리고 3이랑 5로 나눠지지 않으면 -1을 출력한다.

	int inputSugar;
	printf("설탕 몇 kg?\n");
	scanf_s("%d", &inputSugar);
	int pack = 0; //묶음 수
	for (;;) //무한루프
	{
		if (inputSugar % 5 == 0)
		{
			pack += inputSugar / 5;
			printf("%d묶음\n", pack);
			break;
		}
		inputSugar -= 3; //3kg 주머니 하나만큼을 덜어감
		pack++; //주머니 개수 하나 증가
		if (inputSugar < 0)
		{
			printf("-1\n");
			break;
		}
	}
	return 0;
}