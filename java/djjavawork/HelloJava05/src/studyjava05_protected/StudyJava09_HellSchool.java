package studyjava05_protected;

import studyjava04_extends.MasterStudent;

public class StudyJava09_HellSchool {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MasterStudent m1 = new MasterStudent
				("�̵���", 35, "2009038033", "���ڻ�");
		DoctorStudent d1 = new DoctorStudent
				("��ȫ��", 60, "1999038011", 
						"�̵���", "���ڿ���");
		
		//�ٸ� ��Ű�� �ȿ��� protected �پ� ������ �� �ȴ�.
		//m1.thesisTopic="���ν�";
		//m1.writeThesis();
		
		//��, DoctorStudent�� MasterStudent�� ��ӹ޾����Ƿ�
		//������ �ȴ�.
		d1.study();
		
		
	}

}
