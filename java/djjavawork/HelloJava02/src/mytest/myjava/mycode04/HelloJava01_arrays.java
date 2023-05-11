package mytest.myjava.mycode04;

public class HelloJava01_arrays {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a1 = new int[5];//기본 값으로 0이 들어감
		int[] a2 = {1,2,3,4,5};
		for(int i = 0; i<5; i++)
		{
			System.out.println(a1[i]+" " + a2[i]);
		}
		int[][] aa1 = new int[3][4];//3행 4열 데이터 표현
		int[][] aa2 = {
				{1,2,3,4}, //하나씩 직접 쓸 수도 있다.
				{5,6,7,8},
				{9,10,11,12}
		};
		int[][] aa3 = { //각 행마다 열의 개수가 다르게 할 수도 있다.
				{1,2},
				{3,4,5},
				{1}
		};
		

	}

}
