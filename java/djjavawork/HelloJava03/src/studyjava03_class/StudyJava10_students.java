package studyjava03_class;

import java.util.Scanner;

public class StudyJava10_students {
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
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student[] students = new Student[3];
		Scanner s = new Scanner(System.in);
		for(int i = 0; i<students.length;i++)
		{
			System.out.println("��ȣ?");
			int num = Integer.parseInt(s.nextLine());
			System.out.println("�̸�?");
			String name = s.nextLine();
			System.out.println("����?");
			String gender = s.nextLine();
			Student temp = createStudent(name, gender, num);
			students[i] = temp;
			for(int j = 0; j<i; j++)
			{
				if(temp.beonho==students[j].beonho)
				{
					System.out.println("��ȣ �ߺ��̶��...");
					i--;
					break;
				}
			}
		}
		for(Student item : students)
		{
			System.out.print(item.name+",");
			System.out.print(item.gender+",");
			System.out.println(item.beonho);
			System.out.println("------");
		}
	}

}
