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
		Bulbasaur ivy = new Ivysaur();//이상해풀은 이상해씨한테 상속받음
		Charmander cc = new Charmander();
		
		Digimon d1 = new Augumon();
		Digimon d2 = new Padakmon();
		Augumon a1 = new Augumon();
		Padakmon p1 = new Padakmon();
		
		Pokemon poke1 = new Pokemon() {
			
			@Override
			public void cry() {
				System.out.println("난 나옹이다옹");
				
			}
		};
		poke1.cry();
		new Pokemon() {
			
			@Override
			public void cry() {
				System.out.println("으어어어어");
			}
		}.cry();
		
		//인터페이스를 이용해서도 익명객체를 만들 수 있다.
		//Hoiable이라는 인터페이스를 구현한 임시 객체
		Holiable h = new Holiable() {
			
			@Override
			public void killundead() {
				System.out.println("찬송가 부르기!");
			}
			
			@Override
			public void holypeast() {
				System.out.println("정의의 펀치!");
				
			}
			
			@Override
			public void holybolt() {
				System.out.println("하늘의 은총 펀치!");
				
			}
		};
		h.holybolt();
		
		Digimon ddd = new Digimon() {
			
			@Override
			public void evolution() {
				System.out.println("엑스브이몬");
				
			}
			
			@Override
			public void degeneration() {
				System.out.println("꼬마몬~");
				
			}
		};

	}

}
