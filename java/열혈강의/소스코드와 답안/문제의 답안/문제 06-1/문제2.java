class ABS {
    public static void main(String[] args) {
        abs(7, 3);
        abs(-5, -3);
        abs(4, -3);
    }
    
    public static void abs(int n1, int n2) {
        if(n1 > n2)
            System.out.println(n1 - n2);
        else
            System.out.println(n2 - n1);
    }
}
