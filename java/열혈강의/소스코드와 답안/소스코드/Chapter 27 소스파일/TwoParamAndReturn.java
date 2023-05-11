interface Calculate {
    int cal(int a, int b);
}

class TwoParamAndReturn {
    public static void main(String[] args) {
        Calculate c;
        c = (a, b) -> { return a + b; };
        System.out.println(c.cal(4, 3));
        
        c = (a, b) -> a + b;
        System.out.println(c.cal(4, 3));
    }
}