package mytest.myjava.mycode04;

import java.util.Scanner;

public class HelloJava02_2dim_arr {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] kbschool = {
				{30,5,15,100},//10��
				{100,50,0}//9��
		};
		Scanner s = new Scanner(System.in);
		int floor = 10;
		char RoomName = 'A';
		for(int i = 0; i<kbschool.length;i++)
		{
			for(int j = 0; j<kbschool[i].length; j++)
			{
				System.out.println(floor+"���� "+RoomName+" ���ǽǿ��� �� ���� �ִ°�?");
				kbschool[i][j] = s.nextInt();
				RoomName++;
			}
			floor--;
		}
		
		int sum = 0;
		int count = 0;
		floor = 10;
		for(int i = 0; i<kbschool.length;i++)
		{
			for(int j = 0; j<kbschool[i].length;j++)
			{
				if(j+1==kbschool[i].length)
					break;
				sum += kbschool[i][j];
				count++;
			}
			//print�� println�� �ٸ���.
			System.out.print(floor+"���� ��� �ο� �� :");
			System.out.println(sum/count);
			sum=0;
			count=0;
			floor--;
		}
		
		floor=10;
		RoomName='A';
		for(int i = 0; i<kbschool.length;i++)
		{
			for(int j = 0; j<kbschool[i].length;j++)
			{
				String result = String.format("%d�� %c:%d��", 
						floor,RoomName,kbschool[i][j]);
				System.out.println(result);
				RoomName++;
			}
			floor--;
		}
		
		
		

	}

}
