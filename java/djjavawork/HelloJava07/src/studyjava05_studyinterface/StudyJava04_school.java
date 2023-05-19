package studyjava05_studyinterface;

public class StudyJava04_school {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Studiable[] students = new Studiable[4];
		students[0] = new ITStudent(); //�⺻���� �޽Ĺ���� ������
		students[1] = new ElecStudent();//rest�� �������̵���
		students[2] = new ArtStudent();//rest�� �������̵���
		students[3] = new Studiable() { //�⺻���� �޽Ĺ���� ������
			
			@Override
			public void study() {
				System.out.println("�������� �ʱ��ϸ� �����մϴ�.");
			}
		};
		for (Studiable studiable : students) {
			studiable.study();
			studiable.rest();
			System.out.println("----");
		}
		
		//����
		//�޼ҵ尡 �ϳ� �ִ� �������̽��� ���ؼ��� ������ ����
		//C#���� �ַ� ���̰�, java���� ���Ե� �� 
		//�� �� �ƴ�.
		
		Studiable s = () -> {
			System.out.println("�����ϴ°̴ϴ�.");
		};
		s.study();
		
		
		
		
		
		
		
		
	}

}
