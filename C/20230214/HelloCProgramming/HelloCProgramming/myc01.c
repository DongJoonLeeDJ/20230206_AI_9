#include<stdio.h>
int main()
{
	//1. 안녕하세요 출력 (주석, 따라적지 말 것)
	printf("안녕하세요.\n");
	// \ 의 명칭 : escape 문자(이스케이프 문자)
	//2. "안녕하세요" 출력
	printf("\"안녕하세요\"\n"); // \(역슬래시는 폰트에 따라서 w 모양으로 나옴,//백스페이스 아래나 옆에 있음)
	//3. 1+9의 결과를 출력
	printf("%d\n", 1 + 9); //%d = decimal = 10진수 = 일반 정수
	//4. 1+9의 결과물은 10입니다를 출력, %d를 이용
	printf("1+9=%d\n", 1 + 9);
	//5. 제 혈액형은 RH’+’(혹은 -) 형입니다를 출력하세요. + 부분에 %c를 넣고 자신이 해당하는 문자를 삽입해보세요.
	printf("제 혈액형은 RH'%c'형입니다.\n", '+');

	//문자 : 따옴표로 감싸고, 한 글자 => 'a', 'B'
	//문자열 : 큰따옴표로 감싸고, 한 글자 이상 => "a", "abcd"
	//'가'=>2글자=>2byte

	//bit, byte, 2진수, 10진수
	//c 언어에서는 영어 숫자 특수문자는 1byte
	//한글 한자 등은 2byte로 표현함

	//java에서 char타입은 2byte 이므로 '가'가 성립함
	//다른 언어에서는 'A' 이런 애들도 2byte로 간주함

	//아스키코드랑 유니코드때문이다.
	//6. 저의 이메일은 abcd@defg.com입니다. 를 출력해보세요. 
	//%s = 문자열을 문장 중간에 삽입하는 것
	printf("저의 이메일은 %s@%s입니다.\n", "ldjgood12", "gmail.com");
	//7. 저의 시력은 0.3, 0.5입니다. 를 출력하기 이 때 0.3과 0.5는 %f를 이용하여 출력할 것
	//%f = float = 실수=>소수점이 있는 수
	printf("저의 시력은 %f, %f입니다.\n", 0.3, 0.5);
	printf("저의 시력은 %.1f, %.1f입니다.\n", 0.3, 0.5);

	//정수 실수 문자 문자열.... 다 구분할까요?
	//%d, %f, %c, %s....%v 같은 거 집어넣어서 숫자 문자 문자열 다 넣으면 안 되나?
	//지금은 아니지만 옛날엔 컴퓨터 메모리의 공간이 굉장히 한정적이었다.
	//그래서 데이터의 타입을 정의해줘야 했습니다.
	//그래야지만 메모리 공간 관리가 됐다.

	//변수
	//변수 : 변하는 수
	//컴퓨터에서는 변수가 수 뿐 아니라 문자도 변수에 해당됩니다.

	//정수저장하는 변수 
	//int, short, long long이 있는 데, 통상적으로 많이 쓰이는 건 int
	//4byte, 하나의 정수를 4byte 즉 32bit(4x8=32)에 저장
	//-21억 정도 ~ 21억 정도

	//실수
	//float, double이 있는 데, 여기선 보통 double 을 많이 쓰며 용량은 8byte

	//문자는 char(=1byte)를 쓴다.
	
	//1. 두 개의 수를 입력한 뒤 두 수의 합을 출력
	int num1;
	int num2;
	//ctrl + D : 줄 복사
	// alt + 화살표 위나 아래 : 코드 이동
	printf("첫번째 숫자는?\n");
	scanf_s("%d", &num1);
	printf("두번째 숫자는?\n");
	scanf_s("%d", &num2);
	printf("두 수의 합 : %d\n", num1 + num2);
	printf("두 수의 곱 : %d\n", num1 * num2);
	printf("두 수의 차 : %d\n", num1 - num2);
	// 결과가 음수면 양수로 바꿔서 출력(조건문)
	//삼항연산자(쓰는 사람은 꼭 쓴다), IF문(제일 많이 쓰임), switch문(그다음으로 좀 많이 쓰임) 

	num1 < num2 ? printf("두 수의 차 : %d\n", num2 - num1) : printf("두 수의 차 : %d\n", num1 - num2);

	//4. 두 개의 수를 입력한 뒤 첫번째 수를 두 번째 수로 나눈 나머지 출력
	// %가 나머지를 구하는 기호
	printf("%d 나누기 %d의 나머지는 %d입니다.\n", num1, num2, num1 % num2);
	//5. 두 개의 수를 입력한 뒤 첫번재 수를 두 번째 수로 나눈 몫 출력
	printf("%d 나누기 %d의 몫 %d입니다.\n", num1, num2, num1 / num2);
	//소수점까지 다 출력하려면? 분모나 분자를 실수로 표기해주셔야 합니다.
	printf("1 나누기 3의 결과 %f %f %f\n", 1.0 / 3, 1.0 / 3.0, 1 / 3.0);
	printf("%d/%d=%f\n", num1, num2, (double)num1 / num2); //분자는 원래 정수이나 실수로 강제 형변환됨
	//정수를 실수 포맷에 맞추려고 하면 0.000이 나온다.

	//자신의 이름 이니셜 첫 글자를 입력 및 출력
	//이동준이면 L을 입력하고 L 출력하면 됨
	char first_init;
	printf("당신 이름의 첫글자는?\n");
	rewind(stdin); //버퍼라는 이름의 메모리 공간에 저장된 \n등의 문자를 청소해줌
	//scanf 하면 숫자나 문자를 입력하고 남은 엔터키가 버퍼라는 공간에 남아있다.
	//이걸 청소해주지 않으면 scanf를 만났을 때, 그 엔터키를 문자로 간주해서 char 변수에 들어가버림
	//즉 여기선 first_init 변수에 \n(아스키코드값 10)이 들어가버림
	scanf_s("%c", &first_init, sizeof(char)); //문자 입력은 끝에 sizeof(char)나 1을 붙여줘야 함
	printf("당신 이름의 첫글자는 %c입니다.\n", first_init);

	//2. 대소문자 여부 구별해서 출력해보기(조건문)
	//if = 만약에
	// && = 그리고(AND)
	//&& 양쪽에 있는 조건들이 모두 맞아야 저 괄호 안에 있는 수식이 참(True)
	//if (수식) 여기에서 수식이 참이면 그 밑에 있는 코드를 실행함
	if (first_init >= 'A' && first_init <= 'Z')
		printf("%c는 대문자!\n", first_init);
	else if (first_init >= 'a' && first_init <= 'z')
		printf("%c는 소문자!\n", first_init);
	else
		printf("잘못된 값!!!\n");

	//3. 대소문자 여부 구별한 뒤 반대로 바꿔서 출력하기(조건문)
	if (first_init >= 'A' && first_init <= 'Z')
	{
		first_init +=  ('a' - 'A'); // first_init = first_init + ('a'-'A');
		printf("첫글자 : %c %d", first_init, first_init);
	}
	else if (first_init >= 'a' && first_init <= 'z')
	{
		first_init -= ('a' - 'A'); // first_init = first_init - ('a'-'A');
		printf("첫글자 : %c %d", first_init, first_init);
	}
	else
		printf("잘못된 값!!!\n");


	return 0;				  
}