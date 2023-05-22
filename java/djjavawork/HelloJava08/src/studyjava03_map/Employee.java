package studyjava03_map;

public class Employee {

	private String name;
	private String sabeon;
	private int age;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getSabeon() {
		return sabeon;
	}
	public void setSabeon(String sabeon) {
		this.sabeon = sabeon;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public Employee(String name, String sabeon, int age) {
		this.name = name;
		this.sabeon = sabeon;
		this.age = age;
	}
	//이렇게 두 개를 같이 오버라이딩해야 Set에서 
	//서로를 구분할 수 있게 된다.
	//hashCode = 일종의 주솟값 같은 것(메모리 상의 고유값)
	@Override
	public int hashCode() {
		// TODO Auto-generated method stub
		//return super.hashCode();
		return sabeon.hashCode(); //사번으로만 비교를 하겠다!
	}
	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		//return super.equals(obj);
		return ((Employee)(obj)).getSabeon().equals(getSabeon());
	}
}
