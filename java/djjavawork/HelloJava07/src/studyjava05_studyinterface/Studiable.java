package studyjava05_studyinterface;

public interface Studiable {

	public void study();
	//내가 원할때만 오버라이딩하면 된다.
	public default void rest() {
		System.out.println("쉬는 것도 공부의 연장입니다.");
	}
}
