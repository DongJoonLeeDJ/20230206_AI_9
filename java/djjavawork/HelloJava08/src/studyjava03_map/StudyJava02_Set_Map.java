package studyjava03_map;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class StudyJava02_Set_Map {
public static void main(String[] args) {
	//Set�̶� Map�̶�� �������̽��� �ִ�.
	//HashSet�̶� HashMap�̶�� Ŭ������ ���� ���� ���̴� �ڷ����̴�.
	//Ư�� spring�� �� ���� ����
	//� �鿡�� Ư�� �ڷḦ ���� �� HashMap���θ� �ص� �����
	
	//Set : �ߺ��� ������� �ʰ� ������ ���� ����Ʈ
	//Map : Ű-value�� ������ �Ǵ� �ڷ���, Ű�� �ߺ��Ǹ� ���� ���� ������
	//Map ��ȭ��ȣ(Ű)-����̸�(��)
	
	Set<Integer> numbers = new HashSet<Integer>();
	HashSet<Integer> numbers2 = new HashSet<Integer>();
	
	numbers.add(1);
	numbers.add(56);
	numbers.add(3);
	numbers.add(1);
	for(int item : numbers)//1�� �̹� �־����Ƿ� �� �߰����� ����!
		System.out.println(item); //���� ���� ������� ���X
	
	//Ű-���� ������ �� �̿��ϸ� class �� ����� ��ü �迭�� ���� �� �ִ�.
	//C#, python dictionary�� �ſ� ������ ����
	Map<Integer,String> students 
		= new HashMap<Integer,String>();
	students.put(2,"�̼���");
	students.put(1,"�̵���");
	students.put(1,"��ȫ��");//1�� �̵����� ������
	for(int key : students.keySet()) { //Ű�� ���� ��
		System.out.println(key);//Ű �ϳ� �ϳ�
		System.out.println(students.get(key)); //�ش� Ű�� �´� ��
	}
	
	HashSet<Employee> company = new HashSet<Employee>();
	company.add(new Employee("��ȫ��", "001", 59));
	company.add(new Employee("�ڼ���", "002", 62));
	company.add(new Employee("�̵���", "003", 35));
	company.add(new Employee("�Һ���", "003", 33));//�̵����� 3���̶� �� ��
	for(Employee item : company) {
		System.out.println(item.getSabeon()+
				","+item.getName()+
				","+item.getAge());
	}
	
}
}
