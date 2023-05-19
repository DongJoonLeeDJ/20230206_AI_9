package studyjava01_abstract;

public class Cogmo extends LolChamp {
	
	public void passive() {
		System.out.println("이케시아식 마무리");
	}
	@Override
	public void Q() {
		System.out.println("Q: 부식성 침");
	}
	@Override
	public void W() {
		System.out.println("W: 생체마법 폭격");
	}
	@Override
	public void E() {
		System.out.println("E:공허의 분비물");
	}

	@Override
	public void R() {
		System.out.println("R:궁극기, 살아있는 고사포");
	}

}
