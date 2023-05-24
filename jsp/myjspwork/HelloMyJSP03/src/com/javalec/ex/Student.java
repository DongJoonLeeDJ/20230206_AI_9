package com.javalec.ex;

public class Student {
	private String name;
	private int age;
	//Bean을 쓰기 위해선 생성자를 만들지 않는다.
	//기본생성자를 써야 함(매개변수 없는 거)
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	
}
