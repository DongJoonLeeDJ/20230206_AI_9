package studyjava07_test_compare_copy;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

import studyjava06_basic_interface.Student;

public class StudyJava05_Test_Compare_Clone {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Copy Test
		//얕은 복사
		Student s1 = new Student("001", "박준호", 34);
		Student s2 = s1;
		s2.setNum("007");
		//s1과 s2가 같은 곳을 가리키고 있다.
		//이렇게 가르키는 주소지만 복사하는 걸
		//얕은 복사(Shallow Copy)라고 부름
		//이 경우 s2의 num값을 바꿨는 데, s1의 num값도 바뀌므로
		//예상치 못한 프로그램 버그가 발생할 수 있다.
		System.out.println(s1.getNum());
		System.out.println(s2.getNum());
		
		
		//깊은 복사
		Student s3 = new Student("100", "김신혁", 30);
		Student s4 = null;
		try {
			//clone 함수의 리턴값이 Object이므로 형변환한 것
			s4 = (Student)s3.clone();
			s4.setNum("200");
			s4.setAge(35);
			s4.setName("이동준");
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println(s3.getName());
		System.out.println(s3.getAge());
		System.out.println(s3.getNum());
		System.out.println(s4.getName());
		System.out.println(s4.getAge());
		System.out.println(s4.getNum());
		
		//순서 정렬하는 거~!!
		ArrayList<Student> students = 
				new ArrayList<Student>();
		students.add(s1);//박준호 34
		students.add(s3);//김신혁 30
		students.add(s4);//이동준 35
		System.out.println("---------------");
		for (Student student : students) {
			System.out.println(student.getNum());
			System.out.println(student.getName());
			System.out.println(student.getAge());
			System.out.println("-");
		}
		System.out.println("---------------");
		//import Collections java util
		Collections.sort(students);
		for (Student student : students) {
			System.out.println(student.getNum());
			System.out.println(student.getName());
			System.out.println(student.getAge());
			System.out.println("-");
		}
		
		
	}

}
