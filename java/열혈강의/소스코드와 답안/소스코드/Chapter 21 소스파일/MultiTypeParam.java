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

class MultiTypeParam {
    public static void main(String[] args) {
        DBox<String, Integer> box = new DBox<String, Integer>();
        box.set("Apple", 25);
        System.out.println(box);
    }
}