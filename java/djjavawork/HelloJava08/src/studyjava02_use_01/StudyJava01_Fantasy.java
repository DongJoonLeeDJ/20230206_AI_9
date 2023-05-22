package studyjava02_use_01;

import studyjava01_creator.*;
public class StudyJava01_Fantasy {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Qilin q1 = new Qilin();
		Animal a1 = new Qilin();
		Cryptid c1 = new Dragon();
		Cryptid g1 = new GirlFriend();
		GirlFriend w1 = new Wife();
		Walkable r1 = new Robot();
		Fliable f1 = new Dron();
		Cryptid cc = new Cryptid() {
			
			@Override
			public void jog() {
				System.out.println("����Ⱑ ���ϴ�.");
				
			}
			
			@Override
			public void Run() {
				System.out.println("�� ������ ����");
				
			}
			
			@Override
			public void Fly() {
				System.out.println("������ �ϴ��� ���� �� ����.");
				
			}
			
			@Override
			public void FlapWing() {
				System.out.println("���� ���� ����� ���� �������̾�");
				
			}
			
			@Override
			public void sleep() {
				System.out.println(getName()+"���� �ڴ� �͵� ���־�");
				
			}
		};
		
		cc.setName("�ں���");
		cc.setAge(30);
		cc.sleep();
		
		Cryptid[] fantasy = new Cryptid[5];
		fantasy[0] = cc;
		fantasy[1] = w1;
		fantasy[2] = g1;
		fantasy[3] = c1;
		fantasy[4] = q1;
		
		Walkable[] wolkers = new Walkable[3];
		wolkers[0] = r1;
		wolkers[1] = w1;
		wolkers[2] = new Walkable() {
			@Override
			public void jog() {
				System.out.println("���ݾ��� ����.");
			}
			@Override
			public void Run() {
				System.out.println("��¿Ƽ��");
				
			}
		};
		

	}

}






