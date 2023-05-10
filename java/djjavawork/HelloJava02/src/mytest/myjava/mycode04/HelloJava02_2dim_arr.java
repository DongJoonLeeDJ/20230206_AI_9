package mytest.myjava.mycode04;

import java.util.Scanner;

public class HelloJava02_2dim_arr {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] kbschool = {
				{30,5,15,100},//10Ãþ
				{100,50,0}//9Ãþ
		};
		Scanner s = new Scanner(System.in);
		int floor = 10;
		char RoomName = 'A';
		for(int i = 0; i<kbschool.length;i++)
		{
			for(int j = 0; j<kbschool[i].length; j++)
			{
				System.out.println(floor+"ÃþÀÇ "+RoomName+" °­ÀÇ½Ç¿¡´Â ¸î ¸íÀÌ ÀÖ´Â°¡?");
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
			//print¿Í printlnÀº ´Ù¸£´Ù.
			System.out.print(floor+"ÃþÀÇ Æò±Õ ÀÎ¿ø ¼ö :");
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
				String result = String.format("%dÃþ %c:%d¸í", 
						floor,RoomName,kbschool[i][j]);
				System.out.println(result);
				RoomName++;
			}
			floor--;
		}
		
		
		

	}

}
