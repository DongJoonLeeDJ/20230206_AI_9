package studyjava01_study_class;

public class Circle {

	private int r;
	private static double PI=3.14;//조상이든 자손이든
	//바꾸게 되면 다른 모든 클래스에 다 영향을 받는다.
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
		System.out.println("원을 만듭니다.");
		System.out.println("자손클래스 생성자 호출시");
		System.out.println("이 것도 자동호출됨 ㅇㅇ");
	}
	
	public double calcArea() {//원넓이
		return getR()*getR()*getPI();
	}
	public double calcRound() { //원둘레
		return 2*getR()*getPI();
		
	}
	
	public void dance() {
		System.out.println("반지름이"+getR()+"인 원의 춤");
	}
	
	
	
}









