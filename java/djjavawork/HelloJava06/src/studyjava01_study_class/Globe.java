package studyjava01_study_class;

//Sphere�� Circle�� ��ӹ��� Ŭ�����̴�.
//Sphere�� ��ӹ��� Ŭ�����̰�
//���� Globe�� Circle�� ����Ŭ������.(�ڼ��� �ڼ�)
public class Globe extends Sphere{
	private int countOfCountry; //���� ����

//	public Globe() {}
	public Globe(int countOfCountry) {
		this.countOfCountry = countOfCountry;
	}
	public void spinGlobe(String c) {
		setColor(c);
		//Color = c; //Sphere�� �ִ� protected �Ӽ�
		spin();
	}
	
	//public�� ���ؼ� protected�� private���� �� �Ϳ�
	//������ �� �ִ�.
	public void setColor(String c)
	{
		Color = c;
	}
	public String getColor()
	{
		return Color;
	}
	
	public int getCountOfCountry() {
		return countOfCountry;
	}
	public void setCountOfCountry(int countOfCountry) {
		this.countOfCountry = countOfCountry;
	}
	
	@Override
	public void dance() {
		System.out.println(this.countOfCountry+"������� ���ϴ�.");
	}
	
	@Override
	public void breakCircle() {
		System.out.println("���� ��� �Ф�");
		System.out.println(this.countOfCountry+"������� �������ϴ�.");
	}
	
	
}





