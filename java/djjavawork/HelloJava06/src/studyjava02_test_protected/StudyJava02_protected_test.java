package studyjava02_test_protected;

import studyjava01_study_class.Circle;
import studyjava01_study_class.Globe;
import studyjava01_study_class.Sphere;

public class StudyJava02_protected_test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle c = new Circle(10);
		System.out.println("sp1 생성");
		Sphere sp1 = new Sphere();
		System.out.println("g1 생성");
		Globe g1 = new Globe(245);
		
		//다른 패키지라서 안 된다.
		//결정적으로 protected가 붙어있으므로 
		//다른 패키지에선 그걸 상속받은 클래스에서만 된다.
//		sp1.Color = "RED";
//		sp1.spin();
		g1.setColor("Blue");
		g1.spinGlobe(g1.getColor());
//		g1.spin();

	}

}
