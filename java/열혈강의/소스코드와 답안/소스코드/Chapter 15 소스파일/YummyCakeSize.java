class Cake {
    public int size;     // cake size
    
    public Cake(int sz) {
        size = sz;
    }

    public void showCakeSize() {
        System.out.println("Bread Ounces: " + size);
    }
}
   
class CheeseCake extends Cake { 
    public int size;     // cheese size
    
    public CheeseCake(int sz1, int sz2) {
        super(sz1);
        size = sz2;
    }

    public void showCakeSize() {
        System.out.println("Bread Ounces: " + super.size);
        System.out.println("Cheese Ounces: " + size); 
    }
}

class YummyCakeSize {
    public static void main(String[] args) {
        CheeseCake ca1 = new CheeseCake(5, 7);
        Cake ca2 = ca1;
    
        System.out.println("Bread Ounces: " + ca2.size);
        System.out.println("Cheese Ounces: " + ca1.size);
        System.out.println();

        ca1.showCakeSize();
        System.out.println();

        ca2.showCakeSize();
    }
}