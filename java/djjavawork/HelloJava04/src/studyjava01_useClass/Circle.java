package studyjava01_useClass;
//Circle.java = C���� ġ�ڸ� ����ü�� ��� ������� ���� ��
//js�� ġ�ڸ� class�� ��� js�����̶�� ���ŵ� ��
public class Circle {

	//static�� ���� ������ ���� �ν��Ͻ� ���� Ȥ�� �ν��Ͻ� �޼ҵ�
	private int r;//������, �ν��Ͻ� ����
	private final double PI = 3.14;//PI���� ���
	
	//static �ٴ� �� Ŭ���� ����, Ŭ���� �޼ҵ��� ��
	//Ŭ���� �������� ���������� ���� �޼ҵ峪 �Ӽ��� Ŭ���� ����, Ŭ���� �޼ҵ�
	//�տ� static�� �ٴ´�.
	//!!!! �׸���!!!! static�� ���� �޼ҵ� �ȿ��� static�� ���� �޼ҵ峪
	//static�� ���� ������ Ȱ���� �� �ִ�.
	
	//��� static�� ���� �� static�� ���� ���� ������ �� �� �ִ�.
	//������ C�� ������ �� ����ٸ� �˰� ���� ���̴�.
	
	//static�� ���� �� �ν��Ͻ��� �������� �ʰ� �� �� �ִ�.
	//�� new Circle() �̷� �� ���� �׳� Circle.MYPI �̷��� �� �� �ִ�
	//�޼ҵ峪 ���� �� �� �׷���.
	public static double MYPI = 3.1415; //��� Circle�� ���������� �̿���
	public void printMyCircle()
	{
		System.out.println("���� ����!(MYPI�̿�)");
		System.out.println(this.r*this.r*MYPI);
		System.out.println("���� �ѷ�!(MYPI�̿�)");
		System.out.println(2*this.r*MYPI);
	}
	public static void printMYPI()
	{
		System.out.println(MYPI);
	}
	
	//getter, setter
	//�ν��Ͻ� �޼ҵ�
	public int getR() {
		return r;
	}
	public void setR(int r) {
		if(r<=0)
		{
			System.out.println("Error!");
			this.r = 0;
			return;
		}
		this.r = r;
	}
	public double getPI() {
		return PI;
	}
	
	//Circle���� ���ϵǴ� ���� �ٸ��Ƿ�(�����ϴ� ��Ŀ������ �Ȱ�����)
	//���� �� ����� �ٸ��Ƿ� �ν��Ͻ� �޼ҵ��� ��
	//static Ű���� �����Ƿ� �ν��Ͻ� �޼ҵ�
	public double getArea() {
		return PI*this.r*this.r;
	}
	public double getRound() {
		return PI*2*this.r;
	}
	
	//������
	//�� �� �����ڶ�� �ϴ� ��
	//�̰� ������
	//public Circle() { }
	//�̿� ���� �ƹ� �͵� ���� �����ڰ� �Ϲ������� ������� �ִ�.
	//�ٵ� �Ʒ��� ���� �Ű������� �ִ� �����ڸ� �����
	//�Ű����� ���� �⺻ �����ڴ� ������
	//�Ű����� ���� �⺻ �����ڸ� ���� �ʹٸ�
	//��������� ����� ��
	public Circle() {}
	
	public Circle(int r) {
		setR(r); //�ڵ����� ������ ���� ����ó���� ���� �� �ִ�.
		//this.r = r;
	}
	
	
	
}













