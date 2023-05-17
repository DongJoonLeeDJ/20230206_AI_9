package studyjava04_extends;

public class MasterStudent extends UnivStudent{
	
	private String profName;
	
	//���� ��Ű�������� publicó�� ������
	//�ٸ� ��Ű������ �ݵ��! �̰� ��ӹ��� �͵鸸 ���ٰ� �� �� �־��!
	protected String thesisTopic; //�� ����
	
	protected void writeThesis() {
		System.out.println(getProfName()+"�������� ������ �޾�");
		System.out.println("���� ���ϴ�. ������ �ֽ� �� �ο�");
		System.out.println("���ڴ� �� ������. ������ �߿�ġ �ʾ�.");
	}
	
	
	
	public String getProfName() {
		return profName;
	}
	public void setProfName(String profName) {
		this.profName = profName;
	}
	public MasterStudent(String name, int age) {
		super(name, age);
		// TODO Auto-generated constructor stub
	}
	public MasterStudent(String name, int age, String hakbeon) {
		super(name, age, hakbeon);
		// TODO Auto-generated constructor stub
	}
	public MasterStudent(String name, int age, String hakbeon, String profName) {
		super(name, age, hakbeon);
		this.profName = profName;
	}
	
	public void cleanRoom()	{
		System.out.println
		(getProfName()+"������ �� ������ ���� �ҹ� ���� ����");
	}
	public void cleanRoom(String name)	{
		System.out.println
		(getProfName()+"�������� "+name+"�� û��");
	}
	
	@Override
	public void study() {
		//super.study(); //����Ŭ������ �ִ� study�� �ҷ�����
		System.out.println(getHakbeon()+"�й��� �������̽ô�");
		System.out.println("���п���ó�� �����Ѵ�");
	}
	
	@Override
	public void sleep() {
		// TODO Auto-generated method stub
		super.sleep();
		System.out.println(getProfName()+"������ �������� ��ٶ�ٿ��� �ܴ�.");
		
	}
	

}
