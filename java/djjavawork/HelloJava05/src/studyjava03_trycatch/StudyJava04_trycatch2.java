package studyjava03_trycatch;

import java.util.Scanner;

public class StudyJava04_trycatch2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		try {
			Scanner s = new Scanner(System.in);
			int one = s.nextInt();
			int two = s.nextInt();
			int three = one/two;
			int size = s.nextInt();
			int[] arr = new int[size];
			arr[100] = 10;
			System.out.println("프로그램 테스트중!!!");
		}catch(ArithmeticException e) {
			System.out.println("수학적 오류");
		}catch(IndexOutOfBoundsException e) {
			System.out.println("인덱스 오류");
		} catch (Exception e) {
			System.out.println("모든 오류는 다 여기로");
		}
		
	}

}
