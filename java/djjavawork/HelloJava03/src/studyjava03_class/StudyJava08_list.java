package studyjava03_class;

import java.util.ArrayList;
import java.util.Scanner;

public class StudyJava08_list {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		ArrayList<Student> students = 
				new ArrayList<Student>();//처음엔 길이 0
		//Student[] students = new Student[5];
		for(int i = 0; i<5;i++)
		{
			Student tempStu = new Student();
			System.out.println("학생의 번호?");
			tempStu.beonho = 
					Integer.parseInt(s.nextLine());
			boolean isDuplicate = false;//flag(깃발) 변수
			for(int j = 0; j<i; j++)
			{
				if(tempStu.beonho==students.get(j).beonho)
				{
					System.out.println("중복!!!");
					isDuplicate = true;
					i--;
					break;
				}
			}
			if(isDuplicate)
				continue;
			System.out.println("학생의 이름?");
			tempStu.name = s.nextLine();
			System.out.println("학생의 성별?");
			tempStu.gender = s.nextLine();
			
			students.add(tempStu);
		}
		
		//foreach 쓰고 ctrl space 엔터
		for (Student student : students) {
			System.out.print(student.name+",");
			System.out.print(student.gender+",");
			System.out.println(student.beonho);
			System.out.println("-------------");
			
		}
	}


}
