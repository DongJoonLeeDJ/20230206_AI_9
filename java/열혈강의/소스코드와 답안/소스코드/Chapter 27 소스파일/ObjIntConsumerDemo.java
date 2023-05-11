import java.util.function.ObjIntConsumer;

class ObjIntConsumerDemo {
    public static void main(String[] args) {
        ObjIntConsumer<String> c = (s, i) -> System.out.println(i + ". " + s);

        int n = 1;
        c.accept("Toy", n++);
        c.accept("Book", n++);
        c.accept("Candy", n);
    }
}