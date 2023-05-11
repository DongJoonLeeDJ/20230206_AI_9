class ExceptionMessage2 { 
    public static void md1(int n) {
        md2(n, 0);
    }
    public static void md2(int n1, int n2) {
        int r = n1 / n2;
    }
    public static void main(String[] args) {
        try {
            md1(3);
        }
        catch(Throwable e) {
            e.printStackTrace();
        }
        
        System.out.println("Good bye~~!");
    }
}