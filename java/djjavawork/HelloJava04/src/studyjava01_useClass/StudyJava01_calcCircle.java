package studyjava01_useClass;

public class StudyJava01_calcCircle {
	
	static double getArea(Circle c)
	{
		return c.getR()*c.getR()*c.getPI();
	}
	static double getRound(Circle c) {

		return 2*c.getR()*c.getPI();
	}
	
	static void printCircleInfo(Circle c)
	{
		System.out.println(getRound(c));
		System.out.println(getArea(c));
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle c = new Circle(10);
		Circle c2 = new Circle(); //�����ڰ� �����ε��� �ȴ�.
		//�ֳĸ� Circle class �ȿ� �� ���� �����ڸ� ����� �����̴�.
		Circle c3 = new Circle(-1); //r = 0���� ����.
		
		System.out.println(c.getArea());
		System.out.println(c.getRound());
		c2.setR(5);
		System.out.println(c2.getArea());
		System.out.println(c2.getRound());
		System.out.println(c3.getArea());
		System.out.println(c3.getRound());
		
		
		printCircleInfo(c);
		
		
		//cc ������ stack�̶�� ������ �Ҵ��
		//new Circle()�� �̿��ؼ� Heap ������ Circle Ÿ���� ������ �Ҵ��
		//new Circle(), new Circle(50)�� Instance(�ν��Ͻ�)��� �θ�
		
		
		//�ν��Ͻ��� �� �� ���� ���̴�.
		Circle cc = new Circle();//r = 0
		Circle cc2 = new Circle(50); //r = 50
		
		//�ν��Ͻ����� r���� �ٸ� �� �ִ�.
		//�ν��Ͻ����� ���̰��̶� �ѷ����� �ٸ� �� �ִ�.
		//�ֳĸ� r ���� �ٸ��� �����̴�.
		//���� �̷��� �ν��Ͻ����� ���� �ٸ� �� �ν��Ͻ� ����, �ν��Ͻ� �޼ҵ�
		
		//��� �ν��Ͻ��� �� �Ȱ��� ���� ���� �� �ִٴ� �ǰ�?
		//Circle�� ��쿡�� cc, cc2, c ���� ��� PI���� �����ϴ�.
		//���� �� ��쿣 �ٸ��� ǥ���� �� �ִ�.
		
		cc.setR(20);
		cc.printMyCircle();//1256.6000000000001, 125.66000000000001
		cc2.printMyCircle();
		Circle.printMYPI();
		Circle.MYPI=3.1415926; //��� Circle�� ������ ��ģ��.
		//PI�� Ȥ�� �б��� ġ�� ����
		//�������� ġ�� �� ������ ������ ���� �͵���
		//����� ������ �տ� static�� ���δ�.
		//�׷��� ���������� ������ �ϰ� ��� �ν��Ͻ��鿡 ������ �ش�.
		System.out.println("----");
		cc.printMyCircle();//1256.63704,125.663704
		cc2.printMyCircle();
		Circle.printMYPI();
		
		
	}

}








