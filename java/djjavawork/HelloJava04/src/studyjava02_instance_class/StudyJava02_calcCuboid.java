package studyjava02_instance_class;

public class StudyJava02_calcCuboid {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cuboid c1 = new Cuboid();
		c1.setH(10);
		c1.setW(20);
		Cuboid.setZ(2);
		Cuboid c2 = new Cuboid();
		c2.setH(11);
		c2.setW(11);
		System.out.println(c1.getVolume());
		System.out.println(c1.getArea());//z�� �������.
		System.out.println(c2.getVolume());
		System.out.println(c2.getArea());
		Cuboid.setZ(100);//c1, c2�� ���ǿ� ������ ��ħ
		System.out.println(c1.getVolume());
		System.out.println(c1.getArea());
		System.out.println(c2.getVolume());
		System.out.println(c2.getArea());
		
		Cuboid c3 = new Cuboid(2,3);
		System.out.println(c3.getVolume());//600
		System.out.println(c3.getArea());//6
		Cuboid c4 = new Cuboid(5,6,11);
		//Ŭ���� ������ z�� �ٲ�鼭
		//�ٸ� ������ü���� ���̵� �� �ٲ�� �ǰ�
		//�׷��� ���ǰ��� ��� �޶����� �ȴ�.
		System.out.println(c3.getVolume());//66
		System.out.println(c4.getVolume());//330
		System.out.println(c4.getArea());//30
		System.out.println(c1.getVolume());//2200
		System.out.println(c2.getVolume());//1331
		
		
	}

}
