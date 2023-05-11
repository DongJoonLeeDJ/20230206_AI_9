class PostfixOp {
    public static void main(String[] args) {
        int num = 5;

        System.out.print((num++) + " ");
        System.out.print((num++) + " ");
        System.out.print(num + "\n");

        System.out.print((num--) + " ");
        System.out.print((num--) + " ");
        System.out.print(num);
    }
}