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
	//�����̶� �ϸ�, �Դ� ����� �ִ�.
	//�����̶�� �̸��� ������ ����.
	//�ٸ�... ������ ��ӹ޾Ҵٸ� �ݵ�� eat�� ������ �ؾ� �Ѵ�.
	public abstract void eat();
}
