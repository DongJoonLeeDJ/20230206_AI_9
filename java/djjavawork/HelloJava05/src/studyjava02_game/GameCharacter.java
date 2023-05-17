package studyjava02_game;

public class GameCharacter {
	
	//인스턴스 변수
	private String id; //게임 캐릭터의 아이디
	//class, role, job
	private String job; //캐릭터 직업
	private int level; //캐릭터 레벨
	
	//클래스 변수
	private static int count; //해당 서비스의 총 인원
	//alt shift s 누르고 o
	//혹은 마우스 오른쪽 -> Source -> Generate Constructor		
//public GameCharacter() {}
	
	public GameCharacter(String id) {
		this.id = id;
		this.job = "novice";
		this.level = 1;
		count++;//count가 처음엔 0이지만 캐릭터 만들 때 마다 증가
	}

	public GameCharacter(String id, String job) {
		this.id = id;
		this.job = job;
		this.level = 1;
		count++;//count가 처음엔 0이지만 캐릭터 만들 때 마다 증가
	}

	//alt shift s 누르고 r 
	// 마우스 오른쪽 -> Source -> Generate Getter and Setter
	public String getJob() {
		return job;
	}
	public void setJob(String job) {
		this.job = job;
	}
	public int getLevel() {
		return level;
	}
	public void setLevel(int level) {
		this.level = level;
	}
	//Id와 count는 읽어들이는 것만 됩니다.
	public String getId() {
		return id;
	}
	public static int getCount() {
		return count;
	}
	//오버로딩해봤음
	//채팅은 공통적인 기능임
	//클래스 메소드
	public static void chat(String msg)
	{
		System.out.println(msg);
	}
	//귓속말 기능
	public static void chat(String id, String msg) {
		System.out.println(id+"님에게 : "+msg);
	}
	
	//인스턴스 메소드
	public void attack() {
		System.out.println(getId()+"님의 공격!");
		//자바에서는 문자열 비교할 때 == 쓰면 안 된다.
		//equals로 비교해야 값을 비교
		//==은 주소를 비교하는 것
		//==이 원하는 데로 동작할 때도 있지만 
		//그렇지 않은 경우도 있다.
		
		if(this.job.equals("전사"))
			System.out.println("칼로 후려팹니다.");
		else if(this.job.equals("마법사"))
			System.out.println("강력 마법공격!!!");
		else
			System.out.println("어떻게든 팹니다.");
		
	}
	
	public void printInfo()
	{
		System.out.println(getId());
		System.out.println(getLevel());
		System.out.println(getJob());
	}
	
	

}
