package mytest.myjava.mycode04;

public class HelloJava01_arrays {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a1 = new int[5];//�⺻ ������ 0�� ��
		int[] a2 = {1,2,3,4,5};
		for(int i = 0; i<5; i++)
		{
			System.out.println(a1[i]+" " + a2[i]);
		}
		int[][] aa1 = new int[3][4];//3�� 4�� ������ ǥ��
		int[][] aa2 = {
				{1,2,3,4}, //�ϳ��� ���� �� ���� �ִ�.
				{5,6,7,8},
				{9,10,11,12}
		};
		int[][] aa3 = { //�� �ึ�� ���� ������ �ٸ��� �� ���� �ִ�.
				{1,2},
				{3,4,5},
				{1}
		};
		

	}

}
