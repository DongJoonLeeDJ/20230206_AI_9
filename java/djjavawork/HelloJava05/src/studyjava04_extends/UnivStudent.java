package studyjava04_extends;

//����� ��~�� Ŭ�������� ������ Object��� �̸��� Ŭ�����Դϴ�.
//���⼭ UnivStudent�� SubClass Ȥ�� �ڼ� Ŭ������� �Ҹ���
public class UnivStudent extends Student {

	public UnivStudent(String name, int age) {
		super(name, age); //super = ����Ŭ����
		//�� Student�� �˴ϴ�.
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
	
	//�������̵� != �����ε�
	//Overwrite�� ������ ����ϴ�, ����� �Ѵٰ� ���� �ȴ�.
	//�� Student�� study�� �����, �ڽŸ��� study�� �����Ѵ�.
	@Override
	public void study() {
		// TODO Auto-generated method stub
		super.study(); //����Ŭ������ �ִ� study�� �ҷ�����
		System.out.println(getHakbeon()+"�й��� �������̽ô�");
		System.out.println("���л�ó�� �����ϽŴ�");
	}
	
}
