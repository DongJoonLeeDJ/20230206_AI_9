package studyjava02_abstract;

public class CTeacher extends CodingTeacher{

	@Override
	public void computerSetting() {
		System.out.println("컴퓨터가 안 되면, 껐다 켜세요.");
	}

	@Override
	public void Teach() {
		System.out.println("printf부터 합시다.");	
	}

}
