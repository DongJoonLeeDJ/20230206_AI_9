#pragma once
//위치 저장 자료형을 아래와 같이 만들 수 있다.
struct Pos {
	int x;
	int y;
	int z;
}typedef MyPosition;
//struct Pos p;라고 쓰거나 Position p;이라고 선언하면 됨

//참고로 MyPosition 대신 struct Pos를 써야 하는 경우도 있습니다.(연결리스트나 스택 큐 같은 자료구조
//공부할 때 볼 수 있음)
struct GameCharacter {
	MyPosition p; //또 다른 구조체가 구조체 안에 들어올 수 있다.
	char id[100];
	int level;
}typedef MyPlayer;