package studyjava03_interface;


//이상해씨는 추상클래스인 포켓몬을 상속받고
//인터페이스 2개가 추가된 객체(규칙이 2개 추가됨)
//Platable이라는 규칙에는 3개의 메소드 추가
//Animalable이라는 규칙에는 5개의 메소드 추가
public class Bulbasaur extends Pokemon implements Plantable,Animalable{

	@Override
	public void bodyattack() {
		// TODO Auto-generated method stub
		System.out.println("몸통 박치기!");
	}

	@Override
	public void QuickAttack() {
		// TODO Auto-generated method stub
		System.out.println("전광 석화!");
		
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void jump() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void solarbeam() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void growth() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void photosynthesis() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void cry() {
		// TODO Auto-generated method stub
		
	}

}
