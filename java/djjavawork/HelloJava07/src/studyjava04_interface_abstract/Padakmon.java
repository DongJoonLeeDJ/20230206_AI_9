package studyjava04_interface_abstract;

public class Padakmon extends Digimon implements Holiable{

	@Override
	public void killundead() {
		return;//아직 진화하기 전이라 천사가 아님
		
	}

	@Override
	public void holypeast() {
		return;//아직 진화하기 전이라 천사가 아님
		
	}

	@Override
	public void holybolt() {
		return;//아직 진화하기 전이라 천사가 아님
		
	}

	@Override
	public void evolution() {
		System.out.println("엔젤몬~~~");
		
	}

	@Override
	public void degeneration() {
		System.out.println("응애응애~~~");
		
	}

}
