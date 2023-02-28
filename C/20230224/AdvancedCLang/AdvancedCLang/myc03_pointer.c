#include<stdio.h>
int main()
{
	int a = 100;
	int* pa = &a; //포인터 표기는 아래 세 가지를 쓸 수 있다.
	int *pa2 = pa; //int*, int *변수, int * 변수 이렇게 세 가지 모둥 사용 가능함.
	int * pa3 = pa;

	double pi = 3.14;
	double* ppi = &pi;

	//다중 포인터
	int** ptr_ptr_a = &pa; //포인터의 주소를 저장할 수 있다.
	//이런식으로 2중 이상의 포인터를 다중포인터라고 함
	//3중 4중 5중.... 255중까지 가능한 것으로 알고 있음.

	int numbers[5] = { 11,21,31,41,51 };
	int mul[3][2] = { {3, 4}, {1,11}, {99,22} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%d\n", mul[i][j]);
	}

	//2차원 선언하고 2x1의 값부터 9x9까지의 값을 2차원 배열에 모두 담아보세요.
	int gugu[8][9];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
			gugu[i][j] = (i + 2) * (j + 1);
	}
	//그 배열에 있는 것들을 출력해보세요.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d\t",gugu[i][j]);
		printf("\n");
	}
	//그 배열에 있는 것들을 전부 다 더해서 그 결과를 출력해보세요.
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
			sum += gugu[i][j];
	}
	printf("총 합 : %d\n", sum); //총 합 : 1980
	//3차원, 4차원, 5차원 등의 배열은 만들 수 있는지 생각해보세요.
	//되는지 안 되는지 이유도 같이 생각해보세요.

	//됩니다.
	int arr1[3]; //3칸 짜리 1차원 배열 
	int arr2[3][4]; //4칸짜리 1차원 배열 3개인 2차원 배열
	int arr3[3][4][5]; //5칸짜리 1차원 배열 4개인 2차원 배열 3개인 3차원
	int arr4[3][4][5][6];//6칸짜리 1차원 배열 5개인 2차원 배열 4개인 3차원 배열 3개인 4차원 배열
	//7칸짜리 1차원 배열 6개인 2차원 배열 5개인 3차원 배열 4개인 4차원 배열 3개인 5차원 배열
	int arr5[3][4][5][6][7];


	//포인터로 2차원 배열은 어떻게 가리킬까?
	//int** nptr 이렇게 하는 거 아님
	int(*nptr)[9] = gugu;//9칸짜리 1차원 배열을 가리키는 포인터
	//gugu : 9칸짜리 1차원 배열 8개있는 2차원 배열
	//nptr이랑 gugu랑 둘 다 2차원 메모리의 시작 위치를 가리킨다.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d\t", nptr[i][j]); //그 위치를 하나씩 더해가면서 배열에 있는 내용 출력 가능
		printf("\n");
	}

	printf("%d\n", **gugu); //2 (gugu의 시작 위치 = gugu[0][0])
	printf("%d\n", **(gugu+1)); //3 gugu[1][0]
	printf("%d\n", *(*gugu+1)); //4 gugu[0][1]
	printf("%d\n", *(*gugu+10)); //6 => 컴퓨터는 기본적으로 1차원이다. 시작으로부터 10칸 뒤에꺼
	//2 4 6 8 10 12 14 16 18 3 6 따라서 6이 출력됨
	printf("%d\n", **nptr);//2 (gugu의 시작 위치 = gugu[0][0])
	printf("%d\n", **(nptr + 1)); //3
	printf("%d\n", *(*nptr + 1)); //4
	printf("%d\n", *(*nptr + 10)); //6

	//sizeof를 활용하여 배열 크기 구하기
	printf("2차원이나 그 이상 배열의 사이즈를 구하는 방법\n");
	printf("%d %d\n", sizeof(gugu) / sizeof(gugu[0]), sizeof(gugu[0]) / sizeof(gugu[0][0]));
	printf("2차원배열의 전체크기, 2차원 배열의 1차원 배열 한 개의 크기, 한 칸의 크기\n");
	printf("%d %d %d\n",
		sizeof(gugu), sizeof(gugu[0]), sizeof(gugu[0][0]));

	int row = sizeof(gugu) / sizeof(gugu[0]); //행
	int col = sizeof(gugu[0]) / sizeof(gugu[0][0]);//열
	printf("행=%d, 열=%d\n", row, col); //8 9 
	

	return 0;
}