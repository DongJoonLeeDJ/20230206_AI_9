package studyjava03_class;
//public : 공공의
//다른 class에서도 접근이 가능
//다른 패키지에서도 접근이 가능

//private : 개인적인, 사적인
//해당 class 안에서는 접근이 되지만
//다른 class에선 접근이 불가능
public class Person {
	private String name;
	private String gender;
	private int beonho;

	
	//Getter Setter(게터 세터를 반드시 만들어 준다.)
	//alt shift s 누르고 r키를 누른다.
	//Select All 클릭 후 Generate누른다.
	
	//마우스 오른쪽 클릭 -> 소스 -> Generate Getter and Setter 클릭
	//Select All 클릭 후 Generate누른다.
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;//this.~~ : 해당 클래스의 속성
	}
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public int getBeonho() {
		return beonho;
	}
	public void setBeonho(int beonho) {
		if(beonho<0)
		{
			System.out.println("음수 안 됩니다.");
			beonho = 0;
		}
		this.beonho = beonho;
	}
	
	//생성자
	//생성자는 오버로딩이 된다.
	
	//alt shift s 누르고 o 
	//혹은 마우스 오른쪽 클릭->Source -> Generate Construct using Fields
	//만약 학생의 정보를 전혀 모르고, 일단 만든다면?

	
	//생성자
	//리턴타입이 없고 클래스랑 이름이 똑같은 메소드
	//오버로딩이 적용이 된다.
	//new 키워드 이용해서 메모리에 변수가 할당될 때 그 때 호출되는 메소드
	
	//이거... 아무 것도 없는 생성자
	//이건 내가 따로 적어주지 않아도 자동으로 암시적으로 암묵적으로 만들어져 있다.
	public Person() {
		//Omit~~~ 이거 눌러서 super는 안 나오게 하기
		//super(); //나중에 설명할 개념
	}
	//만약 이름만 안다면?

	public Person(String name) {
		this.name = name;
	}
	//만약 전부다 알고 있다면?
	public Person(String name, String gender, int beonho) {
		this.name = name;
		this.gender = gender;
		this.beonho = beonho;
	}
}
