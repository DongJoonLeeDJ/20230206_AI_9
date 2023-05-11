class Box<T> {
    private T ob;     
    public void set(T o) { ob = o; }
    public T get() { return ob; }

    @Override
    public String toString() {
        return ob.toString();
    }
}

class Unboxer {
    public static void peekBox(Box<? extends Number> box) {
        System.out.println(box);
    }
}

class UpperBoundedWildcard {
    public static void main(String[] args) {
        Box<Integer> iBox = new Box<>();
        iBox.set(1234);

        Box<Double> dBox = new Box<>();
        dBox.set(10.009);

        Unboxer.peekBox(iBox);
        Unboxer.peekBox(dBox);
    }
}