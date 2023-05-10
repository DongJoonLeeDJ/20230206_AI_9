import java.util.stream.IntStream;
import java.util.stream.DoubleStream;

class PrimitiveSortedStream {
    public static void main(String[] args) {
        IntStream.of(3, 9, 4, 2)
            .sorted()
            .forEach(d -> System.out.print(d + "\t"));
        System.out.println();

        DoubleStream.of(3.3, 6.2, 1.5, 8.3)
            .sorted()
            .forEach(d -> System.out.print(d + "\t"));
        System.out.println();
    }
}