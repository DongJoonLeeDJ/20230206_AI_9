package studyjava02_game;

public class StudyJava02_Diablo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(GameCharacter.getCount());
		GameCharacter g1 = 
				new GameCharacter("����ũ���ּҺ���", "����");
		GameCharacter g2 = 
				new GameCharacter("���̺��������", "������");
		GameCharacter g3 = 
				new GameCharacter("���������̵���", "������");
		
		GameCharacter g4 = new GameCharacter("���������̼���");
		
		System.out.println(GameCharacter.getCount());
		
		GameCharacter.chat("���̷� ���̷� �氡�氡");
		GameCharacter.chat("���������̵���","������ ���� �ð��ε���.");
		
		g1.printInfo();
		g2.printInfo();
		g3.printInfo();
		
		g1.setJob("������");
		g1.setLevel(255);
		g2.setJob("����");
		g2.setLevel(100);
		g3.setLevel(35);

		g1.printInfo();
		g2.printInfo();
		g3.printInfo();
		
		g1.attack();
		g2.attack();
		g3.attack();
		
		

	}

}
