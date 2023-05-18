package studyjava04_object_class;

import java.util.ArrayList;
import java.util.Scanner;

public class StudyJava06_Company {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person[] p = new Person[5];
		OfficeWorker[] workers = new OfficeWorker[5];
		Scanner s = new Scanner(System.in);
		for(int i = 0; i<5; i++)
		{
			System.out.println("회사원의 사번은?");
			String sabeon = s.nextLine();
			System.out.println("이름이 뭐니?");
			String name = s.nextLine();
			System.out.println("나이는 몇살?");
			int age = Integer.parseInt(s.nextLine());
			workers[i] = new OfficeWorker(age, name);
			workers[i].setSabeon(sabeon);
			boolean isDuplicate = false;
			for(int j = 0; j<i; j++)
			{
				if(workers[i].equals(workers[j]))
				{
					System.out.println("중복!!!");
					isDuplicate=true;
					i--;
					break;
				}
			}
			if(isDuplicate)
				continue;
			System.out.println(workers[i].toString());
		}
		ArrayList<OfficeWorker> arroffice 
		= new ArrayList<OfficeWorker>();
		for(int i = 0; i<5; i++)
		{
			System.out.println("회사원의 사번은?");
			String sabeon = s.nextLine();
			System.out.println("이름이 뭐니?");
			String name = s.nextLine();
			System.out.println("나이는 몇살?");
			int age = Integer.parseInt(s.nextLine());
			arroffice.add(new OfficeWorker(age, name));
			arroffice.get(i).setSabeon(sabeon);
			boolean isDuplicate = false;
			for(int j = 0; j<i; j++)
			{
				if(arroffice.get(i).equals(workers[j]))
				{
					System.out.println("중복!!!");
					arroffice.remove(i);
					isDuplicate=true;
					i--;
					break;
				}
			}
			if(isDuplicate)
				continue;
			System.out.println(arroffice.get(i).toString());
		}
	}

}







