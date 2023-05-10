class FormatString {
    public static void main(String[] args) {
        int age = 20;
        double height = 178.2;
        String name = "YOON SUNG WOO";
        
        System.out.printf(" name: %s \n", name);
        System.out.printf(" age: %d \n height: %e \n\n", age, height);
        
        System.out.printf(" %d - %o - %x \n\n", 77, 77, 77);
        System.out.printf(" %g \n", 0.00014);
        System.out.printf(" %g \n", 0.000014);
    }
}