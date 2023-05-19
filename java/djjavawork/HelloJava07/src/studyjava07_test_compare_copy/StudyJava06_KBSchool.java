package studyjava07_test_compare_copy;

import java.util.ArrayList;
import java.util.Collections;

import studyjava06_basic_interface.Student;

public class StudyJava06_KBSchool {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Student> KBStudents = new ArrayList<Student>();
		KBStudents.add(new KBStudent("001", "이동준", 35,10,20));
		KBStudents.add(new KBStudent("002", "소병수", 35,100,100));
		KBStudents.add(new KBStudent("003", "박준호", 35,50,70));
		KBStudents.add(new KBStudent("004", "김희수", 20,55,75));
		KBStudents.add(new KBStudent("005", "임나현", 25,85,95));
		for (Student student : KBStudents) {
			System.out.println(student);
		}
		Collections.sort(KBStudents);
		for (Student student : KBStudents) {
			System.out.println(student);
		}

		ArrayList<KBStudent> KBKBStudents = new ArrayList<KBStudent>();
		KBKBStudents.add(new KBStudent("001", "이동준", 35,10,20));
		KBKBStudents.add(new KBStudent("002", "소병수", 35,100,100));
		KBKBStudents.add(new KBStudent("003", "박준호", 35,50,70));
		KBKBStudents.add(new KBStudent("004", "김희수", 20,55,75));
		KBKBStudents.add(new KBStudent("005", "임나현", 25,85,95));
		for (Student student : KBKBStudents) {
			System.out.println(student);
		}
		Collections.sort(KBKBStudents);
		for (Student student : KBKBStudents) {
			System.out.println(student);
		}
		
		System.out.println("일등:"+KBKBStudents.get(0));
		System.out.println("꼴등:"+KBKBStudents.get(KBKBStudents.size()-1));
		
		
	}

}
