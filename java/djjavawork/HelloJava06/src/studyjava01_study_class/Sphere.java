package studyjava01_study_class;

public class Sphere extends Circle{

	//Sphere�� ��ӹ��� Ŭ���������� �� �� �ִ�.
	//�� Circle�̳� �ٸ� main�Լ��� �ִ� class���� �� ����.
	protected String Color;
	protected void spin() {
		System.out.println(Color+"���� ���� ���ϴ�.");
	}
	
	public double calcVolume()
	{
		//calcArea() = getPI()*getR()*getR()
		return (4/3.0)*calcArea()*getR();
		//return (4/3.0)*getPI()*getR()*getR()*getR();
	}
	
	@Override
	public void dance() {
		// TODO Auto-generated method stub
		super.dance();
		System.out.println("3D ���� ȸ���Դϴ�.");
	}
	
	public void breakCircle() {
		System.out.println("����  : " + calcVolume());
		System.out.println("3D ���� �ҹ�⸦ ���ϴ�.");
	}
}






