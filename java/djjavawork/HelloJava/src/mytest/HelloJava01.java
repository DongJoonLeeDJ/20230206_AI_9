package mytest;

import java.util.Scanner;

//Scanner(�� �Է¹ޱ�) �ϴ� ��
//C�� ������� �߰��� ���� ��

public class HelloJava01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a = 10;
		double b = 3.14;
		char c = '��'; //java������ char�� 2byte
		//char ���� �ϳ��� �ѱ��� ������ �� �ִ�.
		boolean d = false;//true, false�� �����ϴ� �ڷ���
		String f = "�ȳ��ϼ���";//ū����ǥ�� ������ ���ڿ�(=����)��
		//����. �ѱ��� �̻��� ������ ����
		//+
		//�ܼ��� ���� ���� ���� ������, ���ڿ��� �̾���� �� �ִ�.(jsó��)
		f = f + " �̼����� !";
		System.out.println(f);
		
		//�Է¹޴� ���
		Scanner s = new Scanner(System.in);
		f = s.nextLine();//s.nextLine() : StringŸ�� �Է¹���
		System.out.println(f+"�Ե� ȯ���ؿ�!");
		
		int random = ((int)Math.random()*45)+1;//1~45
		System.out.println(random);
		
		//c�� int lotto[6]
		int[] lotto = new int[6];
		lotto[0] = random;
		for(int i = 0; i<lotto.length; i++)
		{
			lotto[i] = i*10;
			System.out.println(lotto[i]);
		}
		
		

	}

}
