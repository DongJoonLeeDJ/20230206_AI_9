class UnaryAddMin {
    public static void main(String[] args) {
        short num1 = 5;
        System.out.println(+num1);
        System.out.println(-num1);
		
        short num2 = 7;
        short num3 = (short)(+num2);
        short num4 = (short)(-num2);
        System.out.println(num3);
        System.out.println(num4);	
    }
}