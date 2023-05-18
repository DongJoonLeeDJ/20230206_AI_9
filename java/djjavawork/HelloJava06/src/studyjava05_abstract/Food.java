package studyjava05_abstract;

public abstract class Food {

	private int price;
	private String name;
	public int getPrice() {
		return price;
	}
	public void setPrice(int price) {
		this.price = price;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	//음식이라 하면, 먹는 방법이 있다.
	//음식이라는 이름의 음식은 없다.
	//다만... 음식을 상속받았다면 반드시 eat은 구현을 해야 한다.
	public abstract void eat();
}
