package mytest.myjava.mycode03;

import java.util.*;
//�ֳʱ׷�(���ö)
public class Solve03_Anagram {

	public static void main(String[] args) {
		System.out.println("ù��° ���ڿ� �Է�");
		Scanner s = new Scanner(System.in);
		String s1 = s.nextLine();
		System.out.println("�ι�° ���ڿ� �Է�");
		String s2 = s.nextLine();
		if(s1.length() != s2.length())
		{
			System.out.println("��� ���� �ٸ� ����");
			return; //main�� �����Ŵ
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
			System.out.println("�Ȱ��� ���ڿ���");
		else
			System.out.println("�ٸ� ���ڿ���");

	}

}
