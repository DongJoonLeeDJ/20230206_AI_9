package studyjava03_trycatch;

public class StudyJava06_throw_Error2 {
	public static int power(int n) throws Exception {
		if(n<=0)
			throw new Exception("¾ç¼ö¸¸ µÊ!");
		return n*n;
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		int a = power(10);
		System.out.println(a);
		int b = power(-10);
		System.out.println(b);
	}

}
