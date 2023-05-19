package studyjava06_basic_interface;

//Cloneable : ���� �����
//���縦 �� �� ���� �����ϰ�, �ּ����� �������� �ʴ� ��
//�ּ����� �����ϴ� �� ���� ������ ��
//Deep Copy, Shallow Copy

//Comparable : ���ϴ� ������ ����
//���� ���⼱ �л��� ���̼����� ������ �Ѵٰ� ��������
//�׷� ��� age�� �������� ���ϰԲ� ����� �Ѵ�.
public class Student implements Cloneable, Comparable<Student>{

	private String num; //PK
	private String name;
	private int age;
	
	//�������̽� Cloneable ����, �� ������ clone �������̵��ϱ�
	//�ٸ� ��Ű�������� ��� Ȱ���Ϸ��� protected�� ��� public���� �ٲ�� ��
	//Cloneable�� clone �޼ҵ�� �̹� default�� �����Ǿ� ������
	//�������̵��� �ؾ� �� �� �ִ�.
	@Override
	public Object clone() throws CloneNotSupportedException {
		// TODO Auto-generated method stub
		return super.clone();
	}
	@Override
	public int compareTo(Student o) {
		// TODO Auto-generated method stub
		return this.age-o.getAge();
		//0 ��� �����Ŀ� ���� ������ �ȴ�.
	}
	
	public Student(String num, String name, int age) {
		super();//ObjectŬ������ ������ �� ���� Ŭ������ ������
		this.num = num;
		this.name = name;
		this.age = age;
	}
	public String getNum() {
		return num;
	}
	public void setNum(String num) {
		this.num = num;
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

	
}
