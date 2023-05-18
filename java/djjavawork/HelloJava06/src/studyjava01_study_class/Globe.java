package studyjava01_study_class;

//Sphere는 Circle을 상속받은 클래스이다.
//Sphere를 상속받은 클래스이고
//따라서 Globe는 Circle의 손자클래스다.(자손의 자손)
public class Globe extends Sphere{
	private int countOfCountry; //나라 개수

//	public Globe() {}
	public Globe(int countOfCountry) {
		this.countOfCountry = countOfCountry;
	}
	public void spinGlobe(String c) {
		setColor(c);
		//Color = c; //Sphere에 있는 protected 속성
		spin();
	}
	
	//public을 통해서 protected나 private으로 된 것에
	//접근할 수 있다.
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
		System.out.println(this.countOfCountry+"나라들이 돕니다.");
	}
	
	@Override
	public void breakCircle() {
		System.out.println("지구 멸망 ㅠㅠ");
		System.out.println(this.countOfCountry+"나라들이 없어집니다.");
	}
	
	
}






