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
		
		System.out.println("sp1(��) �ϳ� ����");
		Sphere sp1 = new Sphere();
		sp1.setR(15);
		sp1.Color = "RED"; //���� ��Ű���� protected�� default�� �͵鵵 �� ���� ���
		sp1.spin();
		System.out.println(sp1.calcVolume());
		Circle.setPI(3.0);
		System.out.println("PI�� 3.0���� �ٲ� ��");
		System.out.println(c1.calcArea());
		System.out.println(c1.calcRound());
		System.out.println(c2.calcArea());
		System.out.println(c2.calcRound());
		System.out.println(sp1.calcArea());
		System.out.println(sp1.calcRound());
		System.out.println(sp1.calcVolume());
		Sphere.setPI(3.1);
		System.out.println("PI�� 3.1�� �ٲ� ��");
		System.out.println(c1.calcArea());
		System.out.println(c1.calcRound());
		System.out.println(c2.calcArea());
		System.out.println(c2.calcRound());
		System.out.println(sp1.calcArea());
		System.out.println(sp1.calcRound());
		System.out.println(sp1.calcVolume());
		System.out.println("3.1415 ���� ����!");
		Globe.setPI(3.1415);
		//Sphere sp2 = new Sphere(100);
		Globe g1 = new Globe(195);//Circle�� �ڼ��� �ڼ� = ����
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
