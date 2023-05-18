package studyjava02_test_protected;

import java.util.ArrayList;

import studyjava01_study_class.*;

public class StudyJava03_Polymorphism {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//������ : �پ��� ���·� ���� ����
		//���� ����Ŭ����(superŬ����)
		//������ �ڼ� Ŭ����(subŬ����)
		Circle c = new Sphere();
		c.setR(20);
		Circle c2 = new Globe(200);
		c2.setR(30);
		Circle c3 = new Circle(10);
		Sphere ss = new Sphere();
		ss.setR(40);
		Sphere ss2 = new Globe(300);
		ss2.setR(50);
		
		//is���谡 �����Ǹ� �������� �����ȴ�.
		//�����ʲ� is ���ʲ�
		//Sphere is Circle(O)
		//Globe is Sphere(O)
		//�ݴ�� �������� ����
		//Circle is Globe(???)
		
		//�̷� Ư¡������ Circle �迭�̳� Circle List�� 
		//Sphere�� Globe�� �� �� ����
		
		Circle[] circles = new Circle[10];
		circles[0] = c;
		circles[1] = c2;
		circles[2] = c3;
		circles[3] = new Globe(245);
		circles[4] = new Sphere();
		circles[5] = new Circle();
		
		ArrayList<Circle> cc = new ArrayList<>();
		cc.add(c);
		cc.add(c2);
		cc.add(c3);
		cc.add(ss);
		cc.add(ss2);
		
		
		for (Circle circle : cc) {
			System.out.println(circle.calcArea());
			System.out.println(circle.calcRound());
			circle.dance();
			if(circle instanceof Sphere)//new Sphere(), new Globe()���
			{
				((Sphere)circle).breakCircle();//new Globe()�� ȣ���
				System.out.println(((Sphere)circle).calcVolume());
			}
			if(circle instanceof Globe) {
				((Globe)circle).setColor("Green");
				((Globe)circle).spinGlobe
				(((Globe)circle).getColor());
				
			}
				
		}

	}

}
