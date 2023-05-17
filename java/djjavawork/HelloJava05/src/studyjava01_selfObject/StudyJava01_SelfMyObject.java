package studyjava01_selfObject;

public class StudyJava01_SelfMyObject {

	void testHelloWorld()
	{
		System.out.println("안녕 세상!");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//testHelloWorld(); //호출 안 됨
		//static이 붙은 main입장에선 testHelloWorld가
		//아직 메모리에 없는, 즉 존재하지 않는 함수인 것!
		
		//자기 자신을 객체화한 것
		//인스턴스 변수나 메소드를 활용하고 싶을 때 이렇게 해야 함
		new StudyJava01_SelfMyObject().testHelloWorld();
	}

}
