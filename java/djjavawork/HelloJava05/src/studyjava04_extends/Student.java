package studyjava04_extends;

public class Student {
	private String name;
	private int age;
	//Getter, Setter
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	//생성자
	public Student(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	public void sleep() {
		System.out.println(getName()+"학생은 잡니다.");
	}
	
	public void study() {
		System.out.println(getAge()+"살 답게 공부합니다!");
	}
	

}
