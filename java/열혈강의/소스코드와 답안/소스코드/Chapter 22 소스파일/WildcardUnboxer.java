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
    public static <T> T openBox(Box<T> box) {
        return box.get();
    }
    
    public static <T> void peekBox(Box<T> box) {
        System.out.println(box);
    }
}

class WildcardUnboxer {
    public static void main(String[] args) {
        Box<String> box = new Box<>();
        box.set("So Simple String");
        Unboxer.peekBox(box);
    }
}