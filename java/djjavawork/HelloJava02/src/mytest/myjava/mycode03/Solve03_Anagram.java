package mytest.myjava.mycode03;

import java.util.*;
//애너그램(어구전철)
public class Solve03_Anagram {

	public static void main(String[] args) {
		System.out.println("첫번째 문자열 입력");
		Scanner s = new Scanner(System.in);
		String s1 = s.nextLine();
		System.out.println("두번째 문자열 입력");
		String s2 = s.nextLine();
		if(s1.length() != s2.length())
		{
			System.out.println("얘네 둘이 다름 ㅇㅇ");
			return; //main을 종료시킴
		}
		boolean isSame = true;
		char[] c1 = s1.toCharArray();
		char[] c2 = s2.toCharArray();
		Arrays.sort(c1);
		Arrays.sort(c2);
		for(int i = 0; i<c1.length; i++)
		{
			if(c1[i]!=c2[i])
			{
				isSame = false;
				break;
			}
		}
		if(isSame)
			System.out.println("똑같은 문자열임");
		else
			System.out.println("다른 문자열임");

	}

}
