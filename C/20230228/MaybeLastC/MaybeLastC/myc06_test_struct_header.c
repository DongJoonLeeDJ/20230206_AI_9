#include<stdio.h>
#include"Position.h" //Position이라는 자료형과 Player라는 자료형을 담고 있다.
int main()
{
	MyPosition p1 = { .x = 10, .y = 20, .z = 30 }; //typedef 뒤에 있는 걸 써도 되고
	struct Pos p2 = { 10,20,30 };//원래 이름을 써도 된다. 
	//사용자 정의 자료형 안에 또 다른 사용자 정의 자료형이 "속성"으로 들어갈 수 있다.
	//Postion의 속성은 3개:x,y,z 이고 Player의 속성은 3개 : id, level, Position
	struct GameCharacter player1 = { .id = "핑크공주이동준", .level = 100, .p = p1 };
	MyPlayer player2 = { .id = "남자는핑크", .level = 255, .p = p2 };

	printf("%s %d %d %d %d\n", player1.id, player1.level, player1.p.x, player1.p.y, player1.p.z);
	printf("%s %d %d %d %d\n", player2.id, player2.level, player2.p.x, player2.p.y, player2.p.z);
	return 0;
}