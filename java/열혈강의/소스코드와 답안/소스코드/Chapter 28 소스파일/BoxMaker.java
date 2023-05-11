class Box<T,U> {
    T id;
    U con;

    public Box(T i, U c) {
        id = i;
        con = c;
    }

    public void showIt() {
        System.out.println("ID: " + id);
        System.out.println("Contents: " + con + '\n');
    }
}

interface BoxWrapper<T, U> {
    Box<T, U> wrap(T i, U c);
}

class BoxMaker {
    public static <T, U> Box<T,U> wrapIt(T i, U c, BoxWrapper<T, U> w) {
        return w.wrap(i, c);
    }

    public static void main(String[] args) {
        BoxWrapper<Integer, String> bw = 
                        (i, c) -> { return new Box<>(i, c); };

        Box<Integer, String> b1 = wrapIt(1, "Toy", bw);
        Box<Integer, String> b2 = wrapIt(2, "Robot", bw);
        
        b1.showIt();
        b2.showIt();
    }
}