package studyjava04_last;

//import�̿��ؼ�
//�ٸ� ��Ű���� �ִ� class�� ���� �� �� �ִ�.
//��, �� class�� public�̾� �h��.
import studyjava03_class.Person;
import studyjava03_class.Worker;

public class HelloStudentPerson {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Student s= new Student();
		Person p = new Person();
		Worker w = new Worker();
		p = new Person("�̵���");
		p.setBeonho(-1);
		p.setGender("����");
		System.out.println(p.getBeonho());
//		p.beonho = -1;
	}

}
