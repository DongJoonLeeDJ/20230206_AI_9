package studyjava04_extends;

public class StudyJava07_School {

	public static void main(String[] args) {
		Student s1 = new Student("�̵���", 35);
		UnivStudent u1 = new UnivStudent(s1.getName(),
				s1.getAge(), "2009038033");
		s1.sleep();
		u1.sleep();//UnivStudent �ȿ��� sleep�� ����.
		s1.study();
		u1.study();//Student�� study�� ������� ��(�������̵�)
		
		
	}

}
