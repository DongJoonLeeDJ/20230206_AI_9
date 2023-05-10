package studyjava03_class;

import java.util.Scanner;

public class StudyJava06_solve {

	public static void main(String[] args) {
		//f2 눌러서 import해도 되고
		//ctrl space(=자동완성) 기능 이용해도 됨
		Scanner s = new Scanner(System.in);
		Student s1 = new Student();
		Student s2 = new Student();
		Student s3 = new Student();
		Student s4;
		
		System.out.println("학생 이름은?");
		s1.name = s.nextLine();
		System.out.println("학생 성별은?");
		s1.gender = s.nextLine();
		System.out.println("학생 번호는?");
		s1.beonho = Integer.parseInt(s.nextLine());
		
		System.out.println("학생 이름은?");
		s2.name = s.nextLine();
		System.out.println("학생 성별은?");
		s2.gender = s.nextLine();
		System.out.println("학생 번호는?");
		s2.beonho = Integer.parseInt(s.nextLine());
		
		System.out.println("학생 이름은?");
		s3.name = s.nextLine();
		System.out.println("학생 성별은?");
		s3.gender = s.nextLine();
		System.out.println("학생 번호는?");
		s3.beonho = Integer.parseInt(s.nextLine());
		
//		System.out.println("%s %s %d", s1.name....);
		System.out.printf
		("%s %s %d\n", s1.name,s1.gender,s1.beonho);
		
		System.out.println(String.format("%s %s %d",
				s2.name,s2.gender,s2.beonho));
		
		System.out.println(s3.name+","
		+s3.gender+","+s3.beonho);
		
		//s4.name="안교석";
		Student s5 = new Student();
		s5.name="신동훈";
		s5.gender="남자";
		s5.beonho=100;
		Student s6 = s5;
		s6.name="한동훈";
		System.out.println(s5.name);
		System.out.println(s6.name);
		
	}

}







