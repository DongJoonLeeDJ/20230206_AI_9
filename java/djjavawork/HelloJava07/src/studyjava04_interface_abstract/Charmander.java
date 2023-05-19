package studyjava04_interface_abstract;

//다른 패키지에 있는 클래스이므로 임포트한다.
import studyjava03_interface.Animalable;
import studyjava03_interface.Pokemon;

public class Charmander extends Pokemon implements Animalable,Fireable{

	@Override
	public void shotFire() {
		System.out.println("꼬랑지에서 불나간다.");
	}

	@Override
	public void Fireball() {
		System.out.println("입에서 불나간다.");
	}

	@Override
	public void FlameWall() {
		return; //리자드는 되야 쓸 수 있다.
	}

	@Override
	public void bodyattack() {
		System.out.println("몸통박치기!");
	}

	@Override
	public void QuickAttack() {
		System.out.println("전광석화!");
	}

	@Override
	public void run() {
		System.out.println("뒤뚱뒤뚱");
	}

	@Override
	public void jump() {
		System.out.println("얍얍!");
	}

	@Override
	public void cry() {
		System.out.println("파~~~이리~~~~");
	}

}
