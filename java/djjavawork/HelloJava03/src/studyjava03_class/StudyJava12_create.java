package studyjava03_class;

public class StudyJava12_create {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s1 = new Student();
		s1.name="�ڼ���";
		s1.gender="����";
		s1.beonho=1;
		
		Person p1 = new Person();
		p1.setName("��ȫ��");//p1.name="��ȫ��"�̰� �� �ɰ���
		p1.setGender("����");
		p1.setBeonho(2);
		
		System.out.println(s1.name+","+s1.gender+","+s1.beonho);
		System.out.println(p1.getName()+","+p1.getGender()+","+p1.getBeonho());
		Person p2 = new Person("�̵���");
		p2.setBeonho(7);
		p2.setGender("����");
		Person p3 = new Person("�̼���","����",10);
		Person p4 = new Person("�ӳ���","����",11);
		

	}

}
