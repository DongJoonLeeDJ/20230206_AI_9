package studyjava05_abstract;

public class StudyJava07_Restaurant {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Food f = new Food(); //�ܵ����� �ν��Ͻ� �� ����
		Food f = new Sushi();//������ �̿��ؼ� ���� �� ����
		Sushi s = new Sushi();
		
		f.eat();//�ν��Ͻ��� Sushi�� ���������
		//Sushi�� �ִ� eat ȣ���� �� �� ��.
		((Sushi)(f)).eat();
	}

}
