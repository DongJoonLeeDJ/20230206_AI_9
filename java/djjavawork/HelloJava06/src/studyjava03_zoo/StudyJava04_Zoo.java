package studyjava03_zoo;

import java.util.ArrayList;

public class StudyJava04_Zoo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Animal[] zoo1 = new Animal[7];
		ArrayList<Animal> zoo2 = new ArrayList<Animal>();
		zoo1[0] = new Cat();
		zoo1[0].setAge(10);
		zoo1[0].setName("��Ĺ");
		((Cat)(zoo1[0])).setEyeColor("yellow green");
		zoo1[1] = new Animal();
		zoo1[1].setAge(1);
		zoo1[1].setName("�ǲ���");
		zoo1[2] = new Dog();
		zoo1[2].setAge(17);
		zoo1[2].setName("�ϴ�");
		Animal a = new Animal();
		a.setAge(2);
		a.setName("����");
		zoo1[3]=a;
		Dog d = new Dog();
		d.setAge(15);
		d.setName("��ġ");
		zoo1[4]=d;
		Cat c = new Cat();
		c.setAge(3);
		c.setName("����");
		c.setEyeColor("blue yellow");
		Animal c2 = new Cat();
		Animal d2 = new Dog();
		c2.setAge(6);
		c2.setName("����");
		if(c2 instanceof Cat) //Cat���� �ν��Ͻ� ������� �� ���� üũ
			((Cat)(c2)).setEyeColor("odd eye");
		d2.setAge(1);
		d2.setName("����");
		zoo1[5] = c2;
		zoo1[6] = d2;
		
		for (Animal animal : zoo1) {
			animal.sleep();
			if(animal instanceof Cat)
				((Cat)animal).Meow();
			if(animal instanceof Dog)
				((Dog)animal).bark();
		}
		
		zoo2.add(zoo1[0]);
		zoo2.add(zoo1[1]);
		zoo2.add(zoo1[2]);
		zoo2.add(zoo1[3]);
		zoo2.add(zoo1[4]);
		zoo2.add(zoo1[5]);
		zoo2.add(zoo1[6]);

		for (Animal animal : zoo2) {
			animal.sleep();
			if(animal instanceof Cat)
				((Cat)animal).Meow();
			if(animal instanceof Dog)
				((Dog)animal).bark();
		}
		
		//��~~~�� Ŭ�������� ������ �־��.
		Object o = new Animal();
		Object o2 = new Dog();
		Object o3 = new Cat();
		//�� Object Ŭ�������� equals�� toString�̶�� �Լ��� �ִ� ��
		//Ŭ������ ���� �� �̰� �������̵��ؼ� Ȱ���� ���� �Ѵ�.
		
	}

}
