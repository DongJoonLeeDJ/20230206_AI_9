package mytest.myjava.mycode;

import java.util.Scanner;

public class YourJava {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a  = 35;//�⺻������ ������ int
		short aa = (short)10;
		double b = 3.14;//�⺻������ �Ǽ��� double��
		float bb = (float)3.1415;
		char c = 'A';
		char cc = '��';//java�� char�� unicode(�ѱ� ��)��
		//�� ���� ������ ����. ������ char�� 2byte�� �����ϱ� ����
		
		boolean d = false;
		d = true;
		
		String f = "�ȳ��ϼ���~!";
		f += " �̵��� ������~! ";	 //���ڿ� �̾���̱�	
		System.out.println(f);
		System.out.println(a);
		
		//�Է�
		//import Scanner(java.util)
		Scanner s = new Scanner(System.in);
		System.out.println("���� ���ð� �Ẹ����.");
		f += s.nextLine();
		System.out.println("���� ���?");
		int age = s.nextInt(); //c�� scanf�� ���� ��������
		s.nextLine(); //�̰� �ϳ� �� ���ֵ��� ���ʿ� nextInt�� �� ����.
		System.out.println("���� �¾��?");
		int birthYear = Integer.parseInt(s.nextLine());
		System.out.println("�� ���� : " + (2023-birthYear));
		
		

	}

}
