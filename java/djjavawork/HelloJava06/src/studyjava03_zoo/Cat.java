package studyjava03_zoo;

public class Cat extends Animal{
	private String eyeColor;
	public String getEyeColor() {
		return eyeColor;
	}
	public void setEyeColor(String eyeColor) {
		this.eyeColor = eyeColor;
	}
	public void Meow() {
		System.out.println("�߿˾߿�");
	}
	@Override
	public void sleep() {
		//name�� private�̶� �ڼ��̶� ������ �� ��
		//���� public�� ���� �޼ҵ带 ���ؼ��� �аų� ���� ���� ����
		System.out.println("�̸�:"+getName());//The field Animal.name is not visible
		System.out.println(eyeColor+"�� ���� ���´�.zZZ...");
	}

}
