package studyjava04_interface_abstract;

//�ٸ� ��Ű���� �ִ� Ŭ�����̹Ƿ� ����Ʈ�Ѵ�.
import studyjava03_interface.Animalable;
import studyjava03_interface.Pokemon;

public class Charmander extends Pokemon implements Animalable,Fireable{

	@Override
	public void shotFire() {
		System.out.println("���������� �ҳ�����.");
	}

	@Override
	public void Fireball() {
		System.out.println("�Կ��� �ҳ�����.");
	}

	@Override
	public void FlameWall() {
		return; //���ڵ�� �Ǿ� �� �� �ִ�.
	}

	@Override
	public void bodyattack() {
		System.out.println("�����ġ��!");
	}

	@Override
	public void QuickAttack() {
		System.out.println("������ȭ!");
	}

	@Override
	public void run() {
		System.out.println("�ڶ׵ڶ�");
	}

	@Override
	public void jump() {
		System.out.println("���!");
	}

	@Override
	public void cry() {
		System.out.println("��~~~�̸�~~~~");
	}

}
