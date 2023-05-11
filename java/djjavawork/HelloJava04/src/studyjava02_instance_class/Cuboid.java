package studyjava02_instance_class;
//직육면체
//z를 static으로 해서 모든 Cuboid들한테 영향을 끼칠 것
public class Cuboid {
	private int w; //인스턴스 변수
	private int h;
	private static int z; //클래스 변수

	//alt shift s 누르고 r키 누르면
	//Generate Getter and Setter 클릭
	//마우스 오른쪽 누르고 Source 클릭 하고 
	//Generate Getter and Setter 클릭
	
	public int getW() {
		return w;
	}
	public void setW(int w) {
		this.w = w;
	}
	public int getH() {
		return h;
	}
	public void setH(int h) {
		this.h = h;
	}
	//클래스 메소드
	//static이 붙은 메소드 안에는 static이 붙은 메소드나
	//static이 붙은 변수만 쓸 수 있다.
	//참고로 static이 없는 메소드 안에는 static 있는 거 들어갈 수 있다.
	public static int getZ() {
		return z;
	}
	public static void setZ(int z) {
		Cuboid.z = z;
	}
	public int getVolume() {
		return z*this.w*this.h;
	}
	public int getArea() {
		return this.w*this.h;
	}
	
	//원래 기본으로 만들어지는 생성자인 데,
	//매개변수 있는 생성자를 만들 게 되면 사라지므로
	//명시적으로 만들어준 것!
	public Cuboid() {}
	//정육면체
	public Cuboid(int wh)
	{
		this.w = wh;
		this.h = wh;
	}
	//하나의 독립된 w와 h를 갖는 직육면체
	public Cuboid(int w, int h)
	{
		this.w = w;
		this.h = h;
	}
	//이 직육면체가 만들어지면 모든 직육면체들의 높이에 영향을 미친다.
	public Cuboid(int w, int h, int z)
	{
		this.w = w;
		this.h = h;
		Cuboid.z= z;
	}
	
	
	
	
	
	
	
	
}
