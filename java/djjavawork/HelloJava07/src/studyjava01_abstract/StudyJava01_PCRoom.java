package studyjava01_abstract;

public class StudyJava01_PCRoom {

	public static void main(String[] args) {
		LolChamp c1 = new Cogmo();
		Cogmo c2 = new Cogmo();
//		LolChamp c3 = new LolChamp();
		//c3�� StudyJava01_PCRoom.java���� �Ｎ���� ������� ��
		//�� �ڵ� �ȿ����� ���̴� ��ü
		LolChamp c3 = new LolChamp() {

			@Override
			public void Q() {
				System.out.println("������ ����");				
			}

			@Override
			public void W() {
				System.out.println("���� ���� ���");
			}

			@Override
			public void E() {
				System.out.println("�б⿡ ���� �ܻ�");
			}

			@Override
			public void R() {
				System.out.println("�ִ� ������");
			}
			
		};
		
		c1.Q();
		c2.passive();
		((Cogmo)c1).passive();
		c3.Q(); //StudyJava01_PCRoom������ ������� �ڵ���
		//�� �ڵ� �ٱ����� ���� �� ����.
		//�Ｎ���� ������� ��ü

	}

}
