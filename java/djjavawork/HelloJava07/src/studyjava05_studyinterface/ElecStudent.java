package studyjava05_studyinterface;

public class ElecStudent implements Studiable {

	@Override
	public void rest() {
		System.out.println("�����鼭 ������ ���� ���ϴ�.");
		// TODO Auto-generated method stub
		//Studiable.super.rest();
	}
	@Override
	public void study() {
		// TODO Auto-generated method stub
		System.out.println("���� ���縦 �����ϸ� �����մϴ�.");
	}

}
