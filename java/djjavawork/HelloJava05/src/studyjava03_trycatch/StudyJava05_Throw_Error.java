package studyjava03_trycatch;

public class StudyJava05_Throw_Error {
	//throw : 던지다
	//Exception : class, 에러를 다루는 객체
	public static int power(int n) throws Exception {
		if(n<=0)
			throw new Exception("양수만 됨!");
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
			int b = power(-10);//양수가 아니므로 에러를 던짐
			System.out.println(b);//따라서 이거 실행 안 하고
		} catch (Exception e) {
			e.printStackTrace();//바로 여기를 실행함
		}
	}

}
