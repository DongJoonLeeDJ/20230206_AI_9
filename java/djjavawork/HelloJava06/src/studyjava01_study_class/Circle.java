package studyjava01_study_class;

public class Circle {

	private int r;
	private static double PI=3.14;//�����̵� �ڼ��̵�
	//�ٲٰ� �Ǹ� �ٸ� ��� Ŭ������ �� ������ �޴´�.
	public int getR() {
		return r;
	}
	public void setR(int r) {
		this.r = r;
	}
	public static double getPI() {
		return PI;
	}
	public static void setPI(double pI) {
		PI = pI;
	}
	public Circle(int r) {
		this.r = r;
	}
	public Circle() {
		System.out.println("���� ����ϴ�.");
		System.out.println("�ڼ�Ŭ���� ������ ȣ���");
		System.out.println("�� �͵� �ڵ�ȣ��� ����");
	}
	
	public double calcArea() {//������
		return getR()*getR()*getPI();
	}
	public double calcRound() { //���ѷ�
		return 2*getR()*getPI();
		
	}
	
	public void dance() {
		System.out.println("��������"+getR()+"�� ���� ��");
	}
	
	
	
}









