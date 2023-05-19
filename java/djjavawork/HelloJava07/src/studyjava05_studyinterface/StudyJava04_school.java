package studyjava05_studyinterface;

public class StudyJava04_school {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Studiable[] students = new Studiable[4];
		students[0] = new ITStudent(); //기본적인 휴식방법을 선택함
		students[1] = new ElecStudent();//rest를 오버라이딩함
		students[2] = new ArtStudent();//rest를 오버라이딩함
		students[3] = new Studiable() { //기본적인 휴식방법을 선택함
			
			@Override
			public void study() {
				System.out.println("교과서에 필기하며 공부합니다.");
			}
		};
		for (Studiable studiable : students) {
			studiable.study();
			studiable.rest();
			System.out.println("----");
		}
		
		//람다
		//메소드가 하나 있는 인터페이스에 대해서만 가능한 문법
		//C#에서 주로 쓰이고, java에는 도입된 지 
		//얼마 안 됐다.
		
		Studiable s = () -> {
			System.out.println("공부하는겁니다.");
		};
		s.study();
		
		
		
		
		
		
		
		
	}

}
