package studyjava04_extends;

//참고로 모~든 클래스들의 조상은 Object라는 이름의 클래스입니다.
//여기서 UnivStudent는 SubClass 혹은 자손 클래스라고 불리움
public class UnivStudent extends Student {

	public UnivStudent(String name, int age) {
		super(name, age); //super = 조상클래스
		//즉 Student가 됩니다.
	}

	private String hakbeon;

	public String getHakbeon() {
		return hakbeon;
	}

	public void setHakbeon(String hakbeon) {
		this.hakbeon = hakbeon;
	}

	public UnivStudent(String name, int age, String hakbeon) {
		super(name, age);
		this.hakbeon = hakbeon;
	}
	
	//오버라이드 != 오버로딩
	//Overwrite랑 발음이 비슷하니, 덮어쓰기 한다고 보면 된다.
	//즉 Student의 study를 덮어쓰고, 자신만의 study를 수행한다.
	@Override
	public void study() {
		// TODO Auto-generated method stub
		super.study(); //조상클래스에 있는 study를 불러들임
		System.out.println(getHakbeon()+"학번님 공부중이시다");
		System.out.println("대학생처럼 공부하신다");
	}
	
}
