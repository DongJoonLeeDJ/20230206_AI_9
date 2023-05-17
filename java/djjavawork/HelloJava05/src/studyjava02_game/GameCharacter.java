package studyjava02_game;

public class GameCharacter {
	
	//�ν��Ͻ� ����
	private String id; //���� ĳ������ ���̵�
	//class, role, job
	private String job; //ĳ���� ����
	private int level; //ĳ���� ����
	
	//Ŭ���� ����
	private static int count; //�ش� ������ �� �ο�
	//alt shift s ������ o
	//Ȥ�� ���콺 ������ -> Source -> Generate Constructor		
//public GameCharacter() {}
	
	public GameCharacter(String id) {
		this.id = id;
		this.job = "novice";
		this.level = 1;
		count++;//count�� ó���� 0������ ĳ���� ���� �� ���� ����
	}

	public GameCharacter(String id, String job) {
		this.id = id;
		this.job = job;
		this.level = 1;
		count++;//count�� ó���� 0������ ĳ���� ���� �� ���� ����
	}

	//alt shift s ������ r 
	// ���콺 ������ -> Source -> Generate Getter and Setter
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
	//Id�� count�� �о���̴� �͸� �˴ϴ�.
	public String getId() {
		return id;
	}
	public static int getCount() {
		return count;
	}
	//�����ε��غ���
	//ä���� �������� �����
	//Ŭ���� �޼ҵ�
	public static void chat(String msg)
	{
		System.out.println(msg);
	}
	//�ӼӸ� ���
	public static void chat(String id, String msg) {
		System.out.println(id+"�Կ��� : "+msg);
	}
	
	//�ν��Ͻ� �޼ҵ�
	public void attack() {
		System.out.println(getId()+"���� ����!");
		//�ڹٿ����� ���ڿ� ���� �� == ���� �� �ȴ�.
		//equals�� ���ؾ� ���� ��
		//==�� �ּҸ� ���ϴ� ��
		//==�� ���ϴ� ���� ������ ���� ������ 
		//�׷��� ���� ��쵵 �ִ�.
		
		if(this.job.equals("����"))
			System.out.println("Į�� �ķ��մϴ�.");
		else if(this.job.equals("������"))
			System.out.println("���� ��������!!!");
		else
			System.out.println("��Ե� �մϴ�.");
		
	}
	
	public void printInfo()
	{
		System.out.println(getId());
		System.out.println(getLevel());
		System.out.println(getJob());
	}
	
	

}
