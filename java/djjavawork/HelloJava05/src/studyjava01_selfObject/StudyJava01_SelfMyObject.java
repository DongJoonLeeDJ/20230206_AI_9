package studyjava01_selfObject;

public class StudyJava01_SelfMyObject {

	void testHelloWorld()
	{
		System.out.println("�ȳ� ����!");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//testHelloWorld(); //ȣ�� �� ��
		//static�� ���� main���忡�� testHelloWorld��
		//���� �޸𸮿� ����, �� �������� �ʴ� �Լ��� ��!
		
		//�ڱ� �ڽ��� ��üȭ�� ��
		//�ν��Ͻ� ������ �޼ҵ带 Ȱ���ϰ� ���� �� �̷��� �ؾ� ��
		new StudyJava01_SelfMyObject().testHelloWorld();
	}

}
