#include<stdio.h>
struct Student {
	char name[100];
	int age;
}typedef Student; //typedef쓰면 그냥 Student만 쓰거나 다른 이름으로 이 자료형 사용 가능
int main()
{
	Student sslee;
	strcpy(sslee.name, "이수성"); 
	sslee.age = 20;
	printf("%s %d\n", sslee.name, sslee.age);
	Student djlee = { "이동준", 35 }; 
	Student dhshin = { .age = 20, .name = "신동훈" }; 
	Student bsSo;
	printf("이름이 뭐야?");
	gets(bsSo.name); 
	printf("나이는?");
	scanf_s("%d", &bsSo.age);
	printf("%s %d\n", sslee.name, sslee.age);
	printf("%s %d\n", djlee.name, djlee.age);
	printf("%s %d\n", dhshin.name, dhshin.age);
	printf("%s %d\n", bsSo.name, bsSo.age);

	return 0;
}