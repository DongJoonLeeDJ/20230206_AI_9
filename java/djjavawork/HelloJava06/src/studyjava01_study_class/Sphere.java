package studyjava01_study_class;

public class Sphere extends Circle{

	//Sphere를 상속받은 클래스에서만 쓸 수 있다.
	//즉 Circle이나 다른 main함수가 있는 class에선 못 쓴다.
	protected String Color;
	protected void spin() {
		System.out.println(Color+"색이 빙빙 돕니다.");
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
		System.out.println("3D 구의 회전입니다.");
	}
	
	public void breakCircle() {
		System.out.println("부피  : " + calcVolume());
		System.out.println("3D 구의 뚝배기를 깹니다.");
	}
}






