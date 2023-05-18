package studyjava03_zoo;

import java.util.ArrayList;

public class StudyJava04_Zoo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Animal[] zoo1 = new Animal[7];
		ArrayList<Animal> zoo2 = new ArrayList<Animal>();
		zoo1[0] = new Cat();
		zoo1[0].setAge(10);
		zoo1[0].setName("동캣");
		((Cat)(zoo1[0])).setEyeColor("yellow green");
		zoo1[1] = new Animal();
		zoo1[1].setAge(1);
		zoo1[1].setName("꽁꽁이");
		zoo1[2] = new Dog();
		zoo1[2].setAge(17);
		zoo1[2].setName("니니");
		Animal a = new Animal();
		a.setAge(2);
		a.setName("지니");
		zoo1[3]=a;
		Dog d = new Dog();
		d.setAge(15);
		d.setName("뭉치");
		zoo1[4]=d;
		Cat c = new Cat();
		c.setAge(3);
		c.setName("랑이");
		c.setEyeColor("blue yellow");
		Animal c2 = new Cat();
		Animal d2 = new Dog();
		c2.setAge(6);
		c2.setName("콩이");
		if(c2 instanceof Cat) //Cat으로 인스턴스 만들었는 지 여부 체크
			((Cat)(c2)).setEyeColor("odd eye");
		d2.setAge(1);
		d2.setName("순수");
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
		
		//모~~~든 클래스에는 조상이 있어요.
		Object o = new Animal();
		Object o2 = new Dog();
		Object o3 = new Cat();
		//이 Object 클래스에는 equals나 toString이라는 함수가 있는 데
		//클래스를 만들 때 이걸 오버라이딩해서 활용을 많이 한다.
		
	}

}
