//2. 숫자(0~9사의 수)가 아닌 걸 입력하면 다시 입력하게 해서 어떻게든 최종 결과는 숫자만 나오게 하기
//종료 조건을 지정 안 했음. 일단 저는 '-'라는 글자를 종료조건으로 했다.
#include<stdio.h>
#define MAXSIZE 100
#include<stdbool.h> //true, false를 c에서도 쓸 수 있게 함. 그냥 #define한 거랑 똑같음...
int main()
{
	char numbers[MAXSIZE];
	int i = 0;
	int isnum = true;
	while (true) //무한루프 반복문
	{
		char c = getchar();
		rewind(stdin); //버퍼에 남은 \n을 제거(=파일포인터를 첫부분으로 이동)
		if (c == '-')
			break;
		if (c < '0' || c>'9')
		{
			isnum = false;
			printf("again!\n");
			continue;
		}
		numbers[i] = c;
		i++;
	}


	//그냥 엔터키만 쳤을 때 예외처리하시고 궁극적으로 숫자만 있는 경우 다 출력되게 해보기
	isnum = true;
	numbers[i] = NULL; //끝 마무리 짓기
	if (isnum == true) // if(isnum)
	{
		printf("%s\n", numbers);
	}



	return 0;
}