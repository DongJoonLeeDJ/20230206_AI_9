package studyjava03_interface;

//추상클래스와 유사한 개념
//특정 메소드를 반드시 구현해야 한다고 강제하는 것
//인터페이스 = 규칙
//여기서 말하는 규칙은 특정 메소드를 구현해야 한다는 규칙
//보통 이름끝에 able이 붙는다.
//C#에선 앞에 대문자 I가 붙는다.

//동물 계통인 것의 기본 기술
public interface Animalable {
	void bodyattack(); //몸통박치기
	void QuickAttack(); //전광석화
	void run(); //달리기
	void jump(); //점프
}






