package studyjava05_abstract;

//스시는 Food를 상속받았으므로
//반드시!!!!!!!! eat을 구현해야 함
//이런 걸 바로 추상클래스라고 함
//그리고 이러한 추상클래스는 단독으로 인스턴스를 만들 순 없어요.
public class Sushi extends Food {

	@Override
	public void eat() {
		// TODO Auto-generated method stub
		System.out.println("와사비+간장에 찍어먹음");
	}

}
