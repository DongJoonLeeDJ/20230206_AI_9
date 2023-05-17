package studyjava04_extends;

public class StudyJava08_NewSchool {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Student s1 = new Student("이수성",26);
		UnivStudent u1 = new UnivStudent("소병수", 30,"10");
		Kindergarten k1 = new Kindergarten
				("최은지", 3, 170.1, 30.5);
		MasterStudent m1 = new MasterStudent("이동준", 45,
				"2009038033", "황우석");
		System.out.println("Student");
		s1.study();
		s1.sleep();
		System.out.println("UniStudent");
		u1.study();
		u1.sleep();
		System.out.println("Kindergarten");
		k1.study();
		k1.sleep();
		k1.cry();
		System.out.println("MasterStudent");
		m1.study();
		m1.sleep();
		m1.cleanRoom();
		m1.cleanRoom("화장실");
		
		//같은 패키지 안에선 protected 붙어 있어도 접근 가능
		m1.thesisTopic="얼굴인식";
		m1.writeThesis();

	}

}
