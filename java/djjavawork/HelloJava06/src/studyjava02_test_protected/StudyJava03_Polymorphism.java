package studyjava02_test_protected;

import java.util.ArrayList;

import studyjava01_study_class.*;

public class StudyJava03_Polymorphism {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//다형성 : 다양한 형태로 변할 가능
		//왼쪽 조상클래스(super클래스)
		//오른쪽 자손 클래스(sub클래스)
		Circle c = new Sphere();
		c.setR(20);
		Circle c2 = new Globe(200);
		c2.setR(30);
		Circle c3 = new Circle(10);
		Sphere ss = new Sphere();
		ss.setR(40);
		Sphere ss2 = new Globe(300);
		ss2.setR(50);
		
		//is관계가 성립되면 다형성이 성립된다.
		//오른쪽꺼 is 왼쪽꺼
		//Sphere is Circle(O)
		//Globe is Sphere(O)
		//반대는 성립하지 않음
		//Circle is Globe(???)
		
		//이런 특징때문에 Circle 배열이나 Circle List에 
		//Sphere나 Globe가 들어갈 수 있음
		
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
			if(circle instanceof Sphere)//new Sphere(), new Globe()라면
			{
				((Sphere)circle).breakCircle();//new Globe()도 호출됨
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
