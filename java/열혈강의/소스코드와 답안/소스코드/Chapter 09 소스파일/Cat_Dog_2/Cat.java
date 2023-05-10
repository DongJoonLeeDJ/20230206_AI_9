package zoo;

public class Cat { 
    // public으로 선언된 메소드, 따라서 어디서든 호출 가능
    public void makeSound() { System.out.println("야용"); }
    
    // default로 선언된 메소드, 따라서 동일 패키지로 묶인 클래스 내에서 호출 가능
    void makeHappy() { System.out.println("스마일"); }
}
