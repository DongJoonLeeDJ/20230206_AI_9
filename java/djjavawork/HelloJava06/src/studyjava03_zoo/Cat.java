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
		System.out.println("야옹야옹");
	}
	@Override
	public void sleep() {
		//name은 private이라서 자손이라도 접근이 안 됨
		//따라서 public이 붙은 메소드를 통해서만 읽거나 쓰는 것이 가능
		System.out.println("이름:"+getName());//The field Animal.name is not visible
		System.out.println(eyeColor+"색 눈을 감는다.zZZ...");
	}

}
