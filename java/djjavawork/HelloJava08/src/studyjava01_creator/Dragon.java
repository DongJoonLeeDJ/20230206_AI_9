package studyjava01_creator;

public class Dragon extends Cryptid{

	@Override
	public void Fly() {
		System.out.println("����� �巡�ｺ���� ����.");
		
	}

	@Override
	public void FlapWing() {
		System.out.println("���� �۴��۴� �巡��巡��.");
		
	}

	@Override
	public void Run() {
		return; //�׶��ؼ� �� �ڴ�.
		
	}

	@Override
	public void jog() {
		return; //������ �ʴ´�.
		
	}

	@Override
	public void sleep() {
		System.out.println("�� �� �� �񶧸��� ���� �ϳ� ���~");
		
	}

}
