class SumTo100 {
    public static void main(String[] args) {
        int num = 1;
        int sum = 0;
    
        while(num<100) {
            sum += num;
            num++;
        }
        
        System.out.println(sum);
    }
}
