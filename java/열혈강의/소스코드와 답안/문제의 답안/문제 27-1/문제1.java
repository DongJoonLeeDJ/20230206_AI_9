interface Calculate<T> {
    T cal(T a, T b);
}

class CalculatorDemo {
    public static void calAndShow(Calculate<T> op, T n1, T n2) {
        T r = op.cal(n1, n2);
        System.out.println(r);
    }

    public static void main(String[] args) {
        // 3 + 4
        calAndShow((a, b) -> a + b, 3, 4);

        // 2.5 + 7.1
        calAndShow((a, b) -> a + b, 2.5, 7.1);

        // 4 - 2
        calAndShow((a, b) -> a - b, 4, 2);
    
        // 4.9 - 3.2
        calAndShow((a, b) -> a - b, 4.9, 3.2);
    }
}