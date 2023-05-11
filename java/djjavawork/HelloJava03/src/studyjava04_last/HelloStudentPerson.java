package studyjava04_last;

//import이용해서
//다른 패키지에 있는 class를 가져 올 수 있다.
//단, 그 class가 public이어 햔다.
import studyjava03_class.Person;
import studyjava03_class.Worker;

public class HelloStudentPerson {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//Student s= new Student();
		Person p = new Person();
		Worker w = new Worker();
		p = new Person("이동준");
		p.setBeonho(-1);
		p.setGender("남성");
		System.out.println(p.getBeonho());
//		p.beonho = -1;
	}

}
