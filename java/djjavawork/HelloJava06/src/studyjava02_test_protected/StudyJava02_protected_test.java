package studyjava02_test_protected;

import studyjava01_study_class.Circle;
import studyjava01_study_class.Globe;
import studyjava01_study_class.Sphere;

public class StudyJava02_protected_test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle c = new Circle(10);
		System.out.println("sp1 ����");
		Sphere sp1 = new Sphere();
		System.out.println("g1 ����");
		Globe g1 = new Globe(245);
		
		//�ٸ� ��Ű���� �� �ȴ�.
		//���������� protected�� �پ������Ƿ� 
		//�ٸ� ��Ű������ �װ� ��ӹ��� Ŭ���������� �ȴ�.
//		sp1.Color = "RED";
//		sp1.spin();
		g1.setColor("Blue");
		g1.spinGlobe(g1.getColor());
//		g1.spin();

	}

}
