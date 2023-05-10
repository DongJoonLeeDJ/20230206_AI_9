class Cake {
    public String toString() {
        System.out.println(super.toString());
        return "My birthday cake";
    }
}
   
class CheeseCake extends Cake { 
    public String toString() {
        return "My birthday cheese cake";
    }    
}

class OverridingToString {
    public static void main(String[] args) {
        Cake c1 = new Cake();
        Cake c2 = new CheeseCake();

        System.out.println(c1);
        System.out.println();

        System.out.println(c2);
    }
}