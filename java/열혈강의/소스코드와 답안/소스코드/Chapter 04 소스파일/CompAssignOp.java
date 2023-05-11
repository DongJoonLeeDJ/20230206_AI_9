class CompAssignOp {
    public static void main(String[] args) {
        short num = 10;
        
        num = (short) (num + 77L);

        int rate = 3;
        rate = (int) (rate * 3.5);

        System.out.println(num);
        System.out.println(rate);

        num = 10;
        num += 77L;

        rate = 3;
        rate *= 3.5;

        System.out.println(num);
        System.out.println(rate);
    }
}