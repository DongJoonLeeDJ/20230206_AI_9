package studyjava04_extends;

public class StudyJava07_School {

	public static void main(String[] args) {
		Student s1 = new Student("이동준", 35);
		UnivStudent u1 = new UnivStudent(s1.getName(),
				s1.getAge(), "2009038033");
		s1.sleep();
		u1.sleep();//UnivStudent 안에는 sleep이 없다.
		s1.study();
		u1.study();//Student의 study를 덮어쓰기한 것(오버라이딩)
		
		
	}

}
