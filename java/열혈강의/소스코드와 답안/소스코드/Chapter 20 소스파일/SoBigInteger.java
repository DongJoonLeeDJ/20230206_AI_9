import java.math.BigInteger;

class SoBigInteger {
    public static void main(String[] args) {
        System.out.println("ÃÖ´ë Á¤¼ö: " + Long.MAX_VALUE);
        System.out.println("ÃÖ¼Ò Á¤¼ö: " + Long.MIN_VALUE);
        System.out.println();
        
        BigInteger big1 = new BigInteger("100000000000000000000");
        BigInteger big2 = new BigInteger("-99999999999999999999");
		
        BigInteger r1 = big1.add(big2);
        System.out.println("µ¡¼À °á°ú: " + r1);

        BigInteger r2 = big1.multiply(big2);
        System.out.println("°ö¼À °á°ú: " + r2);
        System.out.println();

        int num = r1.intValueExact();
        System.out.println("From BigInteger: " + num);
    }
}