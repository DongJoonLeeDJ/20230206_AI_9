package studyjava04_interface_abstract;

public class Augumon extends Digimon implements Fireable{

	@Override
	public void shotFire() {
		System.out.println("�Կ��� ���� ������!");
	}
	@Override
	public void Fireball() {
		return; //��ȭ�ؾ� ���̾�� �� �� �ִٰ� ����
	}

	@Override
	public void FlameWall() {
		return; //��ȭ�ؾ� ���庮�� �� �� �ִٰ� ����
		
	}

	@Override
	public void evolution() {
		System.out.println("�Ʊ��� ��ȭ~~~");
		System.out.println("�׷��� or ���ñ׷��̸�!");
	}

	@Override
	public void degeneration() {
		System.out.println("�ڷθ�~~~~");
		
	}

}
