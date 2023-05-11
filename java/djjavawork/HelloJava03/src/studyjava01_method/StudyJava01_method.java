package studyjava01_method;

import java.util.Scanner;

public class StudyJava01_method {
	
	//앞에 반드시 static 붙일 것
	static void SayHello()//매개변수(=파라메터 혹은 아규먼트), 반환형이 없는 것
	{
		System.out.println("안녕, Hello");
	}
	static void SayHi(String name)
	{
		System.out.println("안녕 "+name+"!");
	}
	static int add(int a,int b)//매개변수랑 반환형 다 있음
	{
		return a+b;
	}
	static int power()//반환형만 있음
	{
		System.out.println("제곱할 수 입력하세요.");
		Scanner s = new Scanner(System.in);
		int num = s.nextInt();
		return num*num;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SayHello();
		SayHi("박준호");
		System.out.println(add(1,2));
		int s = add(10,20);
		System.out.println(s);
		s = power();
		System.out.println(s);
		System.out.println(power());

	}

}
