package studyjava05_studyinterface;

public class ITStudent implements Studiable {

	@Override
	public void study() {
		System.out.println("컴퓨터로 공부를 합니다.");
		System.out.println("모르면 옆사람 코드 봅니다.");
		System.out.println("아니면 선생님께 물어봅니다.");

	}

}
