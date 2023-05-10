class WrapperClassMethod {
    public static void main(String[] args) {
        Integer n1 = Integer.valueOf(5);
        Integer n2 = Integer.valueOf("1024");
        
        System.out.println("큰 수: " + Integer.max(n1, n2));
        System.out.println("작은 수: " + Integer.min(n1, n2));
        System.out.println("합: " + Integer.sum(n1, n2));
        System.out.println();
        
        System.out.println("12의 2진 표현: " + Integer.toBinaryString(12));
        System.out.println("12의 8진 표현: " + Integer.toOctalString(12));
        System.out.println("12의 16진 표현: " + Integer.toHexString(12));
    }
}
