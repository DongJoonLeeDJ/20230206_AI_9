package studyjava07_test_compare_copy;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

import studyjava06_basic_interface.Student;

public class StudyJava05_Test_Compare_Clone {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Copy Test
		//���� ����
		Student s1 = new Student("001", "����ȣ", 34);
		Student s2 = s1;
		s2.setNum("007");
		//s1�� s2�� ���� ���� ����Ű�� �ִ�.
		//�̷��� ����Ű�� �ּ����� �����ϴ� ��
		//���� ����(Shallow Copy)��� �θ�
		//�� ��� s2�� num���� �ٲ�� ��, s1�� num���� �ٲ�Ƿ�
		//����ġ ���� ���α׷� ���װ� �߻��� �� �ִ�.
		System.out.println(s1.getNum());
		System.out.println(s2.getNum());
		
		
		//���� ����
		Student s3 = new Student("100", "�����", 30);
		Student s4 = null;
		try {
			//clone �Լ��� ���ϰ��� Object�̹Ƿ� ����ȯ�� ��
			s4 = (Student)s3.clone();
			s4.setNum("200");
			s4.setAge(35);
			s4.setName("�̵���");
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println(s3.getName());
		System.out.println(s3.getAge());
		System.out.println(s3.getNum());
		System.out.println(s4.getName());
		System.out.println(s4.getAge());
		System.out.println(s4.getNum());
		
		//���� �����ϴ� ��~!!
		ArrayList<Student> students = 
				new ArrayList<Student>();
		students.add(s1);//����ȣ 34
		students.add(s3);//����� 30
		students.add(s4);//�̵��� 35
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
