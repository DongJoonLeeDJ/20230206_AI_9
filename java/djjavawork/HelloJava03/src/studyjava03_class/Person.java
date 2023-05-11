package studyjava03_class;
//public : ������
//�ٸ� class������ ������ ����
//�ٸ� ��Ű�������� ������ ����

//private : ��������, ������
//�ش� class �ȿ����� ������ ������
//�ٸ� class���� ������ �Ұ���
public class Person {
	private String name;
	private String gender;
	private int beonho;

	
	//Getter Setter(���� ���͸� �ݵ�� ����� �ش�.)
	//alt shift s ������ rŰ�� ������.
	//Select All Ŭ�� �� Generate������.
	
	//���콺 ������ Ŭ�� -> �ҽ� -> Generate Getter and Setter Ŭ��
	//Select All Ŭ�� �� Generate������.
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;//this.~~ : �ش� Ŭ������ �Ӽ�
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
			System.out.println("���� �� �˴ϴ�.");
			beonho = 0;
		}
		this.beonho = beonho;
	}
	
	//������
	//�����ڴ� �����ε��� �ȴ�.
	
	//alt shift s ������ o 
	//Ȥ�� ���콺 ������ Ŭ��->Source -> Generate Construct using Fields
	//���� �л��� ������ ���� �𸣰�, �ϴ� ����ٸ�?

	
	//������
	//����Ÿ���� ���� Ŭ������ �̸��� �Ȱ��� �޼ҵ�
	//�����ε��� ������ �ȴ�.
	//new Ű���� �̿��ؼ� �޸𸮿� ������ �Ҵ�� �� �� �� ȣ��Ǵ� �޼ҵ�
	
	//�̰�... �ƹ� �͵� ���� ������
	//�̰� ���� ���� �������� �ʾƵ� �ڵ����� �Ͻ������� �Ϲ������� ������� �ִ�.
	public Person() {
		//Omit~~~ �̰� ������ super�� �� ������ �ϱ�
		//super(); //���߿� ������ ����
	}
	//���� �̸��� �ȴٸ�?

	public Person(String name) {
		this.name = name;
	}
	//���� ���δ� �˰� �ִٸ�?
	public Person(String name, String gender, int beonho) {
		this.name = name;
		this.gender = gender;
		this.beonho = beonho;
	}
}
