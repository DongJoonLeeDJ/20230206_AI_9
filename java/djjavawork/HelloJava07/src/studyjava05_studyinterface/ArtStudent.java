package studyjava05_studyinterface;

public class ArtStudent implements Studiable{

	@Override
	public void rest() {
		// TODO Auto-generated method stub
		Studiable.super.rest();
		System.out.println("�� ���� ���� �۶����ϴ�.");
	}
	@Override
	public void study() {
		// TODO Auto-generated method stub
		System.out.println("���� ��ǰ�� �����ϸ� �����մϴ�.");
		
	}

}
