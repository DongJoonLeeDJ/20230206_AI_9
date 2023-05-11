class DBox<L, R> {
    private L left;     // ¿ÞÂÊ ¼ö³³ °ø°£
    private R right;    // ¿À¸¥ÂÊ ¼ö³³ °ø°£

    public void set(L o, R r) {
        left = o;
        right = r;
    } 
    
    @Override
    public String toString() {
        return left + " & " +right;
    }
}

class DDBoxDemo {
    public static void main(String[] args) {
        DBox<String, Integer> box1 = new DBox<>();
        box1.set("Apple", 25);

        DBox<String, Integer> box2 = new DBox<>();
        box2.set("Orange", 33);
        
        DBox<DBox<String, Integer>, DBox<String, Integer>> ddbox = new DBox<>();
        ddbox.set(box1, box2);

        System.out.println(ddbox);
    }
}