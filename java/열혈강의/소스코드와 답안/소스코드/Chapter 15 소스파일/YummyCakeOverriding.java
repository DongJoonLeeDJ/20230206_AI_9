class Cake {
    public void yummy() { 
        System.out.println("Yummy Cake");
    }
}
   
class CheeseCake extends Cake { 
    // Cake의 yummy 메소드를 오버라이딩 함
    public void yummy() { 
        System.out.println("Yummy Cheese Cake");
    }
}

class YummyCakeOverriding {
    public static void main(String[] args) {
        Cake c1 = new CheeseCake();
        CheeseCake c2 = new CheeseCake();
        
        c1.yummy();
        c2.yummy();
    }
}