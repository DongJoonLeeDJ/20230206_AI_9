package mytest.myjava.mycode03;

import java.util.*;//Scanner,Arrays ����� ���Ե�

public class Solve01_Circle {

	public static void main(String[] args) {
		System.out.println("���� ��������?");
		Scanner s = new Scanner(System.in);
		int r = s.nextInt();
		//Integer.ParseInt(s.nextLine());
		final double PI = 3.14;//final : ���(const)
		System.out.printf("���� ���� %f\n",r*r*PI);
		System.out.println("���� �ѷ� : " + (2*r*PI));
		System.out.println("���� �ѷ� : " + (double)(2*r*PI));
		System.out.println(String.format("%f", (2*r*PI)));
		//float(4) : �ε� �Ҽ��� => ���м��� ����
		//double(8) : ���� �Ҽ��� => ����
		//31.400000000000002
		//�Ҽ�ǥ���ϴ� ����� ��ǻ�ʹ� �������̱� ������
		//�� �������� ǥ���� �� ����.
		//0�� 1�� �Ǽ��� ǥ���ϸ鼭 ����� ����
	}

}
