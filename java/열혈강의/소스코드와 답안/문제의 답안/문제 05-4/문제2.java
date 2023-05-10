class PrintRev {
    public static void main(String[] args) {
        int num = 1;
         
        while(num <= 100)
            System.out.println(num++);
        
        do {
            System.out.println(--num);
        } while(num>1);
    }
}
