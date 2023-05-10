import java.util.function.Function;

class FunctionDemo {
    public static void main(String[] args) {
        Function<String, Integer> f = s -> s.length();

        System.out.println(f.apply("Robot"));
        System.out.println(f.apply("System"));
    }
}