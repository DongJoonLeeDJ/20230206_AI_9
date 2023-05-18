package studyjava05_abstract;

public class StudyJava07_Restaurant {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Food f = new Food(); //단독으로 인스턴스 못 만듦
		Food f = new Sushi();//다형성 이용해서 만들 순 있음
		Sushi s = new Sushi();
		
		f.eat();//인스턴스를 Sushi로 만들었으니
		//Sushi에 있는 eat 호출할 수 있 다.
		((Sushi)(f)).eat();
	}

}
