package studyjava04_object_class;

public class Student {
	private int age;
	private String name;
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Student(int age, String name) {
		this.age = age;
		this.name = name;
	}
	
	//Object 클래스에서 기본으로 제공하는 toString함수
	//즉 Student타입의 자료를 문자열로 변환하는 방법
	@Override
	public String toString() {
//		super.toString()
		return "이름:"+this.name+",나이:"+this.age;
	}
	//Student타입을 어떻게 비교할지 정하는 것
	//이름과 나이까지 똑같아야지 같은 학생으로 간주하는 것!
	@Override
	public boolean equals(Object obj) {
		return this.name.equals(((Student)obj).getName()) 
				&& this.age==((Student)obj).getAge();
	}

}
