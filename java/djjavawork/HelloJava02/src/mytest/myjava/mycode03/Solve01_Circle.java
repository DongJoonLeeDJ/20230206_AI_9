package mytest.myjava.mycode03;

import java.util.*;//Scanner,Arrays 등등이 포함됨

public class Solve01_Circle {

	public static void main(String[] args) {
		System.out.println("원의 반지름은?");
		Scanner s = new Scanner(System.in);
		int r = s.nextInt();
		//Integer.ParseInt(s.nextLine());
		final double PI = 3.14;//final : 상수(const)
		System.out.printf("원의 넓이 %f\n",r*r*PI);
		System.out.println("원의 둘레 : " + (2*r*PI));
		System.out.println("원의 둘레 : " + (double)(2*r*PI));
		System.out.println(String.format("%f", (2*r*PI)));
		//float(4) : 부동 소수점 => 정밀성을 포기
		//double(8) : 고정 소수점 => 정밀
		//31.400000000000002
		//소수표현하는 방식이 컴퓨터는 디지털이기 때문에
		//딱 떨어지게 표현할 수 없다.
		//0과 1로 실수를 표현하면서 생기는 오차
	}

}
