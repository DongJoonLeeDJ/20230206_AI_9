package studyjava03_class;

public class StudyJava12_create {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s1 = new Student();
		s1.name="박세진";
		s1.gender="남성";
		s1.beonho=1;
		
		Person p1 = new Person();
		p1.setName("정홍근");//p1.name="정홍근"이게 안 될거임
		p1.setGender("남성");
		p1.setBeonho(2);
		
		System.out.println(s1.name+","+s1.gender+","+s1.beonho);
		System.out.println(p1.getName()+","+p1.getGender()+","+p1.getBeonho());
		Person p2 = new Person("이동준");
		p2.setBeonho(7);
		p2.setGender("남성");
		Person p3 = new Person("이수성","남성",10);
		Person p4 = new Person("임나현","여성",11);
		

	}

}
