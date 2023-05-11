package studyjava01_useClass;
//Circle.java = C언어로 치자면 구조체가 담긴 헤더파일 같은 것
//js로 치자면 class가 담긴 js파일이라고 보셔도 됨
public class Circle {

	//static이 붙지 않으면 전부 인스턴스 변수 혹은 인스턴스 메소드
	private int r;//반지름, 인스턴스 변수
	private final double PI = 3.14;//PI값은 상수
	
	//static 붙는 건 클래스 변수, 클래스 메소드라고 함
	//클래스 차원에서 공통적으로 쓰는 메소드나 속성을 클래스 변수, 클래스 메소드
	//앞에 static이 붙는다.
	//!!!! 그리고!!!! static이 붙은 메소드 안에는 static이 붙은 메소드나
	//static이 붙은 변수만 활용할 수 있다.
	
	//대신 static이 붙은 건 static이 붙지 않은 곳에서 쓸 수 있다.
	//이유는 C때 수업을 잘 들었다면 알고 있을 것이다.
	
	//static이 붙은 건 인스턴스를 생성하지 않고도 쓸 수 있다.
	//즉 new Circle() 이런 거 없이 그냥 Circle.MYPI 이렇게 쓸 수 있다
	//메소드나 변수 둘 다 그렇다.
	public static double MYPI = 3.1415; //모든 Circle이 공통적으로 이용함
	public void printMyCircle()
	{
		System.out.println("원의 넓이!(MYPI이용)");
		System.out.println(this.r*this.r*MYPI);
		System.out.println("원의 둘레!(MYPI이용)");
		System.out.println(2*this.r*MYPI);
	}
	public static void printMYPI()
	{
		System.out.println(MYPI);
	}
	
	//getter, setter
	//인스턴스 메소드
	public int getR() {
		return r;
	}
	public void setR(int r) {
		if(r<=0)
		{
			System.out.println("Error!");
			this.r = 0;
			return;
		}
		this.r = r;
	}
	public double getPI() {
		return PI;
	}
	
	//Circle별로 리턴되는 값이 다르므로(동작하는 메커니즘은 똑같지만)
	//각각 다 결과가 다르므로 인스턴스 메소드라고 함
	//static 키워드 없으므로 인스턴스 메소드
	public double getArea() {
		return PI*this.r*this.r;
	}
	public double getRound() {
		return PI*2*this.r;
	}
	
	//생성자
	//이 걸 생성자라고 하는 데
	//이게 없으면
	//public Circle() { }
	//이와 같이 아무 것도 없는 생성자가 암묵적으로 만들어져 있다.
	//근데 아래와 같이 매개변수가 있는 생성자를 만들면
	//매개변수 없는 기본 생성자는 지워짐
	//매개변수 없는 기본 생성자를 쓰고 싶다면
	//명시적으로 써줘야 함
	public Circle() {}
	
	public Circle(int r) {
		setR(r); //자동으로 음수에 대한 예외처리도 해줄 수 있다.
		//this.r = r;
	}
	
	
	
}













