package studyjava03_class;

import java.util.Scanner;

public class StudyJava09_create_student {

//	�����ε��� �����
//	createStudent(String,String,int)
//	createStudent()
	static Student createStudent(String name, String gender, int number)
	{
		Scanner s = new Scanner(System.in);
		Student temp = new Student();
		while(true)
		{
			temp.name = name;
			temp.gender = gender;
			if(number<0)//temp.number�� �ƴϰ� number�� üũ�ؾ� ��
			{
				System.out.println("��ȣ�� �ٽ� �Է����ּ���.");
				number = Integer.parseInt(s.nextLine());	
				//temp.beonho = s.nextInt();
				continue;
			}
			temp.beonho = number;
			break;
			
		}
		return temp;
	}
	static Student createStudent()
	{
		Student temp = new Student();
		Scanner s = new Scanner(System.in);
		while(true)
		{
			System.out.println("��ȣ?");
			temp.beonho 
			= Integer.parseInt(s.nextLine());
			if(temp.beonho<0)
			{
				System.out.println("��ȣ �Է� �ٽ��ϼ���.");
				continue;
			}
			System.out.println("�̸�?");
			temp.name = s.nextLine();
			System.out.println("����?");
			temp.gender = s.nextLine();
			break;
		}
		return temp;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s1 = createStudent();
		Student s2 = createStudent("��ȫ��","��",1);
		Student s3 = createStudent("�̵���","��",-1);
		
		System.out.println
		(s1.name+","+s1.gender+","+s1.beonho);
		System.out.println
		(s2.name+","+s2.gender+","+s2.beonho);
		System.out.println
		(s3.name+","+s3.gender+","+s3.beonho);
		

	}

}
