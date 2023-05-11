package mytest.myjava.mycode03;

import java.util.Scanner;

public class Solve02_max_min {

	public static void main(String[] args) {
		//만약 3 개 중 하나를 최대 최소 찾는다면
		//변수 3개 선언하고, if문을 이용해서 찾을 수 있다.
		//하지만 4개, 5개부턴 조건문이 너무 복잡해지고
		//100개 이런 건 찾는 게 사실상 불가능
		Scanner s = new Scanner(System.in);
		System.out.println("배열의 크기는?");
		int n = s.nextInt();
		int[] numbers = new int[n];//Heap(동적메모리영역)
		//C로 치면 malloc이랑 똑같은 것
		//int numbers[n]; // Stack
		for(int i = 0; i<n; i++)
		{
			System.out.println("["+i+"]번째 값은?");
			numbers[i] = s.nextInt();
		}
		int max = numbers[0];
		int min = max;
		int maxidx = 0;
		int minidx = 0;
		
		for(int i = 0; i<n; i++)
		{
			if(max<numbers[i])
			{
				max = numbers[i];
				maxidx = i;
			}
			if(min>numbers[i])
			{
				min = numbers[i];
				minidx = i;
			}
		}
		System.out.println("최댓값은 ["+maxidx+"] 번째있다.");
		System.out.println("최댓값 : " + max);
		System.out.println("최솟값은 ["+minidx+"] 번째있다.");
		System.out.println("최솟값 : " + min);
	}

}
