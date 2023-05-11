class Box<T extends Number> {
    private T ob;

    public void set(T o) {
        ob = o;
    }
    public T get() {
        return ob;
    }
}

class BoundedBox {
    public static void main(String[] args) {
        Box<Integer> iBox = new Box<>();
        iBox.set(24);

        Box<Double> dBox = new Box<>();
        dBox.set(5.97);

        System.out.println(iBox.get());
        System.out.println(dBox.get());
    }
}