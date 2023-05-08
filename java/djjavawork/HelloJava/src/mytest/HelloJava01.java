package mytest;

import java.util.Scanner;

//Scanner(값 입력받기) 하는 법
//C의 헤더파일 추가랑 같은 것

public class HelloJava01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a = 10;
		double b = 3.14;
		char c = '가'; //java에서의 char는 2byte
		//char 변수 하나가 한글을 저장할 수 있다.
		boolean d = false;//true, false를 저장하는 자료형
		String f = "안녕하세요";//큰따옴표로 감싸진 문자열(=문장)을
		//저장. 한글자 이상의 문장을 저장
		//+
		//단순히 값을 더할 수도 있지만, 문자열을 이어붙일 수 있다.(js처럼)
		f = f + " 이수성님 !";
		System.out.println(f);
		
		//입력받는 방식
		Scanner s = new Scanner(System.in);
		f = s.nextLine();//s.nextLine() : String타입 입력받음
		System.out.println(f+"님도 환영해요!");
		
		int random = ((int)Math.random()*45)+1;//1~45
		System.out.println(random);
		
		//c는 int lotto[6]
		int[] lotto = new int[6];
		lotto[0] = random;
		for(int i = 0; i<lotto.length; i++)
		{
			lotto[i] = i*10;
			System.out.println(lotto[i]);
		}
		
		

	}

}
