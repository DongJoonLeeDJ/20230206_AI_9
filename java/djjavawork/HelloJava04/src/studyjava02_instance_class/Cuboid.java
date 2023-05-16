package studyjava02_instance_class;
//������ü
//z�� static���� �ؼ� ��� Cuboid������ ������ ��ĥ ��
public class Cuboid {
	private int w; //�ν��Ͻ� ����
	private int h;
	private static int z; //Ŭ���� ����

	//alt shift s ������ rŰ ������
	//Generate Getter and Setter Ŭ��
	//���콺 ������ ������ Source Ŭ�� �ϰ� 
	//Generate Getter and Setter Ŭ��
	
	public int getW() {
		return w;
	}
	public void setW(int w) {
		this.w = w;
	}
	public int getH() {
		return h;
	}
	public void setH(int h) {
		this.h = h;
	}
	//Ŭ���� �޼ҵ�
	//static�� ���� �޼ҵ� �ȿ��� static�� ���� �޼ҵ峪
	//static�� ���� ������ �� �� �ִ�.
	//����� static�� ���� �޼ҵ� �ȿ��� static �ִ� �� �� �� �ִ�.
	public static int getZ() {
		return z;
	}
	public static void setZ(int z) {
		Cuboid.z = z;
	}
	public int getVolume() {
		return z*this.w*this.h;
	}
	public int getArea() {
		return this.w*this.h;
	}
	
	//���� �⺻���� ��������� �������� ��,
	//�Ű����� �ִ� �����ڸ� ���� �� �Ǹ� ������Ƿ�
	//��������� ������� ��!
	public Cuboid() {}
	//������ü
	public Cuboid(int wh)
	{
		this.w = wh;
		this.h = wh;
	}
	//�ϳ��� ������ w�� h�� ���� ������ü
	public Cuboid(int w, int h)
	{
		this.w = w;
		this.h = h;
	}
	//�� ������ü�� ��������� ��� ������ü���� ���̿� ������ ��ģ��.
	public Cuboid(int w, int h, int z)
	{
		this.w = w;
		this.h = h;
		Cuboid.z= z;
	}
	
	
	
	
	
	
	
	
}
