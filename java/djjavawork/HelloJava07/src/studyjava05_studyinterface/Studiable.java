package studyjava05_studyinterface;

public interface Studiable {

	public void study();
	//���� ���Ҷ��� �������̵��ϸ� �ȴ�.
	public default void rest() {
		System.out.println("���� �͵� ������ �����Դϴ�.");
	}
}
