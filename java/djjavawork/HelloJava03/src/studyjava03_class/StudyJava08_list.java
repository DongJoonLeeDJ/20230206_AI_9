package studyjava03_class;

import java.util.ArrayList;
import java.util.Scanner;

public class StudyJava08_list {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		ArrayList<Student> students = 
				new ArrayList<Student>();//ó���� ���� 0
		//Student[] students = new Student[5];
		for(int i = 0; i<5;i++)
		{
			Student tempStu = new Student();
			System.out.println("�л��� ��ȣ?");
			tempStu.beonho = 
					Integer.parseInt(s.nextLine());
			boolean isDuplicate = false;//flag(���) ����
			for(int j = 0; j<i; j++)
			{
				if(tempStu.beonho==students.get(j).beonho)
				{
					System.out.println("�ߺ�!!!");
					isDuplicate = true;
					i--;
					break;
				}
			}
			if(isDuplicate)
				continue;
			System.out.println("�л��� �̸�?");
			tempStu.name = s.nextLine();
			System.out.println("�л��� ����?");
			tempStu.gender = s.nextLine();
			
			students.add(tempStu);
		}
		
		//foreach ���� ctrl space ����
		for (Student student : students) {
			System.out.print(student.name+",");
			System.out.print(student.gender+",");
			System.out.println(student.beonho);
			System.out.println("-------------");
			
		}
	}


}
