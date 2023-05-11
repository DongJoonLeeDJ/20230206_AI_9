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
    public static void peekBox(Box<? super Integer> box) {
        System.out.println(box);
    }
}

class LowerBoundedWildcard {
    public static void main(String[] args) {
        Box<Integer> iBox = new Box<Integer>();
        iBox.set(5577);
        
        Box<Number> nBox = new Box<Number>();
        nBox.set(new Integer(9955));

        Box<Object> oBox = new Box<Object>();
        oBox.set("My Simple Instance");

        Unboxer.peekBox(iBox);
        Unboxer.peekBox(nBox);
        Unboxer.peekBox(oBox);
    }
}