package studyjava04_object_class;

public class OfficeWorker extends Person{
	
	private String sabeon;

	public OfficeWorker(int age, String name) {
		super(age, name);
		// TODO Auto-generated constructor stub
	}

	public String getSabeon() {
		return sabeon;
	}

	public void setSabeon(String sabeon) {
		this.sabeon = sabeon;
	}
	
	@Override
	public String toString() {
		return String.format("�̸�:%s, ����:%d, ���:%s",
				getName(),getAge(),this.sabeon);		
		// TODO Auto-generated method stub
		//return super.toString();
	}
	
	//�̸�, ���� �ʿ���� ������θ� ���ϸ� ��
	@Override
	public boolean equals(Object obj) {
		return ((OfficeWorker)obj).sabeon.equals(this.sabeon);
		// TODO Auto-generated method stub
		//return super.equals(obj);
	}

}
