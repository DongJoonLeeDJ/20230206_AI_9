package com.javalec.ex;

public class Animal {
	private String kinds; //������ ����
	private String name;
	private int age;
	private String number;
	@Override
	public String toString() {
		return "����"+getKinds()+
				"�̸�,����,��ȣ:"+getName()+getAge()+getNumber();
	}
	public Animal(String kinds, String name, int age, String number) {
		super();
		this.kinds = kinds;
		this.name = name;
		this.age = age;
		this.number = number;
	}
	public String getKinds() {
		return kinds;
	}
	public void setKinds(String kinds) {
		this.kinds = kinds;
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
