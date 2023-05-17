package studyjava03_trycatch;

import java.util.Scanner;

public class StudyJava03_trycatch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println("프로그램 시작");
		try { //시도하다
			int a= 10;
			int b = 0;
			int c = a/b; //여기에서 프로그램이 강제종료됨
			System.out.println(c);
		} catch (Exception e) { //오류를 잡아내다
			e.printStackTrace();
		}
		//프로그램이 잘못되도 catch부분 수행하고 그 밑에꺼
		//계속 이어서 수행을 함
		System.out.println("프로그램 종료");
		
		
		try {
			System.out.println("안녕");
			int aa = 10;
			int bb = 0;
			int cc = aa/bb;
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("리턴!");
			e.printStackTrace();
			return; //catch에서 리턴을 하든 안 하든 finally는 꼭 실행함
			//보통 DB연결을 닫는 부분은 finally 안에 적는다.
		} finally {
			System.out.println("이건 무조건 실행!");
		}
		System.out.println("얘는 실행 안 됨 ㅇㅇ");
		
		
		//catch는 오류원인별로 여러 개를 적을 수 있다.
		

	}

}
