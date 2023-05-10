interface Getable<T> {
    public T get();
}

class Box<T> implements Getable<String> {
    private T ob;     
    public void set(T o) { ob = o; }

    @Override
    public String get() { 
        return ob.toString(); 
    }
}

class Toy {
    @Override 
    public String toString() { 
        return "I am a Toy";
    }
}

class GetableGenericInterface2 {
    public static void main(String[] args) {
        Box<Toy> box = new Box<>();
        box.set(new Toy());
    
        Getable<String> gt = box;
        System.out.println(gt.get());        
    }
}