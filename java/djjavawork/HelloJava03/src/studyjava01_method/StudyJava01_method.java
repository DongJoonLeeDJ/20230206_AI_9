package studyjava01_method;

import java.util.Scanner;

public class StudyJava01_method {
	
	//�տ� �ݵ�� static ���� ��
	static void SayHello()//�Ű�����(=�Ķ���� Ȥ�� �ƱԸ�Ʈ), ��ȯ���� ���� ��
	{
		System.out.println("�ȳ�, Hello");
	}
	static void SayHi(String name)
	{
		System.out.println("�ȳ� "+name+"!");
	}
	static int add(int a,int b)//�Ű������� ��ȯ�� �� ����
	{
		return a+b;
	}
	static int power()//��ȯ���� ����
	{
		System.out.println("������ �� �Է��ϼ���.");
		Scanner s = new Scanner(System.in);
		int num = s.nextInt();
		return num*num;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SayHello();
		SayHi("����ȣ");
		System.out.println(add(1,2));
		int s = add(10,20);
		System.out.println(s);
		s = power();
		System.out.println(s);
		System.out.println(power());

	}

}
