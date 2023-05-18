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
		return String.format("이름:%s, 나이:%d, 사번:%s",
				getName(),getAge(),this.sabeon);		
		// TODO Auto-generated method stub
		//return super.toString();
	}
	
	//이름, 나이 필요없고 사번으로만 비교하면 끝
	@Override
	public boolean equals(Object obj) {
		return ((OfficeWorker)obj).sabeon.equals(this.sabeon);
		// TODO Auto-generated method stub
		//return super.equals(obj);
	}

}
