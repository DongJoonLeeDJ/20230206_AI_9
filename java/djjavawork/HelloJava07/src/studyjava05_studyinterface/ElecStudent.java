package studyjava05_studyinterface;

public class ElecStudent implements Studiable {

	@Override
	public void rest() {
		System.out.println("폰보면서 눈감고 몸을 쉽니다.");
		// TODO Auto-generated method stub
		//Studiable.super.rest();
	}
	@Override
	public void study() {
		// TODO Auto-generated method stub
		System.out.println("직접 자재를 조립하며 공부합니다.");
	}

}
