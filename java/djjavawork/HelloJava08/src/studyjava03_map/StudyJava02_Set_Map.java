package studyjava03_map;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class StudyJava02_Set_Map {
public static void main(String[] args) {
	//Set이랑 Map이라는 인터페이스가 있다.
	//HashSet이랑 HashMap이라는 클래스가 가장 많이 쓰이는 자료형이다.
	//특히 spring할 때 많이 쓰임
	//어떤 면에선 특정 자료를 만들 때 HashMap으로만 해도 충분함
	
	//Set : 중복을 허용하지 않고 순서가 없는 리스트
	//Map : 키-value로 구분이 되는 자료형, 키가 중복되면 기존 값을 삭제함
	//Map 전화번호(키)-사람이름(값)
	
	Set<Integer> numbers = new HashSet<Integer>();
	HashSet<Integer> numbers2 = new HashSet<Integer>();
	
	numbers.add(1);
	numbers.add(56);
	numbers.add(3);
	numbers.add(1);
	for(int item : numbers)//1을 이미 넣었으므로 또 추가하지 않음!
		System.out.println(item); //값을 넣은 순서대로 출력X
	
	//키-벨류 형식을 잘 이용하면 class 안 만들고도 객체 배열을 만들 수 있다.
	//C#, python dictionary랑 매우 유사한 개념
	Map<Integer,String> students 
		= new HashMap<Integer,String>();
	students.put(2,"이수성");
	students.put(1,"이동준");
	students.put(1,"정홍근");//1번 이동준은 삭제됨
	for(int key : students.keySet()) { //키들 모은 것
		System.out.println(key);//키 하나 하나
		System.out.println(students.get(key)); //해당 키에 맞는 값
	}
	
	HashSet<Employee> company = new HashSet<Employee>();
	company.add(new Employee("정홍근", "001", 59));
	company.add(new Employee("박세진", "002", 62));
	company.add(new Employee("이동준", "003", 35));
	company.add(new Employee("소병수", "003", 33));//이동준이 3번이라서 못 들어감
	for(Employee item : company) {
		System.out.println(item.getSabeon()+
				","+item.getName()+
				","+item.getAge());
	}
	
}
}
