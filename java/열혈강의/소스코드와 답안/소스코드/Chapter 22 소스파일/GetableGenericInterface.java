interface Getable<T> {
    public T get();
}

class Box<T> implements Getable<T> {
    private T ob;     
    public void set(T o) { ob = o; }

    @Override
    public T get() { 
        return ob; 
    }
}

class Toy {
    @Override 
    public String toString() { 
        return "I am a Toy";
    }
}

class GetableGenericInterface {
    public static void main(String[] args) {
        Box<Toy> box = new Box<>();
        box.set(new Toy());
    
        Getable<Toy> gt = box;
        System.out.println(gt.get());        
    }
}