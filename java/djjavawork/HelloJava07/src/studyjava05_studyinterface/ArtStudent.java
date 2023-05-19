package studyjava05_studyinterface;

public class ArtStudent implements Studiable{

	@Override
	public void rest() {
		// TODO Auto-generated method stub
		Studiable.super.rest();
		System.out.println("먼 산을 보며 멍때립니다.");
	}
	@Override
	public void study() {
		// TODO Auto-generated method stub
		System.out.println("좋은 작품을 감상하며 공부합니다.");
		
	}

}
