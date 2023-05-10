class SCE {
    public static void main(String[] args) {
        int num1 = 0; 
        int num2 = 0;
        boolean result;

        num1 += 10;
        num2 += 10;        
        result = (num1 < 0) && (num2 > 0);

        System.out.println("result = " + result);
        System.out.println("num1 = " + num1);
        System.out.println("num2 = " + num2 + '\n');
		
        num1 += 10;
        num2 += 10;        
        result = (num1 > 0) || (num2 > 0);

        System.out.println("result = " + result);
        System.out.println("num1 = " + num1);
        System.out.println("num2 = " + num2);
    }
}