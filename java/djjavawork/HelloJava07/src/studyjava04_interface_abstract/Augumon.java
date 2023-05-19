package studyjava04_interface_abstract;

public class Augumon extends Digimon implements Fireable{

	@Override
	public void shotFire() {
		System.out.println("입에서 불이 나가요!");
	}
	@Override
	public void Fireball() {
		return; //진화해야 파이어볼을 쓸 수 있다고 가정
	}

	@Override
	public void FlameWall() {
		return; //진화해야 불장벽을 쓸 수 있다고 가정
		
	}

	@Override
	public void evolution() {
		System.out.println("아구몬 진화~~~");
		System.out.println("그레이 or 스컬그레이몬!");
	}

	@Override
	public void degeneration() {
		System.out.println("코로몬~~~~");
		
	}

}
