package studyjava03_class;

import java.util.Scanner;

public class StudyJava06_solve {

	public static void main(String[] args) {
		//f2 ������ import�ص� �ǰ�
		//ctrl space(=�ڵ��ϼ�) ��� �̿��ص� ��
		Scanner s = new Scanner(System.in);
		Student s1 = new Student();
		Student s2 = new Student();
		Student s3 = new Student();
		Student s4;
		
		System.out.println("�л� �̸���?");
		s1.name = s.nextLine();
		System.out.println("�л� ������?");
		s1.gender = s.nextLine();
		System.out.println("�л� ��ȣ��?");
		s1.beonho = Integer.parseInt(s.nextLine());
		
		System.out.println("�л� �̸���?");
		s2.name = s.nextLine();
		System.out.println("�л� ������?");
		s2.gender = s.nextLine();
		System.out.println("�л� ��ȣ��?");
		s2.beonho = Integer.parseInt(s.nextLine());
		
		System.out.println("�л� �̸���?");
		s3.name = s.nextLine();
		System.out.println("�л� ������?");
		s3.gender = s.nextLine();
		System.out.println("�л� ��ȣ��?");
		s3.beonho = Integer.parseInt(s.nextLine());
		
//		System.out.println("%s %s %d", s1.name....);
		System.out.printf
		("%s %s %d\n", s1.name,s1.gender,s1.beonho);
		
		System.out.println(String.format("%s %s %d",
				s2.name,s2.gender,s2.beonho));
		
		System.out.println(s3.name+","
		+s3.gender+","+s3.beonho);
		
		//s4.name="�ȱ���";
		Student s5 = new Student();
		s5.name="�ŵ���";
		s5.gender="����";
		s5.beonho=100;
		Student s6 = s5;
		s6.name="�ѵ���";
		System.out.println(s5.name);
		System.out.println(s6.name);
		
	}

}







