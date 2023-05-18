package studyjava01_study_class;

public class StudyJava01_circles {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle c1 = new Circle();
		c1.setR(50);
		Circle c2 = new Circle(10);
		System.out.println(c1.calcArea());
		System.out.println(c1.calcRound());
		System.out.println(c2.calcArea());
		System.out.println(c2.calcRound());
		
		System.out.println("sp1(구) 하나 생성");
		Sphere sp1 = new Sphere();
		sp1.setR(15);
		sp1.Color = "RED"; //같은 패키지라서 protected나 default인 것들도 다 접근 허용
		sp1.spin();
		System.out.println(sp1.calcVolume());
		Circle.setPI(3.0);
		System.out.println("PI를 3.0으로 바꾼 뒤");
		System.out.println(c1.calcArea());
		System.out.println(c1.calcRound());
		System.out.println(c2.calcArea());
		System.out.println(c2.calcRound());
		System.out.println(sp1.calcArea());
		System.out.println(sp1.calcRound());
		System.out.println(sp1.calcVolume());
		Sphere.setPI(3.1);
		System.out.println("PI를 3.1로 바꾼 뒤");
		System.out.println(c1.calcArea());
		System.out.println(c1.calcRound());
		System.out.println(c2.calcArea());
		System.out.println(c2.calcRound());
		System.out.println(sp1.calcArea());
		System.out.println(sp1.calcRound());
		System.out.println(sp1.calcVolume());
		System.out.println("3.1415 지구 생성!");
		Globe.setPI(3.1415);
		//Sphere sp2 = new Sphere(100);
		Globe g1 = new Globe(195);//Circle의 자손의 자손 = 지구
//		Globe g2 = new Globe();
		g1.Color = "Blue";
		g1.spin();
		g1.dance();
		g1.calcArea();
		g1.setR(200);
		System.out.println(c1.calcArea());
		System.out.println(c1.calcRound());
		System.out.println(c2.calcArea());
		System.out.println(c2.calcRound());
		System.out.println(sp1.calcArea());
		System.out.println(sp1.calcRound());
		System.out.println(sp1.calcVolume());
		System.out.println(g1.calcArea());
		System.out.println(g1.calcRound());
		System.out.println(g1.calcVolume());
		
		c1.dance();
		sp1.dance();
		g1.dance();
		
		sp1.breakCircle();
		g1.breakCircle();
		
		
		
		
	}

}
