package studyjava03_class;

import java.util.ArrayList;
import java.util.Scanner;

public class StudyJava11_students2 {
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
	//new �̿��ؼ� �޸𸮰� �Ҵ�Ǿ�� �ϰ�, �� �Ӽ��� ������ �־�� �Ѵ�.
	//String�� �����ϰ� �� �� �ִ�.
	static String showStudent(Student tempStudent)
	{
		return tempStudent.name+","+tempStudent.gender+","+tempStudent.beonho;
	}
	//void�� �̿��� ���� �ִ�.
	static void viewStudent(Student tempStudent)
	{
		System.out.println(tempStudent.name+","+tempStudent.gender+","+tempStudent.beonho);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Student> students = new ArrayList<Student>();
		for(int i = 0; i<3; i++)
		{
			Student temp = createStudent();
			students.add(temp);
			for(int j = 0; j<i; j++)
			{
				if(temp.beonho == students.get(j).beonho)
				{
					students.remove(i);//��ȣ�ߺ��� ���� ����� ����
					System.out.println("��ȣ�ߺ�!");
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
		for(Student item : students)
		{
			System.out.println(showStudent(item));
			viewStudent(item);
			System.out.println("----");
		}
	}

}















