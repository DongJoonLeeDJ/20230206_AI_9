package studyjava03_interface;


//�̻��ؾ��� �߻�Ŭ������ ���ϸ��� ��ӹް�
//�������̽� 2���� �߰��� ��ü(��Ģ�� 2�� �߰���)
//Platable�̶�� ��Ģ���� 3���� �޼ҵ� �߰�
//Animalable�̶�� ��Ģ���� 5���� �޼ҵ� �߰�
public class Bulbasaur extends Pokemon implements Plantable,Animalable{

	@Override
	public void bodyattack() {
		// TODO Auto-generated method stub
		System.out.println("���� ��ġ��!");
	}

	@Override
	public void QuickAttack() {
		// TODO Auto-generated method stub
		System.out.println("���� ��ȭ!");
		
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void jump() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void solarbeam() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void growth() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void photosynthesis() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void cry() {
		// TODO Auto-generated method stub
		
	}

}
