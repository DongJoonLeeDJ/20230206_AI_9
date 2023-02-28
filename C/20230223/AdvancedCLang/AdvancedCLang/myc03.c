#include<stdio.h>
#define MAXSIZE 2048
int main()
{
	char start[MAXSIZE] = "1"; 
	//읽고 말하기 수열의 20번째를 출력할 것
	//그 과정을 보여주기 위해서 1번째부터 다 출력을 할 것
	for (int i = 1; i <= 20; i++)
	{
		printf("%d 번째 : %s\n", i, start);
		char end[MAXSIZE] = { NULL }; //읽고 말함에 있어서 필요한 누적용 저장 공간
		char num = start[0]; //num : 읽는 숫자
		int count = 0; //내가 읽은 문자의 개수
		int k = 0; //end에서 문자를 채워넣을 때 씀(누적용)
		for (int j = 0; start[j] != NULL; j++) //읽어들이는 부분
		{
			if (num != start[j]) // ex 1 2 나 1 1 2 1 에서 1에서 2로 넘어가거나 2에서 1로 넘어갈 때 
			{//값이 바뀔 때
				end[k] = num; //num
				k++;
				end[k] = count + '0'; //num 개수
				k++;
				num = start[j];
				count = 1; //최초로 하나가 등장을 해서 이 조건문으로 들어왔으니 0이 아닌 1로 초기화
			}
			else//값이 같을 때
			{
				count++;
			}
		}
		end[k] = num;
		k++;
		end[k] = count + '0';//글자를 넣기 위함.
		int c = 0;
		//복사 쉽게 하기 strcpy(start, end) 쓰면 됨, 문자열길이는 strlen(start)쓰면 됨...
		for (c = 0; end[c] != NULL; c++)
			start[c] = end[c];
		start[c] = NULL; //끝부분 NULL로 함
	}
}