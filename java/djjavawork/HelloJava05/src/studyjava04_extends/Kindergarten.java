package studyjava04_extends;

//����
public class Kindergarten extends Student{

	
	private double cm;
	private double kg;
	
	//�θ�Ŭ�������� �Ű������� �� �� �ִ� �����ڸ� �����Ƿ�
	//�ڼ� Ŭ���������� ���������� �ּ� �Ű������� �� �� �ִ� ������ �ʿ�
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
		System.out.println(getName()+"��̴� �پ� ��ϴ�.");
	}
	//��ġ�������׸� �ִ� ���
	public void cry() {
		System.out.println(getName()+
				" ��̴� "+getAge()+"�� ��� ��ȿ�մϴ�.");
	}
	
	

}
