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
				System.out.println("일본어를 가르칩니다.");
			}
		};
		//익명 객체, 익명 클래스
		CodingTeacher ct = new CodingTeacher() {
			@Override
			public void Teach() {
				System.out.println("파이썬을 가르칩니다.");	
			}
			@Override
			public void computerSetting() {
				System.out.println("파이썬을 깝니다.");
			}
		};
		
		
		Teacher[] arr = new Teacher[3];
		arr[0] = new Teacher() {
			@Override
			public void Teach() {
				System.out.println("물리를 물리적으로 가르친다.");
			}
		};
		arr[1] = new CodingTeacher() {
			@Override
			public void Teach() {
				System.out.println("C#을 가르칩니다.");
			}
			@Override
			public void computerSetting() {
				System.out.println("맥 금지 ㅡㅡ");	
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
