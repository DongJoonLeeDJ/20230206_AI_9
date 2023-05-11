class Box<T> {
    private T ob;     
    public void set(T o) { ob = o; }
    public T get() { return ob; }
}

class Toy {
    @Override 
    public String toString() { 
        return "I am a Toy";
    }
}

class Robot {
    @Override 
    public String toString() { 
        return "I am a Robot";
    }
}

class BoxHandler {
    public static <T> void outBox(Box<? extends T> box) {
        T t = box.get();
        System.out.println(t);
    }

    public static <T> void inBox(Box<? super T> box, T n) {
        box.set(n); 
    } 
}

class BoundedWildcardGenericMethod {
    public static void main(String[] args) {
        Box<Toy> tBox = new Box<>();
        BoxHandler.inBox(tBox, new Toy());
        BoxHandler.outBox(tBox); 

        Box<Robot> rBox = new Box<>();
        BoxHandler.inBox(rBox, new Robot());
        BoxHandler.outBox(rBox);
    }
}