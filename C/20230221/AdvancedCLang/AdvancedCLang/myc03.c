#include<stdio.h>
int main()
{
	//문자열을 입력받는다. 
	char message[100];
	printf("문장을 입력해\n");
	scanf("%s", message); //이렇게 하면 띄어쓰기가 짤린다....
	printf("%s", message);
	//fflush(stdin); 
	/*
	* fflush(stdout)은 출력 버퍼 비우기용이라고 하나, fflush(stdin)은 쓰지 말아야 할 것이라고 함....
	* 
	* 
	fflush(stdin)은 C 표준에서는 정의되지 않은 동작이며, 사용하지 말아야 합니다. 따라서 fflush(stdin)의 역할은 정의되어 있지 않습니다.

오히려 fflush(stdin)을 사용하면 예기치 않은 결과를 가져올 수 있습니다. fflush는 출력 버퍼를 비우기 위한 것이므로, 입력 버퍼를 비우는 데는 적합하지 않습니다.

반면에 rewind(stdin)은 stdin 파일 스트림을 파일의 맨 처음으로 되감아 놓습니다. 이는 이전에 읽은 내용을 버리고, 다시 처음부터 읽을 수 있도록 하는 역할을 합니다.

따라서 rewind(stdin)을 사용하면 입력 버퍼를 비우고, 다시 입력을 받을 수 있습니다. 하지만 rewind는 파일 스트림에만 사용할 수 있으므로, 표준 입력 스트림인 stdin에만 적용할 수 있습니다.
	
	*/
	
	while (getchar() != '\n'); //gpt 교수님 방법(표준 C)
	//while (getchar() != '\n') {} //gpt 교수님 방법(표준 C) //(위에꺼랑 같음거임)
	
	//while (getchar() != '\n' || getchar() != ' '); //이렇게 쓰면 스페이스바를 한 칸 치고 또 쳐야 됨

	fgets(message, sizeof(message), stdin);
	printf("%s", message);

	return 0;
}