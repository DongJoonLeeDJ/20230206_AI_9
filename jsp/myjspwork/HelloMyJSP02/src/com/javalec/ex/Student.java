package com.javalec.ex;

public class Student {
	private String name;
	private int age;
	private String number;
	
	@Override
	public String toString() {
		return "�̸�,����,��ȣ:"+getName()+getAge()+getNumber();
	}
	
	public Student(String name, int age, String number) {
		super();//Object Ŭ������ �������̰� ��������
		this.name = name;
		this.age = age;
		this.number = number;
	}
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
	public String getNumber() {
		return number;
	}
	public void setNumber(String number) {
		this.number = number;
	}
	
}
