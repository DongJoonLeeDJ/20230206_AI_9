package studyjava01_abstract;

public class StudyJava01_PCRoom {

	public static void main(String[] args) {
		LolChamp c1 = new Cogmo();
		Cogmo c2 = new Cogmo();
//		LolChamp c3 = new LolChamp();
		//c3는 StudyJava01_PCRoom.java에서 즉석에서 만들어진 것
		//이 코드 안에서만 쓰이는 객체
		LolChamp c3 = new LolChamp() {

			@Override
			public void Q() {
				System.out.println("오염된 뼈들");				
			}

			@Override
			public void W() {
				System.out.println("심장 전기 충격");
			}

			@Override
			public void E() {
				System.out.println("둔기에 의한 외상");
			}

			@Override
			public void R() {
				System.out.println("최대 투여량");
			}
			
		};
		
		c1.Q();
		c2.passive();
		((Cogmo)c1).passive();
		c3.Q(); //StudyJava01_PCRoom에서만 만들어진 코드임
		//이 코드 바깥에선 쓰일 수 없다.
		//즉석에서 만들어진 객체

	}

}
