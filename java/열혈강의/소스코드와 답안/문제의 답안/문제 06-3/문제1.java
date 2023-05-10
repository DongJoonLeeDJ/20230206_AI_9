class ReculsivePowerOfTwo {
    public static void main(String[] args) {
        System.out.println("2ÀÇ 5½Â : " + powerOfTwo(5));
        System.out.println("2ÀÇ 7½Â : " + powerOfTwo(7));
    }
    
    public static int powerOfTwo(int n) {
        if(n == 0)
            return 1;
        
        return 2 * powerOfTwo(n - 1);
    }
}
