package studyjava03_trycatch;

public class StudyJava05_Throw_Error {
	//throw : ������
	//Exception : class, ������ �ٷ�� ��ü
	public static int power(int n) throws Exception {
		if(n<=0)
			throw new Exception("����� ��!");
		return n*n;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			int a = power(10);
			System.out.println(a);
		} catch (Exception e) {
			e.printStackTrace();
		}
		try {
			int b = power(-10);//����� �ƴϹǷ� ������ ����
			System.out.println(b);//���� �̰� ���� �� �ϰ�
		} catch (Exception e) {
			e.printStackTrace();//�ٷ� ���⸦ ������
		}
	}

}
