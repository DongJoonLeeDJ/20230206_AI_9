package studyjava02_list;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class StudyJava04_HelloList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//배열이랑은 또 다른 형태의 자료 여러개 저장하는 자료 구조
		List numbers = new ArrayList<Integer>();
		ArrayList nums = new ArrayList<Integer>();
		
		//C의 자료구조에서 내가 직접 구현해야 하는 LinkedList가
		//이미 구현됨
		List linkedlist = new LinkedList<Integer>();

		//정수를 저장하는 어레이리스트(배열이랑 다르다)
		ArrayList<Integer> mynumbers = 
				new ArrayList<Integer>();
		//Integer = int
		//int 대신에 꼭! Integer를 써야 함!
		
		//1. 배열은 미리 크기를 정하지만 얘는 그렇지 않다.
		//2. 얘는 크기 추가가 자유롭다.(배열은 그렇지 않다.)
		mynumbers.add(10);
		mynumbers.add(20);
		mynumbers.add(15);
		mynumbers.set(0, -10); //[0]번째 값을 -10으로 변경
		for(int i = 0; i<mynumbers.size(); i++)
			System.out.println(mynumbers.get(i));
		//배열이랑은 다르게 3칸짜리를 두 칸짜리나 그 이하로 만들 수 있다.
		mynumbers.remove(1); //두 번째꺼 삭제
		mynumbers.remove(Integer.valueOf(-10));
		for(int i = 0; i<mynumbers.size(); i++)
			System.out.println(mynumbers.get(i));
		
		ArrayList<String> students = 
				new ArrayList<String>();
		students.add("소병수");
		students.add("정홍근");
		students.add("박준호");
		students.add("정선호");
		students.add("소병수");
		students.remove(0);
		students.remove("소병수");
		
		//foreach ctrl + space enter
		//js의 for(item of students)랑 똑같은 것!
		for (String string : students) {
			System.out.println(string);
		}
		System.out.println(students.size());
		for(int i = 0; i<students.size();i++)
			System.out.println(students.get(i));
		
		int[] mynums = new int[5];
		mynums[3] = 5;
		for(int item : mynums)
			System.out.println(item);
		
	} 

}
