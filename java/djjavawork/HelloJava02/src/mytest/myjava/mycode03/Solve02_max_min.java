package mytest.myjava.mycode03;

import java.util.Scanner;

public class Solve02_max_min {

	public static void main(String[] args) {
		//���� 3 �� �� �ϳ��� �ִ� �ּ� ã�´ٸ�
		//���� 3�� �����ϰ�, if���� �̿��ؼ� ã�� �� �ִ�.
		//������ 4��, 5������ ���ǹ��� �ʹ� ����������
		//100�� �̷� �� ã�� �� ��ǻ� �Ұ���
		Scanner s = new Scanner(System.in);
		System.out.println("�迭�� ũ���?");
		int n = s.nextInt();
		int[] numbers = new int[n];//Heap(�����޸𸮿���)
		//C�� ġ�� malloc�̶� �Ȱ��� ��
		//int numbers[n]; // Stack
		for(int i = 0; i<n; i++)
		{
			System.out.println("["+i+"]��° ����?");
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
		System.out.println("�ִ��� ["+maxidx+"] ��°�ִ�.");
		System.out.println("�ִ� : " + max);
		System.out.println("�ּڰ��� ["+minidx+"] ��°�ִ�.");
		System.out.println("�ּڰ� : " + min);
	}

}
