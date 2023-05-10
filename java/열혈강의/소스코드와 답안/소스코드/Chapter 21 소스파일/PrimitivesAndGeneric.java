class Box<T> {
    private T ob;

    public void set(T o) {
        ob = o;
    }
    public T get() {
        return ob;
    }
}

class PrimitivesAndGeneric {
    public static void main(String[] args) {
        Box<Integer> iBox = new Box<Integer>();
    
        iBox.set(125);
        int num = iBox.get();

        System.out.println(num);
    }
}