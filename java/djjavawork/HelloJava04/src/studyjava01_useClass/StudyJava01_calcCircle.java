package studyjava01_useClass;

public class StudyJava01_calcCircle {
	
	static double getArea(Circle c)
	{
		return c.getR()*c.getR()*c.getPI();
	}
	static double getRound(Circle c) {

		return 2*c.getR()*c.getPI();
	}
	
	static void printCircleInfo(Circle c)
	{
		System.out.println(getRound(c));
		System.out.println(getArea(c));
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle c = new Circle(10);
		Circle c2 = new Circle(); //생성자가 오버로딩이 된다.
		//왜냐면 Circle class 안에 두 개의 생성자를 써놨기 때문이다.
		Circle c3 = new Circle(-1); //r = 0으로 나옴.
		
		System.out.println(c.getArea());
		System.out.println(c.getRound());
		c2.setR(5);
		System.out.println(c2.getArea());
		System.out.println(c2.getRound());
		System.out.println(c3.getArea());
		System.out.println(c3.getRound());
		
		
		printCircleInfo(c);
		
		
		//cc 변수는 stack이라는 영역에 할당됨
		//new Circle()을 이용해서 Heap 영역에 Circle 타입의 변수가 할당됨
		//new Circle(), new Circle(50)을 Instance(인스턴스)라고 부름
		
		
		//인스턴스를 두 개 만든 것이다.
		Circle cc = new Circle();//r = 0
		Circle cc2 = new Circle(50); //r = 50
		
		//인스턴스별로 r값이 다를 수 있다.
		//인스턴스별로 넓이값이랑 둘레값이 다를 수 있다.
		//왜냐면 r 값이 다르기 때문이다.
		//따라서 이렇게 인스턴스별로 값이 다른 걸 인스턴스 변수, 인스턴스 메소드
		
		//모든 인스턴스가 다 똑같은 값을 갖는 게 있다는 건가?
		//Circle의 경우에는 cc, cc2, c 등이 모두 PI값이 동일하다.
		//따라서 이 경우엔 다르게 표현할 수 있다.
		
		cc.setR(20);
		cc.printMyCircle();//1256.6000000000001, 125.66000000000001
		cc2.printMyCircle();
		Circle.printMYPI();
		Circle.MYPI=3.1415926; //모든 Circle에 영향을 미친다.
		//PI값 혹은 학교로 치면 급훈
		//게임으로 치면 그 게임의 유저수 같은 것들은
		//공통된 값으로 앞에 static을 붙인다.
		//그래서 공통적으로 관리를 하고 모든 인스턴스들에 영향을 준다.
		System.out.println("----");
		cc.printMyCircle();//1256.63704,125.663704
		cc2.printMyCircle();
		Circle.printMYPI();
		
		
	}

}








