package studyjava04_interface_abstract;

import studyjava03_interface.Bulbasaur;
import studyjava03_interface.Ivysaur;
import studyjava03_interface.Pokemon;

public class StudyJava03_interface_abstract {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Pokemon b1 = new Bulbasaur();
		Pokemon c1 = new Charmander();
		Bulbasaur bb = new Bulbasaur();
		Bulbasaur ivy = new Ivysaur();//�̻���Ǯ�� �̻��ؾ����� ��ӹ���
		Charmander cc = new Charmander();
		
		Digimon d1 = new Augumon();
		Digimon d2 = new Padakmon();
		Augumon a1 = new Augumon();
		Padakmon p1 = new Padakmon();
		
		Pokemon poke1 = new Pokemon() {
			
			@Override
			public void cry() {
				System.out.println("�� �����̴ٿ�");
				
			}
		};
		poke1.cry();
		new Pokemon() {
			
			@Override
			public void cry() {
				System.out.println("�������");
			}
		}.cry();
		
		//�������̽��� �̿��ؼ��� �͸�ü�� ���� �� �ִ�.
		//Hoiable�̶�� �������̽��� ������ �ӽ� ��ü
		Holiable h = new Holiable() {
			
			@Override
			public void killundead() {
				System.out.println("���۰� �θ���!");
			}
			
			@Override
			public void holypeast() {
				System.out.println("������ ��ġ!");
				
			}
			
			@Override
			public void holybolt() {
				System.out.println("�ϴ��� ���� ��ġ!");
				
			}
		};
		h.holybolt();
		
		Digimon ddd = new Digimon() {
			
			@Override
			public void evolution() {
				System.out.println("�������̸�");
				
			}
			
			@Override
			public void degeneration() {
				System.out.println("������~");
				
			}
		};

	}

}
