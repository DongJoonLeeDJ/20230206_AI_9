package studyjava01_creator;

public class GirlFriend extends Cryptid{

	@Override
	public void Fly() {
		System.out.println("T-way 예약");
	}

	@Override
	public void FlapWing() {
		return;
		
	}

	@Override
	public void Run() {
		return; //쿠팡 핫딜할 때만 손가락은 빨라진다
		
	}

	@Override
	public void jog() {
		System.out.println("데이트 할 때만 좀 움직임");
		
	}

	@Override
	public void sleep() {
		System.out.println("조용히 잡니다.");
		
	}

}
