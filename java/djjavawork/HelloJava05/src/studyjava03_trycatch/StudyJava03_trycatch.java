package studyjava03_trycatch;

import java.util.Scanner;

public class StudyJava03_trycatch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println("���α׷� ����");
		try { //�õ��ϴ�
			int a= 10;
			int b = 0;
			int c = a/b; //���⿡�� ���α׷��� ���������
			System.out.println(c);
		} catch (Exception e) { //������ ��Ƴ���
			e.printStackTrace();
		}
		//���α׷��� �߸��ǵ� catch�κ� �����ϰ� �� �ؿ���
		//��� �̾ ������ ��
		System.out.println("���α׷� ����");
		
		
		try {
			System.out.println("�ȳ�");
			int aa = 10;
			int bb = 0;
			int cc = aa/bb;
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("����!");
			e.printStackTrace();
			return; //catch���� ������ �ϵ� �� �ϵ� finally�� �� ������
			//���� DB������ �ݴ� �κ��� finally �ȿ� ���´�.
		} finally {
			System.out.println("�̰� ������ ����!");
		}
		System.out.println("��� ���� �� �� ����");
		
		
		//catch�� �������κ��� ���� ���� ���� �� �ִ�.
		

	}

}
