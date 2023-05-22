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
	//�̷��� �� ���� ���� �������̵��ؾ� Set���� 
	//���θ� ������ �� �ְ� �ȴ�.
	//hashCode = ������ �ּڰ� ���� ��(�޸� ���� ������)
	@Override
	public int hashCode() {
		// TODO Auto-generated method stub
		//return super.hashCode();
		return sabeon.hashCode(); //������θ� �񱳸� �ϰڴ�!
	}
	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		//return super.equals(obj);
		return ((Employee)(obj)).getSabeon().equals(getSabeon());
	}
}
