package studyjava01_creator;

public class Qilin extends Cryptid {

	@Override
	public void Fly() {
		System.out.println("위엄있게 난다 기린스럽게~");

	}

	@Override
	public void FlapWing() {
		return; //기린은 날개짓을 하지 않는다.

	}

	@Override
	public void Run() {
		return; //기린은 달리지 않는다.

	}

	@Override
	public void jog() {
		return; //기린은 뛰지 않는다.

	}

	@Override
	public void sleep() {
		return; //영겁의 세월동안 기린에겐 잠이 없다.

	}

}
