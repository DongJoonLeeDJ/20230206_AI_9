package studyjava02_list;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class StudyJava04_HelloList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//�迭�̶��� �� �ٸ� ������ �ڷ� ������ �����ϴ� �ڷ� ����
		List numbers = new ArrayList<Integer>();
		ArrayList nums = new ArrayList<Integer>();
		
		//C�� �ڷᱸ������ ���� ���� �����ؾ� �ϴ� LinkedList��
		//�̹� ������
		List linkedlist = new LinkedList<Integer>();

		//������ �����ϴ� ��̸���Ʈ(�迭�̶� �ٸ���)
		ArrayList<Integer> mynumbers = 
				new ArrayList<Integer>();
		//Integer = int
		//int ��ſ� ��! Integer�� ��� ��!
		
		//1. �迭�� �̸� ũ�⸦ �������� ��� �׷��� �ʴ�.
		//2. ��� ũ�� �߰��� �����Ӵ�.(�迭�� �׷��� �ʴ�.)
		mynumbers.add(10);
		mynumbers.add(20);
		mynumbers.add(15);
		mynumbers.set(0, -10); //[0]��° ���� -10���� ����
		for(int i = 0; i<mynumbers.size(); i++)
			System.out.println(mynumbers.get(i));
		//�迭�̶��� �ٸ��� 3ĭ¥���� �� ĭ¥���� �� ���Ϸ� ���� �� �ִ�.
		mynumbers.remove(1); //�� ��°�� ����
		mynumbers.remove(Integer.valueOf(-10));
		for(int i = 0; i<mynumbers.size(); i++)
			System.out.println(mynumbers.get(i));
		
		ArrayList<String> students = 
				new ArrayList<String>();
		students.add("�Һ���");
		students.add("��ȫ��");
		students.add("����ȣ");
		students.add("����ȣ");
		students.add("�Һ���");
		students.remove(0);
		students.remove("�Һ���");
		
		//foreach ctrl + space enter
		//js�� for(item of students)�� �Ȱ��� ��!
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
