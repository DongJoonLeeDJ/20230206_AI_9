package studyjava05_protected;

import studyjava04_extends.MasterStudent;

public class StudyJava09_HellSchool {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MasterStudent m1 = new MasterStudent
				("이동준", 35, "2009038033", "오박사");
		DoctorStudent d1 = new DoctorStudent
				("정홍근", 60, "1999038011", 
						"이동준", "양자역학");
		
		//다른 패키지 안에선 protected 붙어 있으면 안 된다.
		//m1.thesisTopic="얼굴인식";
		//m1.writeThesis();
		
		//단, DoctorStudent는 MasterStudent를 상속받았으므로
		//접근이 된다.
		d1.study();
		
		
	}

}
