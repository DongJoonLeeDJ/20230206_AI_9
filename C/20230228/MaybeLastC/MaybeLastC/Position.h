#pragma once
//��ġ ���� �ڷ����� �Ʒ��� ���� ���� �� �ִ�.
struct Pos {
	int x;
	int y;
	int z;
}typedef MyPosition;
//struct Pos p;��� ���ų� Position p;�̶�� �����ϸ� ��

//����� MyPosition ��� struct Pos�� ��� �ϴ� ��쵵 �ֽ��ϴ�.(���Ḯ��Ʈ�� ���� ť ���� �ڷᱸ��
//������ �� �� �� ����)
struct GameCharacter {
	MyPosition p; //�� �ٸ� ����ü�� ����ü �ȿ� ���� �� �ִ�.
	char id[100];
	int level;
}typedef MyPlayer;