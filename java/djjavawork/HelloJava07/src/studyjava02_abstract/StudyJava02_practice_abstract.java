package studyjava02_abstract;

public class StudyJava02_practice_abstract {

	public static void main(String[] args) {
		Teacher t1 = new MathTeacher();
		Teacher j1 = new JavaProgrammingTeacher();
		ProgrammingTeacher p1 = new JavaProgrammingTeacher();
		Teacher t2 = new ProgrammingTeacher();
		CodingTeacher c = new CTeacher();
		Teacher tt = new Teacher() {
			@Override
			public void Teach() {
				System.out.println("�Ϻ�� ����Ĩ�ϴ�.");
			}
		};
		//�͸� ��ü, �͸� Ŭ����
		CodingTeacher ct = new CodingTeacher() {
			@Override
			public void Teach() {
				System.out.println("���̽��� ����Ĩ�ϴ�.");	
			}
			@Override
			public void computerSetting() {
				System.out.println("���̽��� ���ϴ�.");
			}
		};
		
		
		Teacher[] arr = new Teacher[3];
		arr[0] = new Teacher() {
			@Override
			public void Teach() {
				System.out.println("������ ���������� ����ģ��.");
			}
		};
		arr[1] = new CodingTeacher() {
			@Override
			public void Teach() {
				System.out.println("C#�� ����Ĩ�ϴ�.");
			}
			@Override
			public void computerSetting() {
				System.out.println("�� ���� �Ѥ�");	
			}
		};
		arr[2] = t1;
		
		for (Teacher teacher : arr) {
			if(teacher instanceof CodingTeacher)
				((CodingTeacher)teacher).computerSetting();
			teacher.Teach();
		}
	}

}
