package studyjava03_class;

import java.util.ArrayList;
import java.util.Scanner;

public class StudyJava99_goto_example {

	public static void main(String[] args) {
		
		myout:
			for(int i = 0;;i++)//���ѹݺ�
			{
				for(int j = 0; j<5;j++)
				{
					System.out.println(i+","+j);
					if(j==4)
						break myout;
				}
			}
//	hello:
		System.out.println("�ݺ����� ��������");
//		int i = 10;
//		if(i==10)
//			break hello;
	}


}
