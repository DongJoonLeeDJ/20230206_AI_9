class Box<T> {
    protected T ob;
    
    public void set(T o) { ob = o; }
    public T get() { return ob; }
}

class SteelBox<T> extends Box<T> {
    public SteelBox(T o) {
        ob = o;
    }
}



class GenericInheritance {
    public static void main(String[] args) {
        Box<Integer> iBox = new SteelBox<>(7959);
        Box<String> sBox = new SteelBox<>("Simple");

        System.out.println(iBox.get());
        System.out.println(sBox.get());
    }
}