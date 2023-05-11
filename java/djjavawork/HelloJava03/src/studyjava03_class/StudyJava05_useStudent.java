package studyjava03_class;

import java.util.ArrayList;

public class StudyJava05_useStudent {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s1 = new Student();
		s1.name = "박세진";
		s1.beonho = 1;
		s1.gender = "남성";
		Student s2 = new Student();
		s2.name = "박세진";
		s2.beonho = 2;
		s2.gender="여성";
		
		Student[] students1 = new Student[3];
		students1[0] = s1;
		students1[1] = s2;
		students1[2] = new Student();
		students1[2].name="정선호";
		students1[2].gender="여성";
		students1[2].beonho =3;
		
		ArrayList<Student> students = 
				new ArrayList<Student>();
		students.add(s1);
		students.add(s2);
		students.add(new Student());
		students.get(2).beonho = 10;
		students.get(2).name = "박세진";
		students.get(2).gender = "남성";
		
		for(int i = 0; i<students1.length; i++)
			System.out.println(students1[i].name);
		for(Student item : students1)
			System.out.println(item.name);
		for(int i = 0; i<students.size(); i++)
			System.out.println(students.get(i).name);
		for(Student item : students)
			System.out.println(item.name);
		
	}

}
