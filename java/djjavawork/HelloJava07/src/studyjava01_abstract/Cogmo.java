package studyjava01_abstract;

public class Cogmo extends LolChamp {
	
	public void passive() {
		System.out.println("���ɽþƽ� ������");
	}
	@Override
	public void Q() {
		System.out.println("Q: �νļ� ħ");
	}
	@Override
	public void W() {
		System.out.println("W: ��ü���� ����");
	}
	@Override
	public void E() {
		System.out.println("E:������ �к�");
	}

	@Override
	public void R() {
		System.out.println("R:�ñر�, ����ִ� �����");
	}

}
