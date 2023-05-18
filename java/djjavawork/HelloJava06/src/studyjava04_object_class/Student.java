package studyjava04_object_class;

public class Student {
	private int age;
	private String name;
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Student(int age, String name) {
		this.age = age;
		this.name = name;
	}
	
	//Object Ŭ�������� �⺻���� �����ϴ� toString�Լ�
	//�� StudentŸ���� �ڷḦ ���ڿ��� ��ȯ�ϴ� ���
	@Override
	public String toString() {
//		super.toString()
		return "�̸�:"+this.name+",����:"+this.age;
	}
	//StudentŸ���� ��� ������ ���ϴ� ��
	//�̸��� ���̱��� �Ȱ��ƾ��� ���� �л����� �����ϴ� ��!
	@Override
	public boolean equals(Object obj) {
		return this.name.equals(((Student)obj).getName()) 
				&& this.age==((Student)obj).getAge();
	}

}
