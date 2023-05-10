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
	//new 이용해서 메모리가 할당되어야 하고, 각 속성의 내용이 있어야 한다.
	//String을 리턴하게 할 수 있다.
	static String showStudent(Student tempStudent)
	{
		return tempStudent.name+","+tempStudent.gender+","+tempStudent.beonho;
	}
	//void를 이용할 수도 있다.
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
					students.remove(i);//번호중복된 것을 지우는 것임
					System.out.println("번호중복!");
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















