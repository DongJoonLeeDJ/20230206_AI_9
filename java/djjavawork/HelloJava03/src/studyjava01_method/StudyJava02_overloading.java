package studyjava01_method;

public class StudyJava02_overloading {
	//오버로딩(overloading)
	//함수(=메소드) 이름이 똑같아도 매개변수의 타입이나
	//개수가 다르면 서로 다른 메소드로 간주함
	//참고로 리턴타입은 전혀 상관없음(리턴타입은 중요하지 않음)
	//중요한 건 매개변수
	static int add(int a, int b)
	{
		return a+b;
	}
	static double add(double a, double b)
	{
		return a+b;
	}
	static int add(char a, char b)
	{
		return a+b;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(add(1,2));
		System.out.println(add(3.14,3.86));
		System.out.println(add('A','a'));

	}

}
