package studyjava03_class;

import java.util.Scanner;

public class StudyJava07_arr {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		Student[] students = new Student[5];
		for(int i = 0; i<students.length;i++)
		{
			Student tempStu = new Student();
			System.out.println("�л��� ��ȣ?");
			tempStu.beonho = 
					Integer.parseInt(s.nextLine());
			boolean isDuplicate = false;//flag(���) ����
			for(int j = 0; j<i; j++)
			{
				if(tempStu.beonho==students[j].beonho)
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
			students[i] = tempStu;
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
