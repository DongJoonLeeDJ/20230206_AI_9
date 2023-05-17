package studyjava05_protected;

import studyjava04_extends.MasterStudent;

public class DoctorStudent extends MasterStudent {
	
	@Override
	public void study() {
		// TODO Auto-generated method stub
		super.study();
		writeThesis();
		System.out.println("살려줘...");
		System.out.println(thesisTopic+"너무 어려워...ㅠㅠ");
	}

	public DoctorStudent(String name, int age, String hakbeon, String profName, String thesis) {
		super(name, age, hakbeon, profName);
		this.thesisTopic = thesis;
		// TODO Auto-generated constructor stub
	}

}
