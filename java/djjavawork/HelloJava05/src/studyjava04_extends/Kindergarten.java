package studyjava04_extends;

//유딩
public class Kindergarten extends Student{

	
	private double cm;
	private double kg;
	
	//부모클래스에서 매개변수가 두 개 있는 생성자만 있으므로
	//자손 클래스에서도 마찬가지로 최소 매개변수가 두 개 있는 생성자 필요
	public Kindergarten(String name, int age) {
		super(name, age);
		// TODO Auto-generated constructor stub
	}
	
	public Kindergarten(String name, int age, double cm, double kg) {
		super(name, age);
		this.cm = cm;
		this.kg = kg;
	}


	public double getCm() {
		return cm;
	}

	public void setCm(double cm) {
		this.cm = cm;
	}

	public double getKg() {
		return kg;
	}

	public void setKg(double kg) {
		this.kg = kg;
	}
	
	@Override
	public void study() {
		System.out.println(getName()+"어린이는 뛰어 놉니다.");
	}
	//유치원생한테만 있는 기능
	public void cry() {
		System.out.println(getName()+
				" 어린이는 "+getAge()+"살 답게 포효합니다.");
	}
	
	

}
