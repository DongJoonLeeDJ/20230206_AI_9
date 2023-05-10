package mytest.myjava.mycode02;

import java.util.*;

public class HelloJava01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// Math.random() : 0~0.9999.... 까지의 값
		// (int)로 강제 형변환
		System.out.println("몇 개 사실 건가요?");
		Scanner s = new Scanner(System.in);
		int count = s.nextInt();
		// int count = Integer.ParseInt(s.nextLine());
		// int count = new Scanner(System.in).nextInt();

		for (int c = 0; c < count; c++) {

			int bns = 1 + (int) (Math.random() * 45);
			int[] lotto = new int[6];
			// int lotto[6]; C 스타일
			for (int i = 0; i < lotto.length; i++) {
				lotto[i] = 1 + (int) (Math.random() * 45);
				for (int j = 0; j < i; j++) {
					if (lotto[j] == lotto[i]) {
						i--;
						break;
					}
				}
			}

			for (int i = 0; i < lotto.length; i++) {
				if (bns == lotto[i]) {
					bns = (int) (Math.random() * 45) + 1;
					i = -1;
				}
			}
			// import Arrays(java.util)
			// Arrays : java에서 만든 객체
			// js에서도 자체적인 객체가 있듯이
			// java에서도 자체적으로 만든 객체가 있다.
			// 그 안에 sort랑 toString이라는 함수가 내장되있는 것
			Arrays.sort(lotto);
			System.out.println(Arrays.toString(lotto));
			System.out.println("보너스번호 : " + bns);
			
			System.out.println((double)(10*10*3.14));
			System.out.println((float)(5*2*3.14));
		}
	}

}
