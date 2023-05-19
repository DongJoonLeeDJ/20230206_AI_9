package studyjava06_basic_interface;

//Cloneable : 깊은 복사용
//복사를 할 때 값만 복사하고, 주소지는 복사하지 않는 것
//주소지만 복사하는 걸 얕은 복사라고 함
//Deep Copy, Shallow Copy

//Comparable : 비교하는 기준을 세움
//지금 여기선 학생의 나이순으로 정렬을 한다고 가정하자
//그럴 경우 age를 기준으로 비교하게끔 해줘야 한다.
public class Student implements Cloneable, Comparable<Student>{

	private String num; //PK
	private String name;
	private int age;
	
	//인터페이스 Cloneable 적고, 그 다음에 clone 오버라이딩하기
	//다른 패키지에서도 모두 활용하려면 protected를 모두 public으로 바꿔야 함
	//Cloneable의 clone 메소드는 이미 default로 구현되어 있으나
	//오버라이딩을 해야 쓸 수 있다.
	@Override
	public Object clone() throws CloneNotSupportedException {
		// TODO Auto-generated method stub
		return super.clone();
	}
	@Override
	public int compareTo(Student o) {
		// TODO Auto-generated method stub
		return this.age-o.getAge();
		//0 양수 음수냐에 따라서 정렬이 된다.
	}
	
	public Student(String num, String name, int age) {
		super();//Object클래스의 생성자 즉 조상 클래스의 생성자
		this.num = num;
		this.name = name;
		this.age = age;
	}
	public String getNum() {
		return num;
	}
	public void setNum(String num) {
		this.num = num;
	}
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

	
}
