import java.util.List;
import java.util.Arrays;
import java.util.stream.Stream;

class StreamOfStream {
    public static void main(String[] args) {
        // ex 1
        Stream.of(11, 22, 33, 44)
            .forEach(n -> System.out.print(n + "\t"));
        System.out.println();

        // ex 2
        Stream.of("So Simple")
            .forEach(s -> System.out.print(s + "\t"));
        System.out.println();

        // ex 3
        List<String> sl = Arrays.asList("Toy", "Robot", "Box");
        Stream.of(sl)
            .forEach(w -> System.out.print(w + "\t"));
        System.out.println();       
    }
}