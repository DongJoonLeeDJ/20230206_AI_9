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
			System.out.println("���α׷� �׽�Ʈ��!!!");
		}catch(ArithmeticException e) {
			System.out.println("������ ����");
		}catch(IndexOutOfBoundsException e) {
			System.out.println("�ε��� ����");
		} catch (Exception e) {
			System.out.println("��� ������ �� �����");
		}
		
	}

}
