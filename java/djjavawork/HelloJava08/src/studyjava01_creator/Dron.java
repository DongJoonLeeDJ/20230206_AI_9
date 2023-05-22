package studyjava01_creator;

public class Dron implements Fliable {

	@Override
	public void Fly() {
		System.out.println("이 소리가 들리면 장수 말벌일 수도 있습니다.");

	}

	@Override
	public void FlapWing() {
		System.out.println("프로펠러를 빠르게 움직입니다.");

	}

}
