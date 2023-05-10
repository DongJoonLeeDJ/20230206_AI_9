package studyjava03_class;

import java.util.Scanner;

public class StudyJava09_create_student {

//	오버로딩이 적용됨
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
			if(number<0)//temp.number가 아니고 number를 체크해야 함
			{
				System.out.println("번호를 다시 입력해주세요.");
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
			System.out.println("번호?");
			temp.beonho 
			= Integer.parseInt(s.nextLine());
			if(temp.beonho<0)
			{
				System.out.println("번호 입력 다시하세요.");
				continue;
			}
			System.out.println("이름?");
			temp.name = s.nextLine();
			System.out.println("성별?");
			temp.gender = s.nextLine();
			break;
		}
		return temp;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s1 = createStudent();
		Student s2 = createStudent("정홍근","남",1);
		Student s3 = createStudent("이동준","남",-1);
		
		System.out.println
		(s1.name+","+s1.gender+","+s1.beonho);
		System.out.println
		(s2.name+","+s2.gender+","+s2.beonho);
		System.out.println
		(s3.name+","+s3.gender+","+s3.beonho);
		

	}

}
