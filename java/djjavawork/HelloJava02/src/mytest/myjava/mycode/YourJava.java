package mytest.myjava.mycode;

import java.util.Scanner;

public class YourJava {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a  = 35;//기본적으로 정수는 int
		short aa = (short)10;
		double b = 3.14;//기본적으로 실수는 double형
		float bb = (float)3.1415;
		char c = 'A';
		char cc = '가';//java의 char는 unicode(한글 등)도
		//한 글자 저장이 가능. 이유는 char가 2byte를 저장하기 때문
		
		boolean d = false;
		d = true;
		
		String f = "안녕하세요~!";
		f += " 이동준 선생님~! ";	 //문자열 이어붙이기	
		System.out.println(f);
		System.out.println(a);
		
		//입력
		//import Scanner(java.util)
		Scanner s = new Scanner(System.in);
		System.out.println("졸지 마시고 써보세요.");
		f += s.nextLine();
		System.out.println("나이 몇살?");
		int age = s.nextInt(); //c의 scanf와 같은 문제있음
		s.nextLine(); //이걸 하나 더 써주든지 애초에 nextInt를 안 쓴다.
		System.out.println("언제 태어났니?");
		int birthYear = Integer.parseInt(s.nextLine());
		System.out.println("내 나이 : " + (2023-birthYear));
		
		

	}

}
