class PartialByTimes {
    public static void main(String[] args) {
        for(int i = 2; i < 10; i += 2) {
            for(int j = 1; j < 10; j++) {
                System.out.println(i + " x " + j + " = " + (i * j));
                
                if(j >= i)
                    break;
            }
        }
    }
}
